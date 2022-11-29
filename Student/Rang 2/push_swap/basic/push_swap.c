/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:55:20 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/27 16:46:00 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a, t_stack *b)
{	
	if (a != NULL)
	{
		free(a->data);
		free(a);
	}
	if (b != NULL)
	{
		free(b->data);
		free(b);
	}
}

static int	check_error(int argc, char **argv, t_stack *a, t_stack *b)
{	
	int		nb_value;

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

	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = malloc(sizeof(t_stack));
	if (a == NULL)
		return (1);
	b = malloc(sizeof(t_stack));
	if (b == NULL)
	{
		free(a);
		return (1);
	}
	if (check_error(argc, argv, a, b))
		return (1);
	resolve_push_swap(a, b);
	free_stack(a, b);
	return (0);
}
