/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:10:55 by tquere            #+#    #+#             */
/*   Updated: 2022/12/21 18:30:17 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_stop(t_phil *phil)
{
	pthread_mutex_lock(&(phil->stop_mutex));
	if (phil->stop == 1)
	{
		pthread_mutex_unlock(&(phil->stop_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(phil->stop_mutex));
	return (0);
}

static int	get_fork(t_env *e, t_phil *phil, int id_left, int id_right)
{
	pthread_mutex_lock(&(e->forks[id_left]));
	print_lock(phil->id, get_ms(e), "has taken a fork", e);
	if (check_stop(phil))
		return (1);
	pthread_mutex_lock(&(e->forks[id_right]));
	print_lock(phil->id, get_ms(e), "has taken a fork", e);
	if (check_stop(phil))
		return (1);
	return (0);
}

static int	phil_eat(t_env *e, t_phil *phil)
{
	int				id_left;
	int				id_right;

	id_left = phil->id - 1;
	id_right = phil->id + 1;
	if (phil->id == 0)
		id_left = e->nb_phil - 1;
	if (phil->id == e->nb_phil - 1)
		id_right = 0;
	if (get_fork(e, phil, id_left, id_right))
		return (1);
	pthread_mutex_lock(&(e->eat_mutex));
	e->eats[phil->id] = e->eats[phil->id] + 1;
	e->last_eats[phil->id] = get_ms(e);
	pthread_mutex_unlock(&(e->eat_mutex));
	print_lock(phil->id, get_ms(e), "is eating", e);
	usleep(e->time_eat * 1000);
	pthread_mutex_unlock(&(e->forks[id_left]));
	pthread_mutex_unlock(&(e->forks[id_right]));
	return (0);
}

void	*philo_thread(void *ph)
{
	t_phil				*phil;
	t_env				*e;

	phil = (t_phil *)ph;
	e = (t_env *)phil->e;
	while (check_stop(phil) == 0)
	{	
		if (phil_eat(e, phil))
			return (NULL);
		// print_eat(e);
		if (check_stop(phil))
			return (NULL);
		print_lock(phil->id, get_ms(e), "is sleeping", e);
		if (check_stop(phil))
			return (NULL);
		usleep(e->time_sleep * 1000);
		if (check_stop(phil))
			return (NULL);
		print_lock(phil->id, get_ms(e), "is thinking", e);
	}
	return (NULL);
}
