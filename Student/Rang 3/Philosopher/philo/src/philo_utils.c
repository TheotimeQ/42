/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:10:50 by tquere            #+#    #+#             */
/*   Updated: 2022/12/20 17:55:00 by tquere           ###   ########.fr       */
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

void	print_lock(int id, long int time, char *str, t_env *e)
{
	pthread_mutex_lock(&(e->print_mutex));
	printf("%ld %d %s\n", time, id + 1, str); //printf 
	pthread_mutex_unlock(&(e->print_mutex));
}

void	check_alive(t_env *e, t_phil *phil)
{
	if (get_ms(e) - phil->last_eat > e->time_die)
	{
		print_lock(phil->id, get_ms(e), "have died", e);
		//mutex stop
		//e->stop = 1
		//mutex stop
		exit(0);
	}
	if (phil->stop == 1)
		exit(0);
}

void	sleep_stop_die(long int last, t_env *e, t_phil *phil)
{	
	long int	start;
	long int	current;

	start = get_ms(e);
	current = get_ms(e);
	while (current - start < last)
	{
		usleep(50);
		check_alive(e, phil);
		current = get_ms(e);
	}
}