/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:41:46 by tquere            #+#    #+#             */
/*   Updated: 2022/12/04 14:19:36 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	max_to_top(t_stack *b, t_data *data)
{
	get_max(b, data);
	get_rot_max(b, data);
	rot_b(b, data);
}

static void	min_to_top(t_stack *a, t_data *data)
{
	get_min(a, data);
	get_rot_min(a, data);
	rot_a(a, data);
}

void	resolve_one_test(t_stack *a, t_stack *b, t_data *data)
{	
	data->current_chunk = 0;
	while (a->index >= 0 && data->current_chunk <= data->nb_chunk)
	{	
		if (try_sort_a(a, b, data))
		{	
			get_min(a, data);
			get_rot_min(a, data);
			rot_and_swap(a, data);
			break ;
		}
		if (scan_from_bot(a, data) || scan_from_top(a, data))
			data->current_chunk += 1;
		else
		{	
			chosse_key(a, data);
			insert_key(a, b, data);
			if (is_sorted(-1, a) && data->min > data->max)
				break ;
			pb(a, b, data);
			data->nb_moove++;
		}
	}
	max_to_top(b, data);
	push_all_b(a, b, data);
	min_to_top(a, data);
}
