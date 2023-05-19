#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void    echo(char *input);
char	**ft_split(char const *s, char c);
void exec_commands(char **pathname);

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

	input = "";
	while (ft_strncmp(input, "exit", 5) != 0)
	{
		input = readline("$ ");
		if (ft_strncmp(input, "echo", 4) == 0)
		{
			echo(&input[5]);
		} else {
			returnExecv = ft_split(input, ' ');
			exec_commands(returnExecv);
			while(*returnExecv)
			{
				free(*returnExecv);
				returnExecv++;
			}
			//free(returnExecv);
		}
	}
}