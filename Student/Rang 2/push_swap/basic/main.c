/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:55:20 by zelinsta          #+#    #+#             */
/*   Updated: 2022/11/24 17:57:02 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void free_stack(t_stack *a, t_stack *b)
{
	free(a->data);
	free(b->data);
	free(a);
	free(b);
}

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
	int	i;

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
	int	i;

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

static int	init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	nb_value;

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

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			nb_value;

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
	nb_value = init_stack(a, b, argc, argv);
	if (nb_value < 0)
	{
		free_stack(a, b);
		return (1);
	}
	if (ft_is_double(a->data, nb_value))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(a, b);
		return (1);
	}
	resolve_push_swap(a, b);
	free_stack(a, b);
	return (0);
}