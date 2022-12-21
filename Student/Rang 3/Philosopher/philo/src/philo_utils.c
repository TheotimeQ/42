/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:10:50 by tquere            #+#    #+#             */
/*   Updated: 2022/12/21 15:15:46 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_eat_enough(t_env *e)
{
	int		id;

	id = 0;
	while (id < e->nb_phil)
	{	
		pthread_mutex_lock(&(e->mutex_eat));
		if (e->eats[id] < e->nb_eat)
		{
			pthread_mutex_unlock(&(e->mutex_eat));
			return ;
		}
		pthread_mutex_unlock(&(e->mutex_eat));
		id++;
	}
	pthread_mutex_lock(&(e->stop_mutex));
	e->stop = 1;
	pthread_mutex_unlock(&(e->stop_mutex));
}

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
	ft_putnbr(time);
	write(1, " ", 1);
	ft_putnbr(id + 1);
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	pthread_mutex_unlock(&(e->print_mutex));
}

int	check_alive(t_env *e, t_phil *phil)
{	
	pthread_mutex_lock(&(e->stop_mutex));
	if (e->stop == 1)
	{	
		pthread_mutex_unlock(&(e->stop_mutex));
		return (0);
	}
	pthread_mutex_unlock(&(e->stop_mutex));
	if (get_ms(e) - phil->last_eat > e->time_die)
	{
		print_lock(phil->id, get_ms(e), "have died", e);
		pthread_mutex_lock(&(e->stop_mutex));
		e->stop = 1;
		pthread_mutex_unlock(&(e->stop_mutex));
		return (0);
	}
	return (1);
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
