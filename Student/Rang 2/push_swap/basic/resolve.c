/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:56:21 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/25 10:11:29 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_push_swap(t_stack *a, t_stack *b)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	print_list(a, b);
	while (!is_sorted(-1, a) && a->index > 0)
	{
		if (a->data[a->index - 1] > b->data[b->index - 1]
			&& a->index > 0 && b->index > 0 && is_sorted(-1, a))
			break ;
		get_min(a, data);
		get_rot_dir(a, data);
		rot_min_to_top(a, data);
		pb(a, b);
	}
	push_all_b(a, b);
	print_list(a, b);
	free(data);
}
