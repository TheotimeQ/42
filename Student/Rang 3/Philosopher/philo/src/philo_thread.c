/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:10:55 by tquere            #+#    #+#             */
/*   Updated: 2022/12/20 19:02:38 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	phil_eat(t_env *e, t_phil *phil)
{
	int				id_left;
	int				id_right;

	id_left = phil->id;
	id_right = phil->id + 1 % e->nb_phil;
	pthread_mutex_lock(&((e->all_phil)[id_left]->mutex_fork));
	print_lock(phil->id, get_ms(e), "has taken a fork", e);
	pthread_mutex_lock(&((e->all_phil)[id_right]->mutex_fork));
	print_lock(phil->id, get_ms(e), "has taken a fork", e);
	print_lock(phil->id, get_ms(e), "is eating", e);
	usleep(e->time_eat * 1000);
	pthread_mutex_unlock(&((e->all_phil)[id_left]->mutex_fork));
	pthread_mutex_unlock(&((e->all_phil)[id_right]->mutex_fork));
}

void    *philo_thread(void *ph)
{
	t_phil				*phil;
	t_env				*e;

	phil = (t_phil *)ph;
	e = (t_env *)phil->e;
	pthread_mutex_lock(&(phil->mutex_stop));
	while (phil->stop == 0)
	{	
		pthread_mutex_unlock(&(phil->mutex_stop));
		check_alive(e, phil);
		phil_eat(e, phil);
		phil->last_eat = get_ms(e);
		pthread_mutex_lock(&(phil->mutex_nb_eat));
		phil->nb_eat++;
		pthread_mutex_unlock(&(phil->mutex_nb_eat));
		check_alive(e, phil);
		print_lock(phil->id, get_ms(e), "is sleeping", e);
		sleep_stop_die(e->time_sleep, e, phil);
		check_alive(e, phil);
		print_lock(phil->id, get_ms(e), "is thinking", e);
	}
	print_lock(phil->id, get_ms(e), "-----> ENDED", e);
	return (NULL);
}
