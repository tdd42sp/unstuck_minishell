#include "minunit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char *path[] = {"/bin/", NULL};
int     fd;
char    *file = "./test_fd";
int     bkp;
char    text[1000];

void exec_commands(char **pathname, char **path);

int setup_fd()
{   
    fd = open(file, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (!fd)
        return (0);
    bkp = dup(1);
    dup2(fd, 1);
    close(fd);
    return (bkp);
}

char *get_fd_content()
{
    char *content = calloc(1000, sizeof(char));
    fflush(stdout);
    fd = open(file, O_RDONLY);
    read(fd, content, 1000);
    close(fd);
    return (content);
}

void    unset_fd()
{
    dup2(bkp, 1);
    remove(file);
}

MU_TEST(test_what_execute_function_do)
{
    //file arquivo deve estar no diretório raiz, caso não haverá erro.
    char *command[] = {"cat", "arquivo", NULL};
    char *expected = "oie";
    char *result;

    setup_fd();
    exec_commands(command, path);
    result = get_fd_content();
    unset_fd();

    mu_assert_string_eq(expected, result); 
}

MU_TEST(test_printfa)
{
    char *command[] = {"printf", "a", NULL};
    char *expected = "a";
    char *result;

    setup_fd();
    exec_commands(command, path);
    result = get_fd_content();
    unset_fd();

    mu_assert_string_eq(expected, result); 
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_what_execute_function_do);
    MU_RUN_TEST(test_printfa);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}