/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:38:21 by tquere            #+#    #+#             */
/*   Updated: 2022/12/04 13:55:51 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{	
	free(stack->data);
	free(stack);
}

void	leave(t_data *data)
{	
	free_stack(data->a);
	free_stack(data->b);
	free_stack(data->sorted_a);
	free(data->chunk);
	free(data->saved_chunk);
	free(data);
	exit(0);
}

static int	check_error(int argc, char **argv, t_data *data)
{	
	int		nb_value;

	nb_value = init_stack(data, argc, argv);
	if (nb_value < 0)
	{
		ft_putstr_fd("Error\n", 2);
		leave(data);
	}
	if (ft_is_double((data->a)->data, nb_value))
	{
		ft_putstr_fd("Error\n", 2);
		leave(data);
	}
	return (0);
}

static t_data	*init_stack_error(void)
{	
	t_data		*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		exit(0);
	data->a = malloc(sizeof(t_stack));
	data->b = malloc(sizeof(t_stack));
	data->sorted_a = malloc(sizeof(t_stack));
	if (!data->a || !data->b || !data->sorted_a)
	{
		free(data);
		free(data->a);
		free(data->b);
		free(data->sorted_a);
		exit(0);
	}
	return (data);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc <= 1)
		return (1);
	data = init_stack_error();
	data->a->data = NULL;
	data->b->data = NULL;
	data->sorted_a->data = NULL;
	data->nb_test = NB_TEST;
	data->chunk = malloc((data->nb_test + 1) * sizeof(int));
	data->saved_chunk = malloc((data->nb_test + 1) * sizeof(int));
	if (!data->chunk || !data->saved_chunk || check_error(argc, argv, data))
		leave(data);
	resolve_push_swap(data->a, data->b, data);
	leave(data);
}
