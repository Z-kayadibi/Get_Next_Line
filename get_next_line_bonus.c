/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkayadib <zkayadib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:36:53 by zkayadib          #+#    #+#             */
/*   Updated: 2024/12/25 18:14:23 by zkayadib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*findnewline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (str + i);
		i++;
	}
	return (NULL);
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

char	*after_new_line(char *s)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	ret = ft_calloc(sizeof(char), ft_strlen(s) - i + 1);
	if (!ret)
		return (NULL);
	j = 0;
	while (s[i])
	{
		ret[j++] = s[i++];
	}
	free(s);
	return (ret);
}

char	*read_func(int *rd, int fd, char *after)
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
	static char	*after[8192];

	rd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (rd > 0 && !findnewline(after[fd]))
	{
		after[fd] = read_func(&rd, fd, after[fd]);
		if (!after[fd])
			return (NULL);
	}
	result = beforenewline(after[fd]);
	after[fd] = after_new_line(after[fd]);
	if (after[fd] && after[fd][0] == 0)
	{
		free(after[fd]);
		after[fd] = NULL;
	}
	return (result);
}
