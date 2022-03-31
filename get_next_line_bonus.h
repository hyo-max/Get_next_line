/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojpark <hyojpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:05:33 by hyojpark          #+#    #+#             */
/*   Updated: 2022/03/31 10:55:40 by hyojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEN_NEXT_LINE_BONUS_H
# define GEN_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(char *s, int c);

#endif