/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:22:56 by tquere            #+#    #+#             */
/*   Updated: 2022/11/22 12:44:28 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*save(char *str, char *buffer, int i);
void	*ft_memset(void *b, int c, size_t len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

#endif