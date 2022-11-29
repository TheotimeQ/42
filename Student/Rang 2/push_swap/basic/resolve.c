/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:56:21 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/29 19:25:56 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max(t_stack *a, t_data *data)
{
	size_t	index;

	index = 0;
	if (a->index == 0)
		return ;
	data->max = a->data[0];
	while (index < a->index)
	{
		if (a->data[index] > data->max)
			data->max = a->data[index];
		index++;
	}
}

void	get_min(t_stack *a, t_data *data)
{
	size_t	index;

	index = 0;
	if (a->index == 0)
	{
		data->min_index = 0;
		return ;
	}
	data->min = a->data[0];
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

static size_t	cut_chunk(t_data *data, t_stack *a)
{	
	size_t	i;

	get_min(a, data);
	get_max(a, data);
	data->chunk = malloc((data->nb_chunk + 1) * sizeof(int));
	if (data->chunk == NULL)
		return (1);
	i = 0;
	printf("| min:%d max:%d |", data->min, data->max);
	printf("\n");
	while (i <= data->nb_chunk)
	{	
		(data->chunk)[i] = data->min + i
			* (data->max - data->min) / data->nb_chunk;
		printf("| %d ", (data->chunk)[i]);
		i++;
	}
	printf("|\n");
	return (0);
}

static size_t	create_test(t_data *data)
{
	data->test_result = malloc((data->nb_test) * sizeof(int));
	if (data->test_result == NULL)
		return (1);
	return (0);
}

//VERIFIER LES SCAN

static size_t	scan_from_top(t_stack *a, t_data *data)
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

static size_t	scan_from_bot(t_stack *a, t_data *data)
{
	size_t	index;

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


static void	chosse_key(t_stack *a, t_data *data)
{	
	if (data->bot_key_index + 1 < (a->index - data->top_key_index) - 1)
	{
		data->key = data->bot_key;
		data->key_index = data->bot_key_index;
		data->dir_rot = -1;
		data->nb_rot = data->bot_key_index + 1;
	}
	else
	{
		data->key = data->top_key;
		data->key_index = data->top_key_index;
		data->dir_rot = 1;
		data->nb_rot = (a->index - data->top_key_index) - 1;
	}
}

void	get_rot_dir(t_stack *b, t_data *data)
{	
	if (b->index == 0)
	{
		data->dir_rot = 1;
		data->nb_rot = 0 ;
		return ;
	}
	if (data->index_to_place_key > b->index / 2)
	{
		data->dir_rot = 1;
		data->nb_rot = b->index - data->index_to_place_key;
	}
	else
	{
		data->dir_rot = -1;
		data->nb_rot = data->index_to_place_key;
	}
}

void	get_rot_min(t_stack *a, t_data *data)
{	
	if (a->index == 0)
	{
		data->dir_rot = 1;
		data->nb_rot = 0 ;
		return ;
	}
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

static void	find_insert_index(t_stack *b, t_data *data)
{	
	size_t	i;

	//SI PLUS PETIT QUE LE MIN 

	//SI PLUS GRAND QUE LE MAX

	//SINON

	if (b->index == 0)
	{
		data->index_to_place_key = 0;
		return ;
	}
	i = 0;
	while (i + 1 < b->index)
	{
		if (b->data[i] < data->key && data->key < b->data[i + 1])
			break ;
		i++;
	}
	data->index_to_place_key = i;
}

static void	insert_key(t_stack *b, t_data *data)
{	
	find_insert_index(b, data);
	printf("key:%d to %zu\n",data->key, data->index_to_place_key);	
	get_rot_dir(b, data);
	rot_b(b, data);
}

static void	min_to_top(t_stack *a, t_data *data)
{
	get_min(a, data);
	get_rot_min(a, data);
	rot_a(a, data);
}

void	resolve_one_test(t_stack *a, t_stack *b, t_data *data)
{	
	data->current_chunk = 0;				
	while (a->index >= 0 && data->current_chunk <= data->nb_chunk)
	{		
		if (scan_from_top(a, data) || scan_from_bot(a, data))
		{
			printf("CHANGED:%zu\n",data->current_chunk);
			data->current_chunk += 1;
		}
		else
		{	
			chosse_key(a, data);
			printf("key:%d\n",data->key);	
			rot_a(a, data);
			insert_key(b, data);
			pb(a, b, data);
			print_list(a, b);
			data->nb_moove++;
		}
	}
	push_all_b(a, b, data);
	min_to_top(a, data);
}

void	resolve_push_swap(t_stack *a, t_stack *b, t_data *data)
{
	size_t	current_test;

	data->chunk = NULL;
	if (create_test(data))
		return ;
	current_test = 0;
	while (current_test < data->nb_test)
	{	
		data->nb_chunk = (a->index / 10) + 2;
		if(cut_chunk(data, a))
			return ;
		// print_list(a, b);
		data->nb_moove = 0;
		resolve_one_test(a, b, data);
		print_list(a, b);	
		printf("NB_CHUNK:%zu, MOOVE:%zu\n",data->nb_chunk,data->nb_moove);
		(data->test_result)[current_test] = data->nb_moove;
		current_test++;
	}
	//Choisir le nombre total de test a faire en fonction de la taille de la liste

	//Choisir le nombre de chunk a faire en foncion de la taille de la liste

	//On refait le test avec la bonne valeur de nb chunk
	return ;
}



// make && ./push_swap 2602 1769 2803 1254 2681 393 1546
// https://www.random.org/integer-sets/?sets=1&num=100&min=1&max=3000&seqnos=on&order=index&format=html&rnd=new