/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkayadib <zkayadib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:30:33 by zkayadib          #+#    #+#             */
/*   Updated: 2024/12/23 21:55:12 by zkayadib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
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
	int		has_nl;

	has_nl = 0;
	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		has_nl = 1;
		i++;
	}
	line = ft_calloc(sizeof(char), i + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (str && str[++i] && str[i] != '\n')
		line[i] = str[i];
	if (has_nl)
		line[i] = '\n';
	return (line);
}

char	*deneme(int *rd, int fd, char *after)
{
	char	*buffer;

	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	*rd = read(fd, buffer, BUFFER_SIZE);
	if (*rd == -1)
	{
		free(after);
		free(buffer);
		return (NULL);
	}
	after = ft_strjoin(after, buffer);
	return (free(buffer), after);
}

char	*get_next_line(int fd)
{
	char		*result;
	int			rd;
	static char	*after;

	rd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (rd > 0 && !findnewline(after))
	{
		after = deneme(&rd, fd, after);
		if (!after)
			return (NULL);
	}
	result = beforenewline(after);
	after = after_new_line(after);
	if (after && after[0] == 0)
	{
		free(after);
		after = NULL;
	}
	return (result);
}
