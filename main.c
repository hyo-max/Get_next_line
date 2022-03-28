/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:12:51 by hyojpark          #+#    #+#             */
/*   Updated: 2022/03/25 19:58:17 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
//gnl_test
	int	fd;
	char *line;

	fd = open("hello.txt", O_RDONLY);
	if(fd < 0)
		printf("file open error");
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%s\n",line);
	// 	free(line);
	// }
	line = get_next_line(fd);
	printf("%s\n",line);
	free(line);
	close(fd);
	


//파일 오픈하는 법
	// int fd;
	// char buff[42];
	// int	file_bite;
	// int i = 0;

	// fd = open("hello.txt", O_RDONLY);
	// if (fd < 0)
	// 	printf("error file open");
	// else
	// {
	// 	file_bite = read(fd, buff, sizeof(buff));
	// 	if (file_bite > 0)
	// 	{
	// 		// printf("%d\n", file_bite);
	// 	}
	// 	i = 0;
	// 	while(file_bite){
	// 		write(1, &buff[i], 1);
	// 		i++;
	// 		file_bite--;
	// 	}
	// 	// printf("%s\n", buff);
	// 	close(fd);
	// }

//파일디스크립터 값 조회
	// int fd_1;
    // int fd_2;
    
    // fd_1 = open("a.out", O_RDONLY);
    // printf("fd_1 = %d\n", fd_1);
    // fd_2 = open("a.out", O_RDONLY);
    // printf("fd_2 = %d\n", fd_2);

	// int fd_1;
    // int fd_2;
    
    // fd_1 = open("a.out", O_RDONLY);
    // printf("fd_1 = %d\n", fd_1);
    // close(fd_1);
    // fd_2 = open("a.out", O_RDONLY);
    // printf("fd_2 = %d\n", fd_2);
    // close(fd_2);
}
