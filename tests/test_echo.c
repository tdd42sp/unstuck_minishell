#include "minunit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int     fd;
char    *file = "./test_fd";
int     bkp;
char    text[1000];

void    echo(char *input);

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

MU_TEST_SUITE(echo_inserting_lula_should_print_lula)
{
    setup_fd();

    char *input = "lula";
    char *expected_result = "lula\n";
    char *actual_result;
    echo(input);

    actual_result = get_fd_content();
    unset_fd();

    mu_assert_string_eq(expected_result, actual_result);
    
    free(actual_result);
}

MU_TEST_SUITE(echo_inserting_42_should_print_42)
{
    setup_fd();

    char *input = "42";
    char *expected_result = "42\n";
    char *actual_result;
    echo(input);

    actual_result = get_fd_content();
    unset_fd();

    mu_assert_string_eq(expected_result, actual_result);
    
    free(actual_result);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(echo_inserting_lula_should_print_lula);
    MU_RUN_TEST(echo_inserting_42_should_print_42);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}