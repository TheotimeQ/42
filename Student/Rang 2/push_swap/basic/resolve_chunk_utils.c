/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_chunk_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:29:36 by tquere            #+#    #+#             */
/*   Updated: 2022/12/03 17:14:29 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*find_insert_index(t_stack *b, t_data *data)
{	
	int	i;

	if (b->index == 0)
		return (data->index_to_place_key = 0, NULL);
	get_min(b, data);
	if (data->key < data->min)
	{	
		data->index_to_place_key = data->min_index;
		if (data->index_to_place_key < 0)
			data->index_to_place_key = b->index;
		return (NULL);
	}
	get_max(b, data);
	if (data->max < data->key)
		return (data->index_to_place_key = data->max_index + 1, NULL);
	i = 0;
	while (i + 1 < b->index)
	{	
		if (b->data[i] < data->key && data->key < b->data[i + 1])
			break ;
		i++;
	}
	data->index_to_place_key = i + 1;
	return (NULL);
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
		get_rot_min(cpy, data);
		rot_and_swap(cpy, data);
		data->nb_moove = nb_moove;
		data->print = should_print;
		if (is_sorted(-1, cpy))
			return (free_stack(cpy), 1);
		free_stack(cpy);
		return (0);
	}
	else
		return (0);
}

void	insert_key(t_stack *a, t_stack *b, t_data *data)
{	
	find_insert_index(b, data);
	get_rot_dir_b(b, data);
	rot_stack_opti(a, b, data);
	get_min(a, data);
	get_max(b, data);
}
