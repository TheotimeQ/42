/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:10:50 by tquere            #+#    #+#             */
/*   Updated: 2022/12/22 09:59:54 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mutex(t_env *e, char *str)
{
	pthread_mutex_lock(&(e->print_mutex));
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&(e->print_mutex));
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
