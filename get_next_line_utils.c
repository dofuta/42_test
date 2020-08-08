/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdofuku <tdofuku@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 13:52:12 by tdofuku           #+#    #+#             */
/*   Updated: 2020/08/08 22:39:12 by tdofuku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	if (!(dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char))))
		return (0);
	i = 0;
	while ((src)[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;
	size_t	len;

	CHECK_PTR(s1);
	CHECK_PTR(s2);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len = len_s1 + len_s2 + 1;
	result = ft_calloc(sizeof(char), len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len_s1 + 1);
	ft_strlcat(result, s2, len);
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	size_t			i;
	unsigned char	*str;

	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
	str = (unsigned char *)p;
	i = 0;
	while (i < (count * size))
	{
		*(str + i) = (unsigned char)(count * size);
		i++;
	}
	return (p);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	src_len = 0;
	dest_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	while (dest[dest_len])
		dest_len++;
	if (size == 0)
		return (src_len);
	while (src[i] && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (size < dest_len)
		return (src_len + size);
	else
		return (dest_len + src_len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	l;
	unsigned int	c;

	CHECK_PTR_DEF(dest, 0);
	CHECK_PTR_DEF(src, 0);
	c = 0;
	l = ft_strlen(src);
	if (size == 0)
		return (l);
	while (src[c] != '\0' && c < size - 1)
	{
		dest[c] = src[c];
		c += 1;
	}
	dest[c] = '\0';
	return (l);
}
