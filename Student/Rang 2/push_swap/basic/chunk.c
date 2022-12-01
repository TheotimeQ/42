/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:53:45 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/01 16:26:17 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cut_chunk(t_data *data, t_stack *a)
{	
	int	i;

	get_min(a, data);
	get_max(a, data);
	if (data->chunk == NULL)
		return (1);
	i = 0;
	// printf("\n");
	while (i <= data->nb_chunk)
	{	
		(data->chunk)[i] = data->min + i
			* (data->max - data->min) / data->nb_chunk;
		// printf("| %d ",(data->chunk)[i]);
		i++;
	}
	// printf("\n");
	return (0);
}

int	scan_from_top(t_stack *a, t_data *data)
{
	int	index;

	index = a->index - 1;
	while (index >= 0)
	{
		if ((data->chunk)[data->current_chunk - 1] <= a->data[index]
			&& a->data[index] <= (data->chunk)[data->current_chunk])
		{
			data->top_key = a->data[index];
			data->top_key_index = index;
			return (0);
		}
		index--;
	}
	return (1);
}

int	scan_from_bot(t_stack *a, t_data *data)
{
	int	index;

	index = 0;
	while (index < a->index)
	{	
		if ((data->chunk)[data->current_chunk - 1] <= a->data[index]
			&& a->data[index] <= (data->chunk)[data->current_chunk])
		{
			data->bot_key = a->data[index];
			data->bot_key_index = index;
			return (0);
		}
		index++;
	}
	return (1);
}

void	chosse_key(t_stack *a, t_data *data)
{	
	if (data->bot_key_index < (a->index - data->top_key_index) - 1)
	{
		data->key = data->bot_key;
		data->key_index = data->bot_key_index;
		data->dir_rot_a = -1;
		data->nb_rot_a = data->bot_key_index + 1;
	}
	else
	{
		data->key = data->top_key;
		data->key_index = data->top_key_index;
		data->dir_rot_a = 1;
		data->nb_rot_a = (a->index - data->top_key_index) - 1;
	}
}