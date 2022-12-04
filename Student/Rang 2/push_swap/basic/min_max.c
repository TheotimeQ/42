/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:38:09 by tquere            #+#    #+#             */
/*   Updated: 2022/12/03 16:12:11 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max(t_stack *a, t_data *data)
{
	int	index;

	index = 0;
	if (a->index == 0)
		return ;
	data->max = a->data[0];
	data->max_index = index;
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
	if (a->index == 0)
		return ;
	data->min = a->data[0];
	data->min_index = 0;
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
