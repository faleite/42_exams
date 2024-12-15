#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int sockfd = -1;
int max_fd;
int ids[5000];
char *arr_str[5000];
char *fatal = "Fatal error";
char *message = NULL;
char send_buf[1000];
char recv_buf[1000];
fd_set actual_set, write_set, read_set;

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

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

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

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

void err(char *str)
{
	write(2, str, strlen(str));
	write(2, "\n", 1);
	if (sockfd >= 0)
		close(sockfd);
	exit(1);
}

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

int main(int argc, char *argv[]) 
{
	int id, connfd, len;
	struct sockaddr_in servaddr; 

	if (argc != 2)
		err("Wrong number of arguments");

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
		err(fatal);

	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		err(fatal);

	if (listen(sockfd, 10) != 0)
		err(fatal);
	
	max_fd = sockfd;
	FD_ZERO(&actual_set);
	FD_SET(sockfd, &actual_set);
	id = 0;

	while (1)
	{
		// variavies set
		read_set = write_set = actual_set;
		if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) <= 0)
			continue ;

		if (FD_ISSET(sockfd, &read_set))
		{
			connfd = accept(sockfd, NULL, NULL); /////// sockfd
			if (connfd <= 0)
				err(fatal);
			
			// variaveis
			arr_str[connfd] = NULL;
			ids[connfd] = id++;
			FD_SET(connfd, &actual_set);

			if (connfd > max_fd)
				max_fd = connfd;

			sprintf(send_buf, "server: client %d just arrived\n", ids[connfd]);
			send_msg(connfd);
			continue;
		}

		// loop for
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
					break ;
				}
				else
				{
					recv_buf[len] = '\0';
					arr_str[fd] = str_join(arr_str[fd], recv_buf);
					message = NULL;

					// loop
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
	return (0);
}