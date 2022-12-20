/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:54 by tquere            #+#    #+#             */
/*   Updated: 2022/12/20 17:49:03 by tquere           ###   ########.fr       */
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

void	wait_thread(t_env *e)
{
	int		id;

	id = 0;
	while (id < e->nb_phil)
		if (e->all_phil[id])
			pthread_join(e->all_phil[id++]->thread, NULL);
}

static t_env	*init_env(void)
{
	t_env				*e;
	struct timeval		current_time;

	e = malloc(sizeof(t_env));
	if (e == NULL)
	{
		write(2, "Error: malloc env\n", 18);
		exit(1);
	}
	if (pthread_mutex_init(&(e->print_mutex), NULL) != 0)
	{	
		write(2, "Error: init mutex print\n", 24);
		free_exit(e, 1);
	}
	e->all_phil = NULL;
	e->nb_eat = -1;
	e->nb_phil = -1;
	e->time_die = -1;
	e->time_eat = -1;
	e->time_sleep = -1;
	e->nb_eat = -1;
	gettimeofday(&current_time, NULL);
	e->start_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (e);
}

void	print_list(int *list, int size)
{
	while (size--)
	{
		printf(" %d |", list[size]);
	}
	printf("\n");
}

int	main(int argc, char **argv)
{	
	t_env		*e;

	e = init_env();
	check_args(e, argc, argv);
	create_philos(e);
	// while (1)
	// {	
	// 	// pthread_mutex_lock(&(e->all_eat_mutex));
	// 	// check_eat_enough(e);
	// 	// check_one_died(e);
	// 	// pthread_mutex_unlock(&(e->all_eat_mutex));
	// 	// print_list(e->all_eat, e->nb_phil);
	// 	// usleep(50 * 1000);
	// }
	wait_thread(e);
	free_exit(e, 0);
}



// Usage: start.sh <Project Folder> <Test Type>
// 	Type 0: test philo_one, philo_two and philo_three
// 	Type 1: test philo_one only
// 	Type 2: test philo_two only
// 	Type 3: test philo_three only

// memset, printf, malloc, free, write,
// usleep, gettimeofday, 
// pthread_create, pthread_detach, pthread_join,
// pthread_mutex_init,pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock


// ATTENTION SI 1 OU DEUX PHIL , peut prendre ca propre fork ?

// Dans le cas pair une solution simple existe. On numérote les philosophes selon leur place à la table. Et l'on décide que les philosophes ayant un nombre pair prennent d'abord leur fourchette gauche, puis leur droite et l'inverse avec les philosophes ayant un nombre impair.

//Check si autre chose aue chiffre