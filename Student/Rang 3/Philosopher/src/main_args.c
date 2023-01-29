/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:43:50 by tquere            #+#    #+#             */
/*   Updated: 2022/12/22 10:01:36 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_all_phil(t_env *e)
{
	int					id;

	e->all_phil = malloc(sizeof(t_phil *) * e->nb_phil);
	if (e->all_phil == NULL)
	{
		write(2, "Error: malloc\n", 14);
		free_exit(e, 1);
	}
	e->thread = malloc(sizeof(pthread_t) * e->nb_phil);
	if (e->thread == NULL)
	{
		write(2, "Error: malloc\n", 14);
		free_exit(e, 1);
	}
	e->forks = malloc(sizeof(pthread_mutex_t) * e->nb_phil);
	if (e->forks == NULL)
	{
		write(2, "Error: malloc\n", 14);
		free_exit(e, 1);
	}
	id = 0;
	while (id < e->nb_phil)
		e->all_phil[id++] = NULL;
}

static void	init_all_fork(t_env *e)
{
	int		id;

	e->eats = malloc(sizeof(int) * (e->nb_phil * 2));
	e->last_eats = malloc(sizeof(int) * (e->nb_phil * 2));
	if (e->eats == NULL || e->last_eats == NULL)
	{
		write(2, "Error: malloc\n", 14);
		free_exit(e, 1);
	}
	id = 0;
	while (id < e->nb_phil)
	{	
		if (pthread_mutex_init(&(e->forks[id]), NULL) != 0)
		{	
			write(2, "Error: init fork\n", 17);
			free_exit(e, 1);
		}
		e->eats[id] = 0;
		e->last_eats[id] = 0;
		id++;
	}
}

void	check_args(t_env *e, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{	
		write(2, "Wrong use : ./philo number_of_philosophers time_to_die", 54);
		write(2, " time_to_eat time_to_sleep [number_of_times_each_philos", 55);
		write(2, "opher_must_eat]\n", 16);
		free_exit(e, 1);
	}
	e->nb_phil = check_nb(e, ft_atoi(ft_isnum(argv[1])));
	e->time_die = check_nb(e, ft_atoi(ft_isnum(argv[2])));
	e->time_eat = check_nb(e, ft_atoi(ft_isnum(argv[3])));
	e->time_sleep = check_nb(e, ft_atoi(ft_isnum(argv[4])));
	if (argc == 6)
		e->nb_eat = check_nb(e, ft_atoi(ft_isnum(argv[5])));
	if (e->nb_eat == 0)
	{
		write(2, "Error: wrong input\n", 19);
		free_exit(e, 1);
	}
	init_all_phil(e);
	init_all_fork(e);
}
