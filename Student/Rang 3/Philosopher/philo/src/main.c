/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:54 by tquere            #+#    #+#             */
/*   Updated: 2022/12/16 11:40:17 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_mutex(t_env *e, char *str)
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
	t_env	*e;

	e = malloc(sizeof(t_env));
	if (e == NULL)
	{
		printf("Error: malloc env\n");
		exit(1);
	}
	if (pthread_mutex_init(&(e->print_mutex), NULL) != 0)
    {
        printf("Error: init mutex print\n");
        free_exit(e, 1);
    }

	//Creer le pipe message
	
	e->all_phil = NULL;
	e->nb_phil = -1;
	e->time_die = -1;
	e->time_eat = -1;
	e->time_sleep = -1;
	e->nb_eat = -1;
	e->pipe_msg = -1;
	return (e);
}

void	stop_all_phil(t_env *e)
{	
	int id;

	if (e->nb_eat > 0)
	{
		id = 0;
		while (id < e->nb_phil)
			e->all_phil[id++]->stop = 1
	}
	free_exit(e, 0);
}

void	check_eat_enough(t_env *e)
{
	int id;

	if (e->nb_eat > 0)
	{
		id = 0;
		while (id < e->nb_phil)
		{   
			if (e->all_phil[id]->nb_eat < e->nb_eat)
				return ;
			id++;
		}
	}
	stop_all_phil(e);
	free_exit(e, 0);
}

void	check_died(t_env *e)
{
	int id;

	if (e->nb_eat > 0)
	{
		id = 0;
		while (id < e->nb_phil)
		{   
			if (e->all_phil[id]->alive == 1)
				return ;
			id++;
		}
	}
	stop_all_phil(e);
	free_exit(e, 0);
}

int	main(int argc, char **argv)
{	
	t_env		*e;

	e = init_env();
	check_args(e, argc, argv);
	create_philos(e);
	while(1)
	{
		check_pipe_print(e);
		check_eat_enough(e);
		check_died(e);
	}
	free_exit(e, 0);
}

