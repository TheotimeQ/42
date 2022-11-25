/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:56:21 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/24 17:59:24 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	resolve_push_swap(t_stack *a, t_stack *b)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
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
	free(data);
}
