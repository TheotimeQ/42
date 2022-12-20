/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:10:17 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/20 11:42:39 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_ms(t_env *e)
{	
	struct timeval		current_time;
	long long int		ms;

	gettimeofday(&current_time, NULL);
	ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	ms -= e->start_ms;
	return ((long)ms);
}

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

void	phil_eat(t_env *e, t_phil *phil)
{
	int				id_left;
	int				id_right;
  
	//Take left fork
	if (phil->id == 0)
		id_left = e->nb_phil - 1;
	else
		id_left = phil->id - 1;
	pthread_mutex_lock(&(e->all_fork[id_left]));
	
	pthread_mutex_lock(&(e->print_mutex));
	printf("%ld %d has taken LEFT fork n°%d \n", get_ms(e), phil->id + 1, id_left + 1);
	pthread_mutex_unlock(&(e->print_mutex));

	//Take right fork
	if (phil->id == e->nb_phil - 1)
		id_right = 0;
	else
		id_right = phil->id + 1;
	pthread_mutex_lock(&(e->all_fork[id_right]));

	pthread_mutex_lock(&(e->print_mutex));
	printf("%ld %d has taken RIGHT fork n°%d \n", get_ms(e), phil->id + 1, id_right + 1);
	pthread_mutex_unlock(&(e->print_mutex));

	//Eat
	pthread_mutex_lock(&(e->print_mutex));
	printf("%ld %d is eating\n", get_ms(e), phil->id + 1);
	pthread_mutex_unlock(&(e->print_mutex));
	usleep(e->time_eat * 1000);

	//Rends les fourchette
	pthread_mutex_unlock(&(e->all_fork[id_left]));
	pthread_mutex_unlock(&(e->all_fork[id_right]));

	//Update last eat
	phil->last_eat = get_ms(e);
}

void	phil_sleep(t_env *e, t_phil *phil)
{
	pthread_mutex_lock(&(e->print_mutex));
	printf("%ld %d is sleeping\n", get_ms(e), phil->id + 1);
	pthread_mutex_unlock(&(e->print_mutex));
	usleep(e->time_sleep * 1000);	
}

void	phil_think(t_env *e, t_phil *phil)
{
	pthread_mutex_lock(&(e->print_mutex));
	printf("%ld %d is thinking\n", get_ms(e), phil->id + 1);
	pthread_mutex_unlock(&(e->print_mutex));
	usleep(e->time_sleep * 1000); //Combien de temps à pensser ?		
}

void    *philo_thread(void *ph)
{
	t_phil				*phil;
	t_env				*e;

	phil = (t_phil *)ph;
	e = (t_env *)phil->e;

	pthread_mutex_lock(&(e->print_mutex));
	printf("%ld %d started\n", get_ms(e), phil->id + 1);
	pthread_mutex_unlock(&(e->print_mutex));

	phil->last_eat = get_ms(e);

	while (phil->stop == 0 && phil->alive == 1)
	{	
		if (get_ms(e) - phil->last_eat > e->time_die)
		{
			phil->alive = 0;
			break;
		}
		phil_eat(e, phil);
		phil_sleep(e, phil);
		phil_think(e, phil);
	}

	if (phil->alive == 0)
	{	
		pthread_mutex_lock(&(e->print_mutex));
		printf("%ld %d have died\n", get_ms(e), phil->id + 1);
		pthread_mutex_unlock(&(e->print_mutex));
	}
	pthread_mutex_lock(&(e->print_mutex));
	printf("%ld %d ------------- STOPPPPPPEDDDDD -----------\n", get_ms(e), phil->id + 1);
	pthread_mutex_unlock(&(e->print_mutex));	
	return (NULL);
}

static t_phil	*init_philo(t_env *e, int id)
{	
	t_phil				*philo;

	philo = malloc(sizeof(t_phil));
	if (philo == NULL)
	{
		printf("Error: malloc philo\n");
		free_exit(e, 1);
	}
	if (pthread_mutex_init(&(e->all_fork[id]), NULL) != 0)
	{
		printf("Error: init mutex fork\n"); //printf
		free_exit(e, 1);
	}
	philo->e = (void *)e;
	philo->id = id;
	philo->alive = 1;
	philo->stop = 0;
	philo->last_eat = -1;
	return (philo);
}

void	create_philos(t_env *e)
{
	int	id;

	id = 0;
	while (id < e->nb_phil)
	{	
		e->all_phil[id] = init_philo(e, id);
		if (pthread_create(&(e->all_phil[id]->thread), NULL, philo_thread, e->all_phil[id]) != 0)
		{
			printf("Error: init thread philo\n"); //printf
			free_exit(e, 1);
		}	
		id++;
	}
}
