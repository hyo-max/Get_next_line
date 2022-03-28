/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:16:55 by hyojpark          #+#    #+#             */
/*   Updated: 2022/03/28 13:17:41 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *save)
{
	char	*buf;
	int		read_byte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return(NULL);
	while()
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buf);
			return (NULL);
		}
	}

	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	save = read_line(fd, save);


	file_bite = read(fd, buf, BUFFER_SIZE);
	if (file_bite == -1)
	{
		free(buf);
		return (NULL);
	}
	i = 0;
	while (file_bite)
	{
		if (buf[i] != '\n')
		{
			buf[i];
		}
	}
	buf[i] = '\0';

	return (buf);
	//read()
	//read, malloc, free
	///파일 디스크립터가 파일의 주민번호
}
