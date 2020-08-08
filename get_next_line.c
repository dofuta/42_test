/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdofuku <tdofuku@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 13:49:59 by tdofuku           #+#    #+#             */
/*   Updated: 2020/08/08 22:39:03 by tdofuku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return ((char *)(s + i));
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

static int		make_line(char **holder, char **line)
{
	size_t		len;
	char		*tmp;

	len = 0;
	while ((*holder)[len] && (*holder)[len] != '\n')
		len++;
	if ((*holder)[len] == '\n')
	{
		(*holder)[len] = '\0';
		*line = ft_strdup(*holder);
		tmp = ft_strdup(&(*holder)[len + 1]);
		free(*holder);
		*holder = tmp;
	}
	else
	{
		*line = ft_strjoin(*holder, "");
		free(*holder);
		*holder = NULL;
		return (0);
	}
	return (1);
}

static int		read_file(int fd, char **holder)
{
	char		*tmp;
	char		*buf;
	ssize_t		filesize;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((filesize = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[filesize] = '\0';
		if (*holder == NULL)
			*holder = ft_strjoin(buf, "");
		else
		{
			tmp = ft_strjoin(*holder, buf);
			free(*holder);
			*holder = tmp;
		}
		if (ft_strchr(*holder, '\n'))
			break ;
	}
	free(buf);
	return (filesize);
}

int				get_next_line(int fd, char **line)
{
	static char		*holder;
	ssize_t			filesize;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);

	filesize = read_file(fd, &holder);
	if (filesize < 0)
		return (-1);
	else if (filesize == 0 && holder == NULL)
		return (((int)(*line = ft_strdup("")) * 0));

	return (make_line(&holder, line));
}
