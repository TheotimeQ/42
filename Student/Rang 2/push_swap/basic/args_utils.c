/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:38:44 by tquere            #+#    #+#             */
/*   Updated: 2022/11/29 12:19:24 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	check_nb(char *nb)
{
	if (ft_isnum(nb) == 0)
		return (1);
	if (ft_atoi(nb) < INT32_MIN || INT32_MAX < ft_atoi(nb))
		return (1);
	return (0);
}

static size_t	get_nb_args(int argc, char **argv)
{
	size_t	i;

	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
		i = 0;
		while (argv[i++])
			argc++;
		free_tab(argv, argc);
		return (argc);
	}
	return (argc);
}

static void	get_from_str(t_stack *a, t_stack *b, char **argv, int nb_value)
{
	size_t	i;

	argv = ft_split(argv[1], ' ');
	i = nb_value - 1;
	while (i >= 0)
	{
		if (check_nb(argv[i]))
		{
			free_stack(a, b);
			free_tab(argv, nb_value);
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		push_stack(a, ft_atoi(argv[i--]));
	}
	free_tab(argv, nb_value);
}

static void	get_from_list(t_stack *a, t_stack *b, char **argv, int nb_value)
{
	size_t	i;

	i = nb_value - 1;
	while (i > 0)
	{
		if (check_nb(argv[i]))
		{
			free_stack(a, b);
			free_tab(argv, nb_value);
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		push_stack(a, ft_atoi(argv[i--]));
	}
}

size_t	init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	size_t	nb_value;

	nb_value = get_nb_args(argc, argv);
	b->index = 0;
	a->index = 0;
	a->data = malloc(sizeof(int) * nb_value);
	if (a->data == NULL)
	{
		free(b);
		free(a);
		exit(1);
	}
	b->data = malloc(sizeof(int) * nb_value);
	if (b->data == NULL)
	{
		free(a);
		free(b);
		free(a->data);
		exit(1);
	}
	if (argc == 2)
		get_from_str(a, b, argv, nb_value);
	else
		get_from_list(a, b, argv, nb_value);
	return (nb_value);
}
