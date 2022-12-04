/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:27:58 by tquere            #+#    #+#             */
/*   Updated: 2022/12/04 10:22:32 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rot_dir_a(t_stack *a, t_data *data)
{	
	if (a->index == 0)
	{
		data->dir_rot_a = 1;
		data->nb_rot_a = 0 ;
		return ;
	}
	if (data->index_to_place_key >= a->index / 2)
	{
		data->dir_rot_a = 1;
		data->nb_rot_a = a->index - data->index_to_place_key;
	}
	else
	{
		data->dir_rot_a = -1;
		data->nb_rot_a = data->index_to_place_key;
	}
}

void	get_rot_dir_b(t_stack *b, t_data *data)
{	
	if (b->index == 0)
	{
		data->dir_rot_b = 1;
		data->nb_rot_b = 0 ;
		return ;
	}
	if (data->index_to_place_key >= b->index / 2)
	{
		data->dir_rot_b = 1;
		data->nb_rot_b = b->index - data->index_to_place_key;
	}
	else
	{
		data->dir_rot_b = -1;
		data->nb_rot_b = data->index_to_place_key;
	}
}

void	get_rot_min(t_stack *a, t_data *data)
{	
	if (a->index == 0)
	{
		data->dir_rot_a = 1;
		data->nb_rot_a = 0 ;
		return ;
	}
	if (data->min_index >= a->index / 2)
	{
		data->dir_rot_a = 1;
		data->nb_rot_a = a->index - data->min_index - 1;
	}
	else
	{
		data->dir_rot_a = -1;
		data->nb_rot_a = data->min_index + 1;
	}
}

void	get_rot_max(t_stack *b, t_data *data)
{	
	if (b->index == 0)
	{
		data->dir_rot_b = 1;
		data->nb_rot_b = 0 ;
		return ;
	}
	if (data->max_index >= b->index / 2)
	{
		data->dir_rot_b = 1;
		data->nb_rot_b = b->index - data->max_index - 1;
	}
	else
	{
		data->dir_rot_b = -1;
		data->nb_rot_b = data->max_index + 1;
	}
}

void	rot_and_swap(t_stack *a, t_data *data)
{	
	while (data->nb_rot_a--)
	{	
		if (a->data[a->index - 1] > a->data[a->index - 2])
		{
			sa(a, data);
			data->nb_moove++;
		}
		if (is_sorted(-1, a))
			return ;
		if (data->dir_rot_a == 1)
		{
			ra(a, data);
			data->nb_moove++;
		}
		else
		{
			rra(a, data);
			data->nb_moove++;
		}
	}
}
