/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:38:03 by tquere            #+#    #+#             */
/*   Updated: 2022/12/04 14:19:21 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cut_chunk_egale(t_data *data)
{	
	int	i;
	int	index;

	if (data->chunk == NULL)
		return (1);
	i = 0;
	while (i <= data->nb_chunk)
	{	
		index = i * (data->sorted_a->index - 1) / data->nb_chunk;
		(data->chunk)[data->nb_chunk - i] = (data->sorted_a->data)[index];
		i++;
	}
	return (0);
}

int	cut_chunk(t_data *data, t_stack *a)
{	
	int	i;

	get_min(a, data);
	get_max(a, data);
	if (data->chunk == NULL)
		return (1);
	i = 0;
	while (i <= data->nb_chunk)
	{	
		(data->chunk)[i] = data->min + i
			* (data->max - data->min) / data->nb_chunk;
		i++;
	}
	return (0);
}

int	scan_from_top(t_stack *a, t_data *data)
{
	int	index;

	index = a->index - 1;
	while (index >= 0)
	{	
		if ((data->chunk)[data->current_chunk] <= a->data[index]
			&& a->data[index] <= (data->chunk)[data->current_chunk + 1])
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
		if ((data->chunk)[data->current_chunk] <= a->data[index]
			&& a->data[index] <= (data->chunk)[data->current_chunk + 1])
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
