/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:24:43 by tquere            #+#    #+#             */
/*   Updated: 2022/11/19 11:11:07 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*save(char *str, char *buffer, int i);
void	*ft_memset(void *b, int c, size_t len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

#endif