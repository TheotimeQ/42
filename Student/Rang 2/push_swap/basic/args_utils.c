/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:38:44 by tquere            #+#    #+#             */
/*   Updated: 2022/12/01 11:32:52 by zelinsta         ###   ########.fr       */
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

static void	get_from_str(t_stack *a, char **argv, int nb_value)
{
	int		i;

	argv = ft_split(argv[1], ' ');
	i = nb_value - 1;
	while (i >= 0)
	{
		if (check_nb(argv[i]))
		{
			free_tab(argv, nb_value);
			ft_putstr_fd("Error\n", 2);
		}
		push_stack(a, ft_atoi(argv[i--]));
	}
	free_tab(argv, nb_value);
}

static void	get_from_list(t_stack *a, char **argv, int nb_value)
{
	int	i;

	i = nb_value - 1;
	while (i > 0)
	{
		if (check_nb(argv[i]))
		{
			free_tab(argv, nb_value);
			ft_putstr_fd("Error\n", 2);
		}
		push_stack(a, ft_atoi(argv[i--]));
	}
}

int	init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	nb_value;

	nb_value = get_nb_args(argc, argv);
	b->index = 0;
	a->index = 0;
	a->data = malloc(sizeof(int) * nb_value);
	if (a->data == NULL)
		return (-1);
	b->data = malloc(sizeof(int) * nb_value);
	if (b->data == NULL)
		return (-1);
	if (argc == 2)
		get_from_str(a, argv, nb_value);
	else
		get_from_list(a, argv, nb_value);
	return (nb_value);
}
