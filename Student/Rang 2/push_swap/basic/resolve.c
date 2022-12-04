/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:29:22 by tquere            #+#    #+#             */
/*   Updated: 2022/12/04 16:40:42 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_sorted_cpy(t_data *data)
{	
	data->nb_chunk = 5;
	data_cpy(data->a, data->sorted_a);
	if (cut_chunk(data, data->a))
	{
		free_stack(data->sorted_a);
		leave(data);
	}
	resolve_one_test(data->sorted_a, data->b, data);
}

static void	test_chunk(t_stack *a, t_stack *b, t_data *data)
{	
	t_stack		*cpy_a;
	int			current_test;

	current_test = 0;
	cpy_a = copy_a(a, data);
	while (current_test < data->nb_test)
	{	
		data->nb_moove = 0;
		data->nb_chunk = current_test * 1 + 1;
		if (cut_chunk_egale(data))
		{
			free_stack(cpy_a);
			leave(data);
		}
		data_cpy(a, cpy_a);
		resolve_one_test(cpy_a, b, data);
		if (data->min_moove < 0 || data->nb_moove < data->min_moove)
		{
			data->min_moove = data->nb_moove;
			data->nb_chunk_choosed = data->nb_chunk;
		}
		current_test++;
	}
	free_stack(cpy_a);
}

static void	repeat_best_test(t_stack *a, t_stack *b, t_data *data)
{	
	data->nb_chunk = data->nb_chunk_choosed;
	data->nb_moove = 0;
	if (cut_chunk_egale(data))
		leave(data);
	resolve_one_test(a, b, data);
}

void	resolve_push_swap(t_stack *a, t_stack *b, t_data *data)
{	
	data->min_moove = -1;
	if (is_sorted(-1, a) == 1 && b->index == 0)
		return ;
	test_min_to_top(a, data);
	create_sorted_cpy(data);
	data->print = 0;
	test_chunk(a, b, data);
	data->print = 1;
	repeat_best_test(a, b, data);
}
