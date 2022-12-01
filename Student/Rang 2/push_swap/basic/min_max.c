/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:53:54 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/01 09:53:57 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max(t_stack *a, t_data *data)
{
	int	index;

	index = 0;
	data->max = a->data[0];
	data->max_index = index;
	if (a->index == 0)
		return ;
	while (index < a->index)
	{
		if (a->data[index] > data->max)
		{
			data->max = a->data[index];
			data->max_index = index;
		}
		index++;
	}
}

void	get_min(t_stack *a, t_data *data)
{
	int	index;

	index = 0;
	data->min = a->data[0];
	data->min_index = 0;
	if (a->index == 0)
		return ;
	while (index < a->index)
	{
		if (a->data[index] < data->min)
		{
			data->min = a->data[index];
			data->min_index = index;
		}
		index++;
	}
}