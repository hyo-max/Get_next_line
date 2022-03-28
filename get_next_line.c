/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:16:55 by hyojpark          #+#    #+#             */
/*   Updated: 2022/03/28 15:04:42 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buf_save()
{

}

char	*make_line()
{

}

char	*read_line(int fd, char *buf_backup)
{
	char	*buf;
	int		read_byte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return(NULL);
	while(buf_backup != '\n' || buf_backup != '\0')
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf);
			return (NULL);
		}
		buf_backup = ft_strjoin(buf_backup, buf);
		return (buf_backup);
	}
	return (buf_backup);
}

char	*get_next_line(int fd)
{
	static char	*buf_backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buf_backup = read_line(fd, buf_backup);
	line = make_line();
	buf_backup = buf_save();

	return (line);
}
