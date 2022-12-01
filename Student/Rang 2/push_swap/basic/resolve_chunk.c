/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:00:33 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/01 16:59:37 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_insert_index(t_stack *b, t_data *data)
{	
	int	i;

	if (b->index == 0)
	{
		data->index_to_place_key = 0;
		return ;
	}
	get_min(b, data);
	if (data->key < data->min)
	{	
		data->index_to_place_key = data->min_index;
		if (data->index_to_place_key < 0)
			data->index_to_place_key = b->index;
		return ;
	}
	get_max(b, data);
	if (data->max < data->key)
	{	
		data->index_to_place_key = data->max_index + 1;
		return ;
	}
	i = 0;
	while (i + 1 < b->index)
	{	
		if (b->data[i] < data->key && data->key < b->data[i + 1])
			break ;
		i++;
	}
	data->index_to_place_key = i + 1;
}

void	insert_key(t_stack *b, t_data *data)
{	
	find_insert_index(b, data);		
	get_rot_dir_b(b, data);
	
}

void	min_to_top(t_stack *a, t_data *data)
{
	get_min(a, data);
	get_rot_min(a, data);
	rot_a(a, data);
}

void	rot_stack_opti(t_stack *a, t_stack *b, t_data *data)
{
	if (data->dir_rot_a == data->dir_rot_b)
	{
		while (data->nb_rot_b && data->nb_rot_a)
		{
			if (data->dir_rot_b == 1)
				rr(a, b, data);
			else
				rrr(a, b, data);
			data->nb_moove++;
			data->nb_rot_a--;
			data->nb_rot_b--;
		}
	}
	rot_a(a, data);
	rot_b(b, data);
}

void	resolve_one_test(t_stack *a, t_stack *b, t_data *data)
{	
	print_list(a, b);
	data->current_chunk = 0;				
	while (a->index >= 0 && data->current_chunk <= data->nb_chunk)
	{	
		if (scan_from_top(a, data) || scan_from_bot(a, data))
			data->current_chunk += 1;
		else
		{	
			chosse_key(a, data);
			insert_key(b, data);
			rot_stack_opti(a, b, data);

			// printf("Key :%d , inbsert in :%d",data->key, data->index_to_place_key);
			
			//on ne push pas a si a sorted et > au reste
			get_min(a, data);
			get_max(b, data);
			if (is_sorted(-1, a) && data->min > data->max)
				break;
			pb(a, b, data);
			data->nb_moove++;
			// print_list(a, b);
		}
	}
	push_all_b(a, b, data);
	// print_list(a, b);
	min_to_top(a, data);
	// print_list(a, b);
}
// make && ./push_swap 9 -2 0 6 7