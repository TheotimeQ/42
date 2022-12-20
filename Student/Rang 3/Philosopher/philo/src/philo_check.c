/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:34:27 by tquere            #+#    #+#             */
/*   Updated: 2022/12/20 10:34:50 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop_all_phil(t_env *e)
{	
	int		id;

	id = 0;
	while (id < e->nb_phil)
		if (e->all_phil[id])
			e->all_phil[id++]->stop = 1;
	id = 0;
	while (id < e->nb_phil)
		if (e->all_phil[id])
			pthread_join(e->all_phil[id++]->thread, NULL);
	printf("All philo ended\n");
	free_exit(e, 0);
}

void	check_eat_enough(t_env *e)
{
	int		id;

	if (e->nb_eat > 0)
	{
		id = 0;
		while (id < e->nb_phil)
		{
			if (e->all_phil[id]->nb_eat < e->nb_eat)
				return ;
			id++;
		}
		stop_all_phil(e);
		free_exit(e, 0);
	}
}

void	check_died(t_env *e)
{
	int		id;

	id = 0;
	while (id < e->nb_phil)
	{
		if (e->all_phil[id]->alive == 1)
			return ;
		id++;
	}
	stop_all_phil(e);
	free_exit(e, 0);
}
