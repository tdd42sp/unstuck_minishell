#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

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

	input = "";
	while (ft_strncmp(input, "exit", 5) != 0)
	{
		input = readline("$ ");
		printf("%s\n",input);
	}
}