/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:53:32 by zqouri            #+#    #+#             */
/*   Updated: 2023/12/08 02:14:52 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest_line(char *line)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	size = ft_strlen(line) - i;
	str = (char *)ft_calloc(size , 1);
	if (!str)
		return (NULL);
	if (line[i] == '\n')
		i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	return (free(line), str);
}

char	*get(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		str = (char *)malloc(sizeof(char) * (i + 2));
	else
		str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return ( NULL);
	//str = (char *)ft_calloc(i + 2, 1);
	//if (!str)
	//	return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*readded(char *line, int fd)
{
	char	*buffer;
	int		char_read;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	char_read = 1;
	while (char_read > 0 && !ft_strchr(line, '\n'))
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == 0)
			break ;
		else if (char_read == -1)
			return (free(buffer), free(line), NULL);
		buffer[char_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(buffer), NULL);
	}
	return (free(buffer), line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;

	str = NULL;
	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 0)//lekas
		return (NULL);
	line = readded(line, fd);
	if (!line)
		return (NULL);
	str = get(line);
	if (!str || !str[0])
		return (free(line),NULL);//free line
	line = rest_line(line);
	return (str);
}

//int main(void)
//{
//	int	fd;
//	fd = open("test3.txt",O_RDONLY);
//	char *str;
	
//	while ((str = get_next_line(fd)))
//	{
//		printf("buffer->%s",str);
//		free(str);
//	}
//}