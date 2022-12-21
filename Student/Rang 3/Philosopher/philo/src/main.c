/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:54 by tquere            #+#    #+#             */
/*   Updated: 2022/12/21 15:04:52 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mutex(t_env *e, char *str)
{
	pthread_mutex_lock(&(e->print_mutex));
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&(e->print_mutex));
}

void	free_philo(t_env *e)
{
	int	id;	

	id = 0;
	while (id < e->nb_phil)
	{	
		free(e->all_phil[id]);
		e->all_phil[id] = NULL;
		id++;
	}
}

void	free_exit(t_env *e, int error_code)
{	
	free_philo(e);
	free(e->forks_mutex);
	free(e->all_phil);
	free(e->forks);
	free(e->thread);
	free(e->eats);
	free(e);
	exit(error_code);
}

void	wait_thread(t_env *e)
{
	int		id;

	id = 0;
	while (id < e->nb_phil)
		pthread_join(e->thread[id++], NULL);
}

int	main(int argc, char **argv)
{	
	t_env		*e;

	e = init_env();
	check_args(e, argc, argv);
	create_forks(e);
	create_philos(e);
	wait_thread(e);
	free_exit(e, 0);
}
