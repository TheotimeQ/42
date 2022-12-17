/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:54 by tquere            #+#    #+#             */
/*   Updated: 2022/12/17 15:32:54 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mutex(t_env *e, char *str)
{
	pthread_mutex_lock(&(e->print_mutex));
	write(1, str, ft_strlen(str));
	pthread_mutex_unlock(&(e->print_mutex));
}

void	free_exit(t_env *e, int error_code)
{	
	free_philo(e);
	free(e);
	exit(error_code);
}

static t_env	*init_env(void)
{
	t_env				*e;

	e = malloc(sizeof(t_env));
	if (e == NULL)
	{
		printf("Error: malloc env\n"); //Changer printf
		exit(1);
	}
	if (pthread_mutex_init(&(e->print_mutex), NULL) != 0)
	{
		printf("Error: init mutex print\n"); //Changer printf
		free_exit(e, 1);
	}
	e->all_phil = NULL;
	e->nb_phil = -1;
	e->time_die = -1;
	e->time_eat = -1;
	e->time_sleep = -1;
	e->nb_eat = -1;
	
	return (e);
}

int	main(int argc, char **argv)
{	
	t_env		*e;

	e = init_env();
	check_args(e, argc, argv);
	create_philos(e);
	while (1)
	{
		check_eat_enough(e);
		check_died(e);
	}
	free_exit(e, 0);
}

// memset, printf, malloc, free, write,
// usleep, gettimeofday, 
// pthread_create, pthread_detach, pthread_join,
// pthread_mutex_init,pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock