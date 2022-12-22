/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:43:50 by tquere            #+#    #+#             */
/*   Updated: 2022/12/21 20:28:51 by zelinsta         ###   ########.fr       */
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
	if (pthread_mutex_init(&(e->eat_mutex), NULL) != 0)
	{	
		write(2, "Error: mutex\n", 13);
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
	e->last_eats = NULL;
	e->eats = NULL;
	e->thread = NULL;
	e->forks = NULL;
	e->all_phil = NULL;
	e->nb_eat = -1;
	e->nb_phil = -1;
	e->time_die = -1;
	e->time_eat = -1;
	e->time_sleep = -1;
	gettimeofday(&current_time, NULL);
	e->start_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	init_mutex_env(e);
	return (e);
}
