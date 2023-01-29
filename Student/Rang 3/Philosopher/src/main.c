/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:54 by tquere            #+#    #+#             */
/*   Updated: 2022/12/22 10:00:58 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_env *e)
{
	int	id;	

	if (e->all_phil)
	{
		id = 0;
		while (id < e->nb_phil)
		{	
			free(e->all_phil[id]);
			e->all_phil[id] = NULL;
			id++;
		}
	}
}

void	free_exit(t_env *e, int error_code)
{	
	free_philo(e);
	free(e->all_phil);
	free(e->last_eats);
	free(e->forks);
	free(e->thread);
	free(e->eats);
	free(e);
	exit(error_code);
}

static int	check_eat(t_env *e)
{
	int			id;

	id = 0;
	if (e->nb_eat < 0)
		return (0);
	pthread_mutex_lock(&(e->eat_mutex));
	id = 0;
	while (id < e->nb_phil)
	{	
		if (e->eats[id] < e->nb_eat)
		{
			pthread_mutex_unlock(&(e->eat_mutex));
			return (0);
		}
		id++;
	}
	pthread_mutex_unlock(&(e->eat_mutex));
	return (1);
}

static int	check_die(t_env *e)
{
	int			id;
	long int	current;

	id = 0;
	current = get_ms(e);
	pthread_mutex_lock(&(e->eat_mutex));
	while (id < e->nb_phil)
	{	
		if (current - e->last_eats[id] > e->time_die)
		{	
			print_lock(id, current, "have died", e);
			pthread_mutex_unlock(&(e->eat_mutex));
			return (1);
		}
		id++;
	}
	pthread_mutex_unlock(&(e->eat_mutex));
	return (0);
}

int	main(int argc, char **argv)
{	
	t_env		*e;
	int			id;

	e = init_env();
	check_args(e, argc, argv);
	create_philos(e);
	while (check_die(e) == 0 && check_eat(e) == 0)
		usleep(7 * 1000);
	id = 0;
	while (id < e->nb_phil)
		pthread_detach(e->thread[id++]);
	free_exit(e, 0);
}
