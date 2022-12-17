/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:10:17 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/17 15:58:37 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_env *e)
{
	int	id;

	id = 0;
	while (id < e->nb_phil)
	{
		free(e->all_phil[id]);
		id++;
	}
	free(e->all_phil);
}

// number_of_philosophers 
// time_to_die 
// time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat] optionnel

void    *philo_thread(void *env)
{
	t_env	*e;
	t_phil	*phil;

	e = (t_env *)env;
	phil = e->all_phil[e->cur_id];

	pthread_mutex_lock(&(e->print_mutex));
	printf("%d , started at %ld ms\n",phil->id, phil->last_eat);
	pthread_mutex_unlock(&(e->print_mutex));

	while (phil->stop == 0 && phil->alive == 1)
	{
		//Check si il doit mourir

		//Si mort on stop le thread

		//Si stop on stop le thread
		
		// Verifis si les deux fourchettes sont unlock

		//Si c'est le cas manges

			//une fois fini de manger , envoi 

		//Une fois manger se repose

		//Une fois reposé medite

		//Une fois medité , mange
	}

	pthread_mutex_lock(&(e->print_mutex));
	printf("%d , Stopping at %ld ms\n",phil->id, phil->last_eat);
	pthread_mutex_unlock(&(e->print_mutex));
	
	return (NULL);
}

static t_phil	*init_philo(t_env *e, int id)
{
	t_phil			*philo;

	philo = malloc(sizeof(t_phil));
	if (philo == NULL)
	{
		printf("Error: malloc philo\n");
		free_exit(e, 1);
	}
	if (pthread_mutex_init(&(philo->fork), NULL) != 0)
	{
		printf("Error: init mutex philo\n"); //printf
		free_exit(e, 1);
	}
	philo->id = id;
	philo->alive = 1;
	philo->stop = 0;
	philo->last_eat = 0;		//Get temps
    philo->state = 0; 			//State

	// int						alive;
	// int						id;
	// int						nb_eat;
	// int						state;
	// long int				last_eat;
	// int						stop;
	// pthread_mutex_t			fork;
	// pthread_t				thread;
	
	return (philo);
}

void	create_philos(t_env *e)
{
	int	id;

	id = 0;
	while (id < e->nb_phil)
	{
		e->cur_id = id;
		e->all_phil[id] = init_philo(e, id);
		if (pthread_create(&(e->all_phil[id]->thread), NULL, philo_thread, e) != 0)
		{
			printf("Error: init thread philo\n"); //printf
			free_exit(e, 1);
		}	
		id++;
	}
}
