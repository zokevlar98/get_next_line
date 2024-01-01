/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:00:06 by zqouri            #+#    #+#             */
/*   Updated: 2023/12/31 00:57:15 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//void	ft_bzero(void *p, size_t size)
//{
//	unsigned char	*ptr;
//	size_t			i;

//	i = 0;
//	ptr = (unsigned char *)p;
//	while (i < size)
//	{
//		ptr[i] = 0;
//		i++;
//	}
//}

//void	*ft_calloc(size_t count, size_t size)
//{
//	void	*ptr;
//	int		i;

//	i = 0;
//	ptr = malloc(count * size);
//	if (!ptr)
//		return (NULL);
//	ft_bzero(ptr, (size * count));
//	return (ptr);
//}

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

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	p = (char *)s;
	while (p[i] != '\0')
	{
		if (p[i] == (char)c)
			return (p + i);
		i++;
	}
	if (p[i] == (char)c)
		return (p + i);
	return (NULL);
}
/*si mon static varriable est NULL on alloc le vide*/
char	*ft_strdup(char *src)
{
	int		i;
	char	*str;
	size_t	size;

	i = 0;
	if (!src)
		return (NULL);
	size = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;
	size_t	size;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (s1);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (free(s1), str);
}
