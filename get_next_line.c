#include "get_next_line.h"
#include <stdio.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;
	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	i;

	i = 0;
	memory = malloc(count * size);
	if (memory == NULL)
		return (0);
	while (i < count * size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}

char	*beforenewline(char *str)
{
	int		i;
	char	*line;
	i = 0;
	if(str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 1);
	ft_strlcpy(line, str, ((&str[i + 1] - &str[0]) + 1));
	return (line);
}
char	*deneme(int *rd, int fd, char *after)
{
	char	*buffer;
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1); 
	*rd = read(fd, buffer, BUFFER_SIZE);
	if (*rd == -1 )
	{
		free(after);
		free(buffer);
		return (NULL);
	}
	after = ft_strjoin(after, buffer);
	if(!after)
		return(free(after), free(buffer), NULL);
	free(buffer);
	return (after);
}
char	*get_next_line(int fd)
{
	char		*result;
	int			rd;
	static char	*after;

	if(fd < 0 || BUFFER_SIZE <= 0)
 		return(NULL);

	rd = 1;
	while (rd > 0 && !findnewline(after))
	{
		after = deneme(&rd, fd, after);
		if (!after)
			return NULL;
	}
	result = beforenewline(after);
	after = after_new_line(after);
	if (after[0] == 0)
		free(after);
	return (result);
}