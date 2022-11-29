/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:58:51 by tquere            #+#    #+#             */
/*   Updated: 2022/11/29 18:26:06 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_b(t_stack *a, t_stack *b, t_data *data)
{
	while (b->index)
	{
		pa(a, b, data);
		data->nb_moove++;
	}
}

void	rot_a(t_stack *a, t_data *data)
{	
	while (data->nb_rot--)
	{
		if (data->dir_rot == 1)
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

void	rot_b(t_stack *b, t_data *data)
{
	while (data->nb_rot--)
	{
		if (data->dir_rot == 1)
		{
			rb(b, data);
			data->nb_moove++;
		}
		else
		{
			rrb(b, data);
			data->nb_moove++;
		}
	}
}

size_t	is_sorted(int comp, t_stack *stack)
{
	size_t	index;

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
