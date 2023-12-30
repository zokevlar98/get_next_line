/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:53:32 by zqouri            #+#    #+#             */
/*   Updated: 2023/12/30 07:04:04 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (NULL);
	if (line[i])
		i++;
	while (line[i])
	{
		str[j] = line[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (free(line), str);
}

char	*get_line_m(char *line)
{
	int		i;
	char	*str;

	str = NULL;
	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	//if (line[i] == '\n')
	str = (char *)malloc(sizeof(char) * (i + 2));
	//if (line[i] == '\0')
	//	str = (char *)malloc(sizeof(char) * (i + 1));
	//else
	//	str = NULL;
	if (!str)
		return (NULL);
	i = -1;
	while (line[++i] && line[i] != '\n')
		str[i] = line[i];
	if (line[i] && line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char	*buffer;
	int		char_read;
	char	*str;
	
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buffer)
		return (free(buffer), NULL);
	while (1)
	{
		if (!ft_strchr(line, '\n'))
		{
			char_read = read(fd, buffer, BUFFER_SIZE);
			if (char_read == 0)
			{
				str = line;
				line = NULL;
				return (free(buffer), str);
			}
			if (char_read == -1)
			{
				line = NULL;
				return (free(buffer), NULL);
			}
			buffer[char_read] = '\0';
			line = ft_strjoin(line, buffer);
		}
		//if (!line)
		//	return (NULL);
		if (ft_strchr(line, '\n'))
			break;
	}
	str = get_line_m(line);
	if (!str || !str[0])
		return (free(line), free(buffer), NULL);
	line = rest_line(line);
	if (!line)
		return (NULL);
	return (free(buffer), str);
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