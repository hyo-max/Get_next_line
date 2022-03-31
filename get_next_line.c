/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:16:55 by hyojpark          #+#    #+#             */
/*   Updated: 2022/03/31 09:03:08 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buf_save(char *line)
{
	int		i;
	int		line_len;
	char	*buf_backup;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	line_len = ft_strlen(line);
	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	buf_backup = (char *)malloc(sizeof(char) * (line_len - i));
	if (!buf_backup)
		return (NULL);
	line_len = 0;
	i++;
	while (line[i])
		buf_backup[line_len++] = line[i++];
	buf_backup[line_len] = '\0';
	free(line);
	return (buf_backup);
}

char	*make_line(char *line)
{
	char	*result;
	int		i;

	i = 0;
	if (line[0] == '\0')
		return (NULL);
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
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

char	*read_line(int fd, char *line, char *temp, char *buf)
{
	int		read_byte;

	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_byte] = '\0';
		temp = line;
		if (!temp)
		{
			temp = malloc(sizeof(char) * 1);
			temp[0] = '\0';
		}
		line = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*result;
	char		*temp;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = NULL;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_line(fd, line, temp, buf);
	if (!line)
		return (NULL);
	result = make_line(line);
	line = buf_save(line);
	return (result);
}
