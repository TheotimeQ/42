/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:55:20 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/01 12:06:57 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{	
	if (a != NULL)
	{	
		if (a->data != NULL)
			free(a->data);
		free(a);
	}
}

static int	check_error(int argc, char **argv, t_data *data)
{	
	int		nb_value;

	nb_value = init_stack(data->a, data->b, argc, argv);
	if (nb_value < 0)
		leave(data);
	if (ft_is_double((data->a)->data, nb_value))
	{
		ft_putstr_fd("Error\n", 2);
		leave(data);
	}
	return (0);
}

void	leave(t_data *data)
{
	free_stack(data->a);
	free_stack(data->b);
	free(data->chunk);
	free(data);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_data		*data;

	if (argc <= 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (a == NULL || b == NULL)
		leave(data);
	data->a = a;
	data->b = b;
	data->nb_test = NB_TEST;
	data->chunk = malloc((data->nb_test + 1) * sizeof(int));
	if(!data->chunk)
		leave(data);
	if (check_error(argc, argv, data))
		leave(data);
	resolve_push_swap(a, b, data);
	leave(data);
	return (0);
}
