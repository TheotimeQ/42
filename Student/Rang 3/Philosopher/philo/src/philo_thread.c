/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:10:55 by tquere            #+#    #+#             */
/*   Updated: 2022/12/21 14:22:53 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int_fast32_t	take_fork(t_env *e, t_phil *phil, int id_left, int id_right)
{
	pthread_mutex_lock(&((e->forks)[id_left]));
	print_lock(phil->id, get_ms(e), "has taken a fork", e);
	if (check_alive(e, phil) == 0)
	{
		pthread_mutex_unlock(&((e->forks)[id_left]));
		return (1);
	}
	pthread_mutex_lock(&((e->forks)[id_right]));
	print_lock(phil->id, get_ms(e), "has taken a fork", e);
	if (check_alive(e, phil) == 0)
	{	
		pthread_mutex_unlock(&((e->forks)[id_left]));
		pthread_mutex_unlock(&((e->forks)[id_right]));
		return (1);
	}
	return (0);
}

static void	phil_eat(t_env *e, t_phil *phil)
{
	int				id_left;
	int				id_right;

	id_left = phil->id - 1;
	id_right = phil->id + 1;
	if (phil->id == 0)
		id_left = e->nb_phil - 1;
	if (phil->id == e->nb_phil - 1)
		id_right = 0;
	if (take_fork(e, phil, id_left, id_right))
		return ;
	phil->last_eat = get_ms(e);
	pthread_mutex_lock(&(e->mutex_eat));
	e->eats[phil->id]++;
	pthread_mutex_unlock(&(e->mutex_eat));
	print_lock(phil->id, get_ms(e), "is eating", e);
	usleep(e->time_eat * 1000);
	pthread_mutex_unlock(&((e->forks)[id_left]));
	pthread_mutex_unlock(&((e->forks)[id_right]));
}

static int	special_case(t_env *e, t_phil *phil)
{
	if (e->nb_phil == 1 || e->nb_phil == 2)
	{
		usleep(e->time_die * 1000);
		print_lock(phil->id, get_ms(e), "have died", e);
		free(e->all_phil[phil->id]);
		e->all_phil[phil->id] = NULL;
		return (1);
	}
	return (0);
}

void	*philo_thread(void *ph)
{
	t_phil				*phil;
	t_env				*e;

	phil = (t_phil *)ph;
	e = (t_env *)phil->e;
	if (special_case(e, phil))
		return (NULL);
	while (1)
	{	
		if (check_alive(e, phil) == 0)
			break ;
		phil_eat(e, phil);
		if (e->nb_eat > 0)
			check_eat_enough(e);
		if (check_alive(e, phil) == 0)
			break ;
		print_lock(phil->id, get_ms(e), "is sleeping", e);
		sleep_stop_die(e->time_sleep, e, phil);
		print_lock(phil->id, get_ms(e), "is thinking", e);
	}
	return (NULL);
}
