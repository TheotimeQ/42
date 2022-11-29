/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:55:20 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/29 19:08:55 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a, t_stack *b)
{	
	if (a != NULL)
	{	
		if (a->data != NULL)
			free(a->data);
		free(a);
	}
	if (b != NULL)
	{	
		if (b->data != NULL)
			free(b->data);
		free(b);
	}
}

static void	free_data(t_data *data)
{
	if (data)
	{
		if (data->chunk)
			free(data->chunk);
		free(data);
	}
}

static size_t	check_error(int argc, char **argv, t_stack *a, t_stack *b)
{	
	size_t		nb_value;

	nb_value = init_stack(a, b, argc, argv);
	if (nb_value < 0)
	{
		free_stack(a, b);
		exit(1);
	}
	if (ft_is_double(a->data, nb_value))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(a, b);
		exit(1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_data		*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	data->nb_test = 1;
	data->print = 0;
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		free_data(data);
		return (1);
	}
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (a == NULL || b == NULL)
	{	
		free_stack(a, b);
		free_data(data);
		return (1);
	}
	if (check_error(argc, argv, a, b))
		return (1);
	resolve_push_swap(a, b, data);
	free_stack(a, b);
	free_data(data);
	return (0);
}
