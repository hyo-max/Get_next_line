/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:16:55 by hyojpark          #+#    #+#             */
/*   Updated: 2022/03/29 09:38:44 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buf_save(char *buf_backup)
{

	return (buf_backup);
}

char	*make_line(char *buf_backup)
{
	char	*line;
	int	i;

	i = 0;
	if (!buf_backup[i])
		return (NULL);
	while(buf_backup != '\0')

	
	return (line);
}

char	*read_line(int fd, char *buf_backup)
{
	char	*buf;
	int		read_byte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return(NULL);
	
	while(!(ft_strchr(buf_backup, '\n')) || !(ft_strchr(buf_backup, '\0')))
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf_backup = ft_strjoin(buf_backup, buf);
	}
	free(buf);
	return (buf_backup);
}

char	*get_next_line(int fd)
{
	static char	*buf_backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf_backup = read_line(fd, buf_backup);
	if (!buf_backup)
		return (NULL);
	line = make_line(buf_backup);
	buf_backup = buf_save(buf_backup);

	return (buf_backup);
}
