/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:05:33 by hyojpark          #+#    #+#             */
/*   Updated: 2022/03/31 11:19:47 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*read_line(int fd, char *line, char *temp, char *buf);
char	*make_line(char *line);
char	*buf_save(char *line);

size_t	ft_strlen(const char *c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(char *s, int c);

#endif