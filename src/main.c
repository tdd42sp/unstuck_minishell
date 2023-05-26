#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void    echo(char *input);
char	**ft_split(char const *s, char c);
void exec_commands(char **pathname);
char	*ft_strjoin(char const *s1, char const *s2)
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && n != 0 && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}


int main(void)
{
	char    *input;
	char	**returnExecv;
	char	**start;

	input = "";
	printf("Welcome to a work-in-progress minishell!\n");
	while (ft_strncmp(input, "exit", 5) != 0)
	{
		input = readline("$ ");//Lê a entrada do terminar e a armazena em input.
		//Gambs -> se comando for echo faz o echo, [será refatorado]
		if (ft_strncmp(input, "echo", 4) == 0) 
		{
			echo(&input[5]);
		} else {
			start = returnExecv = ft_split(input, ' ');
			exec_commands(returnExecv);
			while(*returnExecv)
				free(*returnExecv++);
			free(start);
		}
	}
}