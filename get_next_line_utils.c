#include "get_next_line.h"

int		ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *string, size_t n)
{
	char 	*ret;
	size_t	i;

	ret = malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (ret);
	i = -1;
	while (++i < n)
		ret[i] = string[i];
	ret[i] = '\0';
	return (ret);
}

char	*ft_substr(const char *string, unsigned int start, size_t n)
{
	size_t		i;
	char 	*ret;

	ret = malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (ret);
	i = -1;
	while (++i < n)
		ret[i] = string[start + i];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = -1;
	while (string[++i])
	{
		if (string[i] == (char)c)
			return ((char *)string + i);
	}
	if ((char)c == '\0')
		return ((char *)string + i);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (ret);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	j = -1;
	while (s2[++j])
		ret[i + j] = s2[j];
	ret[i + j] = '\0';
	return (ret);
}
