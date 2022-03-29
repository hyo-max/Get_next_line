/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:16:55 by hyojpark          #+#    #+#             */
/*   Updated: 2022/03/29 15:31:19 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*buf_save(char *line)
{
	int		i;
	int		line_len;
	char	*buf_backup;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	line_len = ft_strlen(line);
	buf_backup = (char *)malloc(sizeof(char) * (line_len - i + 1));
	if (!buf_backup)
		return (NULL);
	i = 0;
	while (line[i + line_len])
	{
		buf_backup[i] = line[i + line_len];
		i++;
	}
	free(line);
	return (buf_backup);
}

char	*make_line(char *line)
{
	char	*result;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		result[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		result[i] = line[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*read_line(int fd, char *line)
{
	char	*buf;
	int		read_byte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!(ft_strchr(line, '\n')) || !(ft_strchr(line, '\0')))
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		line = ft_strjoin(line, buf);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, line);
	if (!line)
		return (NULL);
	result = make_line(line);
	line = buf_save(line);
	return (result);
}
