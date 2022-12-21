/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:10:17 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/21 14:20:14 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_phil	*init_one_philo(t_env *e, int id)
{	
	t_phil				*philo;

	philo = malloc(sizeof(t_phil) * 1 + 5000);
	if (philo == NULL)
	{	
		write(2, "Error: malloc philo\n", 20);
		free_exit(e, 1);
	}
	philo->e = (void *)e;
	philo->id = id;
	philo->last_eat = 0;
	return (philo);
}

void	create_forks(t_env *e)
{
	int	id;

	id = 0;
	while (id < e->nb_phil)
	{	
		if (pthread_mutex_init(&((e->forks)[id]), NULL) != 0)
		{	
			write(2, "Error: init fork\n", 17);
			free_exit(e, 1);
		}
		id++;
	}
}

void	create_philos(t_env *e)
{
	int	id;

	id = 0;
	while (id < e->nb_phil)
	{	
		e->all_phil[id] = init_one_philo(e, id);
		if (pthread_create(&(e->thread[id]),
				NULL, philo_thread, e->all_phil[id]) != 0)
		{	
			write(2, "Error: init thread philo\n", 25);
			free_exit(e, 1);
		}	
		usleep(200);
		id++;
	}
}
