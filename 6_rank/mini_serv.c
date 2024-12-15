// main.c
// #include <errno.h>
#include <string.h>      // For strlen, strcpy, strcat, bzero
#include <unistd.h>      // For write, close
// #include <netdb.h>
#include <sys/socket.h>  // For socket, bind, listen, accept, send, recv
#include <netinet/in.h>  // For struct sockaddr_in, htonl, htons

// me
#include <stdio.h>       // For sprintf
#include <stdlib.h>      // For malloc, calloc, free, atoi, exit
#include <sys/select.h>  // For select, FD_SET, FD_CLR, FD_ISSET, FD_ZERO

int sockfd = -1;
int max_fd;
int ids[5000];
char *arr_str[5000];
char *fatal = "Fatal error";
char *message = NULL;
char send_buf[1000];
char recv_buf[1000];

/**
 O tipo fd_set é uma estrutura usada para representar conjuntos de descritores de arquivos 
 (file descriptors) em operações de E/S (entrada/saída) multiplexadas, como a função select.
 
 actual_set: Armazena o conjunto atual de descritores de arquivos que o servidor está monitorando.
 write_set: Armazena o conjunto de descritores de arquivos prontos para escrita.
 read_set: Armazena o conjunto de descritores de arquivos prontos para leitura.

 Essas variáveis são usadas em conjunto com a função select para monitorar múltiplos
 descritores de arquivos e determinar quais estão prontos para operações de leitura ou escrita,
 permitindo que o servidor lide com múltiplas conexões de clientes de forma eficiente.

 typedef struct {
    unsigned long fds_bits[__FD_SETSIZE / (8 * sizeof(unsigned long))];
 } fd_set;

 As macros e funções associadas a fd_set são usadas para manipular esses conjuntos 
 de descritores de arquivos:

 FD_ZERO(fd_set *set): Inicializa o conjunto apontado por set para que ele não contenha nenhum descritor de arquivo.
 FD_SET(int fd, fd_set *set): Adiciona o descritor de arquivo fd ao conjunto set.
 FD_CLR(int fd, fd_set *set): Remove o descritor de arquivo fd do conjunto set.
 FD_ISSET(int fd, fd_set *set): Verifica se o descritor de arquivo fd está no conjunto set.
 
 Essas macros são usadas para preparar e verificar os conjuntos de descritores de arquivos 
 antes e depois de chamar a função select.
*/
fd_set actual_set, write_set, read_set;

// main.c
int extract_message(char **buf, char **msg)
{
    char *newbuf;
    int i;

    *msg = 0;
    if (*buf == 0)
        return (0);
    i = 0;
    while ((*buf)[i])
    {
        if ((*buf)[i] == '\n')
        {
            newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
            if (newbuf == 0)
                return (-1);
            strcpy(newbuf, *buf + i + 1);
            *msg = *buf;
            (*msg)[i + 1] = 0;
            *buf = newbuf;
            return (1);
        }
        i++;
    }
    return (0);
}

// main.c
char *str_join(char *buf, char *add)
{
    char *newbuf;
    int len;

    if (buf == 0)
        len = 0;
    else
        len = strlen(buf);
    newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
    if (newbuf == 0)
        return (0);
    newbuf[0] = 0;
    if (buf != 0)
        strcat(newbuf, buf);
    free(buf);
    strcat(newbuf, add);
    return (newbuf);
}

// me
void err(char *s)
{
    write(2, s, strlen(s));
    write(2, "\n", 1);
    if (sockfd >= 0)
        close(sockfd);
    exit(1);
}

// me
void send_msg(int fd)
{
    for (int i = 0; i <= max_fd; ++i)
    {
        if (FD_ISSET(i, &write_set) && i != fd && i != sockfd)
        {
            send(i, send_buf, strlen(send_buf), 0);
            if (message)
                send(i, message, strlen(message), 0);
        }
    }
}

int main(int argc, char **argv)
{
    int connfd, id, len;
    struct sockaddr_in servaddr;

    if (argc != 2)
        err("Wrong number of arguments");
    
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // main.c
    if (sockfd == -1) // main.c
        err(fatal); 

    // Preencher com zeros uma área de memória. Neste caso, está zerando a estrutura servaddr do tipo struct sockaddr_in.
    bzero(&servaddr, sizeof(servaddr)); // main.c

    // assign IP, PORT 
    servaddr.sin_family = AF_INET; // main.c
    servaddr.sin_addr.s_addr = htonl(2130706433); // main.c
    servaddr.sin_port = htons(atoi(argv[1])); // main.c (me -> atoi(argv[1]))

    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) // main.c
        err(fatal);

    // Coloca o socket em modo de escuta para aceitar conexões de entrada, com uma fila de até 10 conexões pendentes 
    if (listen(sockfd, 10) != 0) // main.c
        err(fatal);

    max_fd = sockfd;
    FD_ZERO(&actual_set); // Inicializa o conjunto apontado por actual_set para que ele não contenha nenhum descritor de arquivo.
    FD_SET(sockfd, &actual_set); // Adiciona o descritor de arquivo sockfd ao conjunto actual_set.
    id = 0;

    while (1)
    {
        read_set = write_set = actual_set;
        if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) <= 0)
            continue;

        // Verifica se o descritor de arquivo sockfd está no conjunto read_set.
        if (FD_ISSET(sockfd, &read_set))
        {
            // Aceita uma conexão de entrada no socket de escuta e retorna um novo descritor de arquivo para a conexão com o cliente
            connfd = accept(sockfd, NULL, NULL);
            if (connfd <= 0)
                err(fatal);

            arr_str[connfd] = NULL;
            ids[connfd] = id++;
            FD_SET(connfd, &actual_set);

            if (connfd > max_fd)
                max_fd = connfd;

            sprintf(send_buf, "server: client %d just arrived\n", ids[connfd]);
            send_msg(connfd);
            continue;
        }

        for (int fd = 0; fd <= max_fd; ++fd)
        {
            if (FD_ISSET(fd, &read_set) && fd != sockfd)
            {
                len = recv(fd, recv_buf, sizeof(recv_buf), 0);

                if (len <= 0)
                {
                    FD_CLR(fd, &actual_set);
                    sprintf(send_buf, "server: client %d just left\n", ids[fd]);
                    send_msg(fd);
                    close(fd);

                    if (arr_str[fd])
                        free(arr_str[fd]);
                    break;
                }
                else
                {
                    recv_buf[len] = '\0';
                    arr_str[fd] = str_join(arr_str[fd], recv_buf);
                    message = NULL;

                    while (extract_message(&arr_str[fd], &message))
                    {
                        sprintf(send_buf, "client %d: ", ids[fd]);
                        send_msg(fd);
                        free(message);
                        message = NULL;
                    }
                }
            }
        }
    }
    return 0;
}