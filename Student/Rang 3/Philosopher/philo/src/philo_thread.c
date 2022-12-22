/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:10:55 by tquere            #+#    #+#             */
/*   Updated: 2022/12/21 20:46:58 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	pthread_mutex_lock(&(e->forks[id_left]));
	print_lock(phil->id, get_ms(e), "has taken a fork", e);
	pthread_mutex_lock(&(e->forks[id_right]));
	print_lock(phil->id, get_ms(e), "has taken a fork", e);
	pthread_mutex_lock(&(e->eat_mutex));
	e->eats[phil->id] = e->eats[phil->id] + 1;
	e->last_eats[phil->id] = get_ms(e);
	pthread_mutex_unlock(&(e->eat_mutex));
	print_lock(phil->id, get_ms(e), "is eating", e);
	usleep(e->time_eat * 1000);
	pthread_mutex_unlock(&(e->forks[id_right]));
	pthread_mutex_unlock(&(e->forks[id_left]));
}

void	*philo_thread(void *ph)
{
	t_phil				*phil;
	t_env				*e;

	phil = (t_phil *)ph;
	e = (t_env *)phil->e;
	while (1)
	{	
		phil_eat(e, phil);
		print_lock(phil->id, get_ms(e), "is sleeping", e);
		usleep(e->time_sleep * 1000);
		print_lock(phil->id, get_ms(e), "is thinking", e);
	}
	return (NULL);
}
