/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:58:51 by tquere            #+#    #+#             */
/*   Updated: 2022/11/25 10:06:37 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min(t_stack *a, t_data *data)
{
	int	index;

	index = 0;
	if (a->index == 0)
		return ;
	data->min = a->data[0];
	data->min_index = 0;
	while (index < a->index)
	{
		if (a->data[index] < data->min)
		{
			data->min_index = index;
			data->min = a->data[index];
		}
		index++;
	}
}

void	push_all_b(t_stack *a, t_stack *b)
{
	while (b->index)
		pa(a, b);
}

void	get_rot_dir(t_stack *a, t_data *data)
{
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

void	rot_min_to_top(t_stack *a, t_data *data)
{
	while (data->nb_rot--)
	{
		if (data->dir_rot == 1)
			ra(a);
		else
			rra(a);
	}
}

int	is_sorted(int comp, t_stack *stack)
{
	int	index;

	index = stack->index - 1;
	if (stack->index <= 0)
		return (0);
	while (index > 0)
	{
		if (stack->data[index] * comp < stack->data[index - 1] * comp)
			return (0);
		index--;
	}
	return (1);
}
