/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:28:36 by tquere            #+#    #+#             */
/*   Updated: 2022/07/24 22:11:48 by tquere           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_input
{
	char	*file;
	char	*value;
	int		error;
}		t_input;
typedef struct s_dict
{
	char	**zero_twenty;
	char	**twenty_hundred;
	char	**ten_power;
	int		max_power;
	int		error;
	char	*key;
	char	*value;
	int		index;
}		t_dict;
typedef struct s_parsing
{
	int		len_nb;
	int		ten_power;
	int		index_left;
	int		index_right;
	int		error;
}		t_parsing;
#endif
