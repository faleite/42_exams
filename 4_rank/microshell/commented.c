#include <unistd.h>
#include <sys/types.h>
#include <string.h>

// Função para escrever uma mensagem de erro no erro padrão (descritor de arquivo 2)
int err(char *str) 
{
    while (*str)
        write(2, str++, 1); // Escrevendo cada caractere da string em stderr
    return 1;
}

// Função para alterar o diretório atual
int cd(char **argv, int i) 
{
    if (i != 2)
        return err("error: cd: bad arguments\n"); // Retorna um erro se a contagem de argumentos não for 2
    else if (chdir(argv[1]) == -1)
        return err("error: cd: cannot change directory to "), err(argv[1]), err("\n"); // Retornar um erro se a alteração do diretório falhar
    return 0; // Retorne 0 em caso de sucesso
}

// Função para executar um comando
int exec(char **argv, char **envp, int i) 
{
    int fd[2];
    int status;
    int has_pipe = argv[i] && !strcmp(argv[i], "|"); // Verifique se um pipe está presente no comando

    if (has_pipe && pipe(fd) == -1)
        return err("error: fatal\n"); // Retornar um erro se a criação do pipe falhar

    int pid = fork(); // Crie um processo filho
    if (!pid) 
    {
        argv[i] = 0; // Defina o elemento após a barra vertical ou ponto e vírgula como nulo
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return err("error: fatal\n"); // Retornar um erro se o redirecionamento ou fechamento do pipe falhar
        execve(*argv, argv, envp); // Execute o comando
        return err("error: cannot execute "), err(*argv), err("\n"); // Retornar um erro se a execução falhar
    }

    waitpid(pid, &status, 0); //Aguarde o processo filho terminar
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return err("error: fatal\n"); // Retornar um erro se o redirecionamento ou fechamento do pipe falhar
    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp) 
{
    int    i = 0;
    int    status = 0;

    if (argc > 1) 
    {
        while (argv[i] && argv[++i]) 
        {
            argv += i; //Mova o ponteiro argv para frente i
            i = 0; // Redefinir i para 0
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++; // Encontre a próxima barra vertical ou ponto e vírgula ou final de argumentos
            if (!strcmp(*argv, "cd"))
                status = cd(argv, i); // Execute o comando cd
            else if (i)
                status = exec(argv, envp, i); // Execute outros comandos
        }
    }
    return status; // Retornar o status do último comando executado
}
