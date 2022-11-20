/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:56:21 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/19 14:57:34 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	get_min(t_stack *a, t_data *data)
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

static void	push_all_b(t_stack *a, t_stack *b)
{
	while (b->index)
		pa(a, b);
}

static int	is_sorted(int comp, t_stack *stack)
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

static void get_rot_dir(t_stack *a, t_data *data)
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

static void	rot_min_to_top(t_stack *a, t_data *data)
{
	while (data->nb_rot--)
	{
		if (data->dir_rot == 1)
			ra(a);
		else
			rra(a);
	}
}

void resolve_push_swap(t_stack *a, t_stack *b)
{
	t_data *data;

	data = malloc(sizeof(t_data));

	while (!is_sorted(-1, a) && a->index > 0)
	{
		if (a->data[a->index - 1] > b->data[b->index - 1] && a->index > 0 && b->index > 0 && is_sorted(-1, a))
			break;
		get_min(a, data);
		get_rot_dir(a, data);
		rot_min_to_top(a, data);
		pb(a, b);
	}
	push_all_b(a, b);
	free(data);
}
