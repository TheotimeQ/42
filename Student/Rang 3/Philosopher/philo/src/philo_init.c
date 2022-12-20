/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:10:17 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/20 19:03:05 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_env *e)
{
	int	id;	

	if (e->all_phil)
	{
		id = 0;
		while (id < e->nb_phil)
		{	
			free(e->all_phil[id]);
			id++;
		}
		free(e->all_phil);
	}
}

t_phil	**init_all_phil(t_env *e)
{
	t_phil				**all_phil;
	int					id;

	all_phil = malloc(sizeof(t_phil *) * e->nb_phil);
	if (all_phil == NULL)
	{
		write(2, "Error: malloc list philo\n", 25);
		free_exit(e, 1);
	}
	id = 0;
	while (id < e->nb_phil)
		all_phil[id++] = NULL;
	return (all_phil);
}

static t_phil	*init_one_philo(t_env *e, int id)
{	
	t_phil				*philo;

	philo = malloc(sizeof(t_phil));
	if (philo == NULL)
	{	
		write(2, "Error: malloc philo\n", 20);
		free_exit(e, 1);
	}
	philo->e = (void *)e;
	philo->id = id;
	philo->last_eat = 0;
	philo->nb_eat = 1;
	philo->stop = 0;
	return (philo);
}

void	create_philos(t_env *e)
{
	int	id;

	id = 0;
	while (id < e->nb_phil)
	{	
		e->all_phil[id] = init_one_philo(e, id);
		if (pthread_mutex_init(&(e->all_phil[id]->mutex_fork), NULL) != 0
			|| pthread_mutex_init(&(e->all_phil[id]->mutex_nb_eat), NULL) != 0
			|| pthread_mutex_init(&(e->all_phil[id]->mutex_stop), NULL) != 0)
		{	
			write(2, "Error: init mutex philo\n", 24);
			free_exit(e, 1);
		}
		usleep(200);
		if (pthread_create(&(e->all_phil[id]->thread),
				NULL, philo_thread, e->all_phil[id]) != 0)
		{	
			write(2, "Error: init thread philo\n", 25);
			free_exit(e, 1);
		}	
		id++;
	}
}
