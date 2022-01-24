#include "get_next_line.h"
#include <string.h>

char	*ft_strdup(const char *string)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (strlen(string) + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (string[++i])
		dup[i] = string[i];
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	*read_str = NULL;
	char		line_buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char 		*temp;
	char		*line;
	char		*end_ptr;

	line = NULL;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_str == NULL)
		read_str = ft_strndup("", 0);
	while (!(ft_strchr(read_str, '\n')))
	{
		bytes_read = read(fd, line_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_str);
			read_str = NULL;
			return (line);
		}
		line_buffer[bytes_read] = '\0';
		temp = ft_strjoin(read_str, line_buffer);
		free(read_str);
		read_str = temp;
		if (bytes_read == 0)
			break;
	}
	if (ft_strlen(read_str) == 0)
	{
		free(read_str);
		read_str = NULL;
		return (line);
	}
	end_ptr = ft_strchr(read_str, '\n');
	if (!end_ptr)
		end_ptr = ft_strchr(read_str, '\0');
	line = ft_strndup(read_str, end_ptr - read_str + !!ft_strchr(read_str, '\n'));
	if (ft_strchr(read_str, '\n'))
	{
		temp = ft_strdup(end_ptr + 1);
		// temp = ft_strndup(end_ptr + 1, ft_strlen(read_str));
		// temp = ft_substr(read_str, end_ptr - read_str + 1, ft_strlen(read_str));
		free(read_str);
		read_str = temp;
	}
	else
	{
		free(read_str);
		read_str = NULL;
	}
	return (line);
}
