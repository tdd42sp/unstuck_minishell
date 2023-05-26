#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);

char * get_command_path(char * command, char ** paths)
{
    int loop = 0;
    char * pathbin;

    while(paths[loop])
    {
        pathbin = ft_strjoin(paths[loop], "/");
        if(access(ft_strjoin(pathbin, command), X_OK | F_OK) == 0) //0 funcionou e 1 falhou.
        {
            return (ft_strjoin(pathbin, command));
        }
        free(pathbin);
        loop++;
    }

}

void exec_commands(char **command, char **paths)
{
    int pid;
    int exitCode;
    char *commando_certo;
    extern char **environ; //importando a váriavel de um local externo, no caso env.

    commando_certo = get_command_path(*command, paths);

    pid = fork(); //Cria a duplicidade do processo.
    if (pid == 0) //Se processo for filho.
    {
        execve(commando_certo, command, environ);
        //Executando a linha acima o processo filho morre.
    } else { //Faz o processo pai.
        waitpid(pid, &exitCode, 0);
    }
}