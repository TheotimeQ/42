/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:34:27 by tquere            #+#    #+#             */
/*   Updated: 2022/12/20 17:30:21 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	stop_all_phil(t_env *e)
// {	
// 	int		id;

// 	id = 0;
// 	while (id < e->nb_phil)
// 		if (e->all_phil[id])
// 			e->all_phil[id++]->stop = 1;
// 			//mutex ?
// 	id = 0;
// 	while (id < e->nb_phil)
// 		if (e->all_phil[id])
// 			pthread_join(e->all_phil[id++]->thread, NULL);
// 	printf("STOPPED\n");
// 	free_exit(e, 0);
// }

// void	check_eat_enough(t_env *e)
// {
// 	int		id;

// 	if (e->nb_eat > 0)
// 	{
// 		id = 0;
// 		while (id < e->nb_phil)
// 		{	
// 			if (e->all_eat[id] < e->nb_eat)
// 				return ;
// 			id++;
// 		}
// 		pthread_mutex_unlock(&(e->all_eat_mutex));
// 		printf("SHOULD STOP EAT\n");
// 		stop_all_phil(e);
// 		free_exit(e, 0);
// 	}
// }

// void	check_one_died(t_env *e)
// {
// 	int		id;

// 	id = 0;
// 	while (id < e->nb_phil)
// 	{	
// 		if (e->all_eat[id] < 0)
// 		{	
// 			pthread_mutex_unlock(&(e->all_eat_mutex));
// 			printf("SHOULD STOP DEAD\n");
// 			stop_all_phil(e);
// 			free_exit(e, 0);
// 		}
// 		id++;
// 	}
// }
