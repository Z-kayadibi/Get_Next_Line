
#include "get_next_line.h"
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && (i < dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
char	*after_new_line(char *s)
{
	int		i;
	int		j;
	char	*ret;
	i = 0;
	if (!s)
	{
		free(s);
		return (NULL);
	}
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	ret = ft_calloc(sizeof(char), ft_strlen(s) - i + 1);
	j = 0;
	while (s[i])
	{
		ret[j++] = s[i++];
	}
	ret[j] = '\0';
	free(s);
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*c;
	int		i;

	if (!s1)
	{
		s1 = ft_calloc(sizeof(char), 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
	{
		if(s2[0] == '\0')
		return (free(s1), free(s2), NULL);
	}
	i = ft_strlen(s1) + ft_strlen(s2);
	c = ft_calloc(sizeof(char), i + 1);
	if (!c)
		return (NULL);
	ft_strlcpy(c, s1, ft_strlen(s1) + 1);
	ft_strlcat(c, s2, i + 1);
	free(s1);
	return (c);
}
char	*findnewline(char *str)
{
	int i;
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