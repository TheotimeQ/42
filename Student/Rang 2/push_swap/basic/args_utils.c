/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:38:44 by tquere            #+#    #+#             */
/*   Updated: 2022/12/04 13:38:11 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_nb(char *nb)
{	
	if (ft_isnum(nb) == 0)
		return (1);
	if (ft_atoi(nb) < INT32_MIN || INT32_MAX < ft_atoi(nb))
		return (1);
	return (0);
}

static int	get_nb_args(int argc, char **argv)
{
	int	i;
	int	nb_args;

	nb_args = argc;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		nb_args = 0;
		i = 0;
		while (argv[i++])
			nb_args++;
		free_tab(argv, nb_args);
		return (nb_args);
	}
	return (nb_args);
}

static int	get_from_str(t_stack *a, char **argv, int nb_value)
{
	int		i;

	argv = ft_split(argv[1], ' ');
	i = nb_value - 1;
	while (i >= 0)
	{
		if (check_nb(argv[i]))
		{
			free_tab(argv, nb_value);
			return (-1);
		}
		push_stack(a, ft_atoi(argv[i--]));
	}
	free_tab(argv, nb_value);
	return (nb_value + 1);
}

static int	get_from_list(t_stack *a, char **argv, int nb_value)
{
	int	i;

	i = nb_value - 1;
	while (i > 0)
	{
		if (check_nb(argv[i]))
			return (-1);
		push_stack(a, ft_atoi(argv[i--]));
	}
	return (nb_value);
}

int	init_stack(t_data *data, int argc, char **argv)
{
	int	nb_value;

	nb_value = get_nb_args(argc, argv);
	data->b->index = 0;
	data->a->index = 0;
	data->a->data = malloc(sizeof(int) * nb_value);
	if (data->a->data == NULL)
		leave(data);
	data->sorted_a->data = malloc(sizeof(int) * nb_value);
	if (data->sorted_a->data == NULL)
		leave(data);
	data->b->data = malloc(sizeof(int) * nb_value);
	if (data->b->data == NULL)
		leave(data);
	if (argc == 2)
		nb_value = get_from_str(data->a, argv, nb_value);
	else
		nb_value = get_from_list(data->a, argv, nb_value);
	return (nb_value);
}
