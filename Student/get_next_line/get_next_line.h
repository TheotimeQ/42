/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:29:20 by tquere            #+#    #+#             */
/*   Updated: 2022/11/16 19:27:48 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

char	*get_next_line(int fd);
char	*save(char *str, char *buffer, int i);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

#endif