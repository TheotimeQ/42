/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:29:27 by tquere            #+#    #+#             */
/*   Updated: 2022/12/03 17:05:18 by tquere           ###   ########.fr       */
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
	while (data->nb_rot_a--)
	{
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

void	rot_b(t_stack *b, t_data *data)
{
	while (data->nb_rot_b--)
	{
		if (data->dir_rot_b == 1)
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
