#include <string.h>
#include <stdlib.h>
 
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;
	size_t	j;

	dst_len = strlen(dst);
	if (dst_len >= size)
		return (size + strlen(src));
	i = dst_len;
	j = 0;
	while (i < size && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*word;
	int		len;

	len = strlen(s1) + strlen(s2);
	word = malloc(sizeof(char) * (len + 1));
	if (word)
	{
		ft_strlcpy(word, s1, strlen(s1) + 1);
		ft_strlcat(word, s2, len + 1);
		return (word);
	}
	return (NULL);
}