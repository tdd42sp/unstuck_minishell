#include "minunit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  

int     fd;
char    *file = "./files/test_fd";
int     bkp;
char    text[1000];

int setup_fd()
{   
    fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (!fd)
        return (0);
    bkp = dup(1);
    dup2(fd, 1);
    return (bkp);
}

char *unset_fd()
{
    close(fd);
    fd = open(file, O_RDONLY);
    read(fd, text, 1000);
    dup2(bkp, 1);
    remove(file);
    return (text);
}

MU_TEST_SUITE(echo_inserting_lula_should_print_lula)
{
    setup_fd();

    char *input = "lula";
        
    unset_fd();
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(echo_inserting_lula_should_print_lula);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}