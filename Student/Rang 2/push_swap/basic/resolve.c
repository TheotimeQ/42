/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:56:21 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/02 11:26:51 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	test_chunk(t_stack *a, t_stack *b, t_data *data)
{	
	t_stack		*cpy_a;
	int			current_test;

	data->print = 0;
	cpy_a = copy_a(a, data);
	current_test = 0;
	while (current_test < data->nb_test)
	{	
		data->nb_chunk = current_test * 1 + 1;
		if(cut_chunk(data, a))
		{
			free_stack(cpy_a);
			leave(data);
		}
		data_cpy(a, cpy_a);
		data->nb_moove = 0;
		resolve_one_test(cpy_a, b, data);
		if (data->min_moove < 0 || data->nb_moove < data->min_moove)
		{
			data->min_moove = data->nb_moove;
			data->nb_chunk_choosed = data->nb_chunk;
		}
		// printf("NB_CHUNK:%d, MOOVE:%d\n",data->nb_chunk,data->nb_moove);
		current_test++;
	}
	free_stack(cpy_a);
}

static void	repeat_best_test(t_stack *a, t_stack *b, t_data *data)
{
	data->nb_chunk = data->nb_chunk_choosed;
	data->print = 1;
	data->nb_moove = 0;
	if(cut_chunk(data, a))
		leave(data);
	resolve_one_test(a, b, data);
}

void	resolve_push_swap(t_stack *a, t_stack *b, t_data *data)
{	
	if (is_sorted(-1, a) == 1 && b->index == 0)
		return;

	test_min_to_top(a, data);
	test_chunk(a, b, data);
	repeat_best_test(a, b, data);

	// printf("Final nb chunk:%d, moove:%d\n",data->nb_chunk_choosed, data->min_moove);
	// if (is_sorted(-1, a) == 1 && b->index == 0)
	// 	write(1, "OK\n", 3);
    // else
	// 	write(1, "KO\n", 3);

	return ;
}

// make && ./push_swap 42
// make && ./push_swap 0 1 2 3
// make && ./push_swap 0 1 2 3 4 5 6 7 8 9
// make && ./push_swap 2 1 0
// make && ./push_swap 1 5 2 4 3
// make && ./push_swap 9 -2 8 -4 1
// make && ./push_swap  100 random value 		< 1500
// make && ./push_swap  500 random value 		< 11500

// make && ./push_swap 2602 1769 2803 1254 2681 393 1546

// https://www.random.org/integer-sets/
// https://github.com/rizky/42-corrections/blob/master/push_swap.pdf


