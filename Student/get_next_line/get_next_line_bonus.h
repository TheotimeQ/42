/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:29:20 by tquere            #+#    #+#             */
/*   Updated: 2022/11/17 13:51:15 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

char	*get_next_line(int fd);
char	*save(char *str, char *buffer, int i);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

#endif