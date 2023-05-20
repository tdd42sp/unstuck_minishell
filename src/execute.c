#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void exec_commands(char **pathname)
{
    int pid;
    int exitCode;
    extern char **environ;

    pid = fork();
    if (pid == 0)
    {
        execve(*pathname, pathname, environ);
    } else {
        waitpid(pid, &exitCode, 0);
    }
}