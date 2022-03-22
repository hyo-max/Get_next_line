/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:16:55 by hyojpark          #+#    #+#             */
/*   Updated: 2022/03/22 19:57:58 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);

		
	read(fd,buf,BUFFER_SIZE);
	//read()
	//read, malloc, free
	///파일 디스크립터가 파일의 주민번호
}
