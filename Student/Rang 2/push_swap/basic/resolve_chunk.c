/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:00:33 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/02 11:25:54 by zelinsta         ###   ########.fr       */
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



void	rot_and_swap(t_stack *a, t_data *data)
{	
	while (data->nb_rot_a--)
	{	
		if (a->data[a->index - 1] > a->data[a->index - 2])
		{
			sa(a, data);
			data->nb_moove++;
		}
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


int	try_sort_a(t_stack *a, t_stack *b, t_data *data)
{
	t_stack		*cpy;
	int			nb_moove;
	int			should_print;

	get_min(a, data);
	get_max(b, data);
	if (b->index == 0 || data->min > data->max)
	{
		should_print = data->print;
		nb_moove = data->nb_moove;
		data->print = 0;	
		cpy = copy_a(a, data);

		// printf("----------------------\n");
		// printf("Before rot min\n");
		// print_list(cpy, data->b);

		get_min(cpy, data);
		get_rot_min(cpy, data);
		// rot_a(cpy, data);
		rot_and_swap(cpy, data);

		// printf("After rot min\n");
		// print_list(cpy, data->b);
		// printf("----------------------\n");
		
		data->nb_moove = nb_moove;
		data->print = should_print;
		if (is_sorted(-1, cpy))
		{	
			free_stack(cpy);	
			return (1);
		}
		free_stack(cpy);
		return (0);
	}
	else
		return (0);	
}


// 2   sa 	1
// 1		2
// 0		0


void	resolve_one_test(t_stack *a, t_stack *b, t_data *data)
{	
	// print_list(a, b);
	data->current_chunk = 0;				
	while (a->index >= 0 && data->current_chunk <= data->nb_chunk)
	{	
		// print_list(a, b);
		
		if (try_sort_a(a, b, data))
		{
			get_min(a, data);
			get_rot_min(a, data);
			// rot_a(a, data);
			rot_and_swap(a, data);
			break;
		}

		if (scan_from_top(a, data) || scan_from_bot(a, data))
			data->current_chunk += 1;
		else
		{	
			// print_list(a, b);
			chosse_key(a, data);
			insert_key(b, data);
			rot_stack_opti(a, b, data);
			get_min(a, data);
			get_max(b, data);
			if (is_sorted(-1, a) && data->min > data->max)
				break;
			pb(a, b, data);
			data->nb_moove++;
		}
	}
	push_all_b(a, b, data);
	min_to_top(a, data);
	// print_list(a, b);
}
// make && ./push_swap 9 -2 0 6 7