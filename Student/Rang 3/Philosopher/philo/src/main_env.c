/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:43:50 by tquere            #+#    #+#             */
/*   Updated: 2022/12/21 15:06:07 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_mutex_env(t_env *e)
{
	if (pthread_mutex_init(&(e->print_mutex), NULL) != 0)
	{	
		write(2, "Error: mutex\n", 13);
		free_exit(e, 1);
	}
	if (pthread_mutex_init(&(e->stop_mutex), NULL) != 0)
	{	
		write(2, "Error: mutex\n", 13);
		free_exit(e, 1);
	}
	if (pthread_mutex_init(&(e->mutex_eat), NULL) != 0)
	{	
		write(2, "Error: mutex\n", 13);
		free_exit(e, 1);
	}
}

static void	init_all_fork(t_env *e)
{
	int					id;

	e->forks_mutex = malloc(sizeof(pthread_mutex_t) * e->nb_phil);
	if (e->forks_mutex == NULL)
	{
		write(2, "Error: malloc\n", 14);
		free_exit(e, 1);
	}
	e->eats = malloc(sizeof(int) * e->nb_phil);
	e->forks = malloc(sizeof(int) * e->nb_phil);
	if (e->eats == NULL || e->forks == NULL)
	{
		write(2, "Error: malloc\n", 14);
		free_exit(e, 1);
	}
	id = 0;
	while (id < e->nb_phil)
	{
		e->eats[id] = 0;
		e->forks[id++] = 1;
	}
}

static void	init_all_phil(t_env *e)
{
	int					id;

	e->all_phil = malloc(sizeof(t_phil *) * e->nb_phil);
	if (e->all_phil == NULL)
	{
		write(2, "Error: malloc list philo\n", 25);
		free_exit(e, 1);
	}
	id = 0;
	while (id < e->nb_phil)
		e->all_phil[id++] = NULL;
	e->thread = malloc(sizeof(pthread_t) * e->nb_phil);
	if (e->thread == NULL)
	{
		write(2, "Error: malloc thread list\n", 26);
		free_exit(e, 1);
	}
}

t_env	*init_env(void)
{
	t_env				*e;
	struct timeval		current_time;

	e = malloc(sizeof(t_env));
	if (e == NULL)
	{
		write(2, "Error: malloc env\n", 18);
		exit(1);
	}
	e->eats = NULL;
	e->thread = NULL;
	e->forks = NULL;
	e->all_phil = NULL;
	e->nb_eat = -1;
	e->nb_phil = -1;
	e->time_die = -1;
	e->time_eat = -1;
	e->time_sleep = -1;
	e->nb_eat = -1;
	e->stop = 0;
	gettimeofday(&current_time, NULL);
	e->start_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	init_mutex_env(e);
	return (e);
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
	init_all_fork(e);
	init_all_phil(e);
	e->time_die = check_nb(e, ft_atoi(ft_isnum(argv[2])));
	e->time_eat = check_nb(e, ft_atoi(ft_isnum(argv[3])));
	e->time_sleep = check_nb(e, ft_atoi(ft_isnum(argv[4])));
	if (argc == 6)
		e->nb_eat = check_nb(e, ft_atoi(ft_isnum(argv[5])));
}
