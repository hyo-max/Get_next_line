/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:05:27 by hyojpark          #+#    #+#             */
/*   Updated: 2022/03/31 11:15:30 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (!line)
		return (NULL);
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
	{
		result[i++] = '\n';
	}
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
	static char	*line[OPEN_MAX];
	char		*result;
	char		*temp;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	temp = NULL;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line[fd] = read_line(fd, line[fd], temp, buf);
	if (!line[fd])
		return (NULL);
	result = make_line(line[fd]);
	line[fd] = buf_save(line[fd]);
	return (result);
}
