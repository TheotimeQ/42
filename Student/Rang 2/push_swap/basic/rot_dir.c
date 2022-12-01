/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:54:49 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/01 12:01:50 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rot_dir(t_stack *b, t_data *data)
{	
	if (b->index == 0)
	{
		data->dir_rot = 1;
		data->nb_rot = 0 ;
		return ;
	}
	if (data->index_to_place_key - 1 > b->index / 2)
	{
		data->dir_rot = 1;
		data->nb_rot = b->index - data->index_to_place_key;
	}
	else
	{
		data->dir_rot = -1;
		data->nb_rot = data->index_to_place_key;
	}
}

void	get_rot_min(t_stack *a, t_data *data)
{	
	if (a->index == 0)
	{
		data->dir_rot = 1;
		data->nb_rot = 0 ;
		return ;
	}
	if (data->min_index > a->index / 2)
	{
		data->dir_rot = 1;
		data->nb_rot = a->index - data->min_index - 1;
	}
	else
	{
		data->dir_rot = -1;
		data->nb_rot = data->min_index + 1;
	}
}


void	get_rot_dir(t_stack *b, t_data *data);
void	get_rot_min(t_stack *a, t_data *data);