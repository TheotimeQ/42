/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:05:42 by tquere            #+#    #+#             */
/*   Updated: 2022/07/27 05:50:27 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef struct s_map_var
{
	int		x;
	int		y;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
	int		sol_x;
	int		sol_y;
	int		sol_side_len;
	int		error;
	int		stop;
	int		file;
	int		visual;
	int		crt_lin;
	int		last_count_size;
	int		malloc_len;
}	t_map_var;

#endif
