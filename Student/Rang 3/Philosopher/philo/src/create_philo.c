/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:10:17 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/17 08:46:10 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    free_philo(t_env *e)
{
    int id;

    id = 0;
    while (id < e->nb_phil)
    {   
        free(e->all_phil[id]);
        id++;
    }
    free(e->all_phil);
}

// number_of_philosophers 
// time_to_die 
// time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat] optionnel

//Thread :

    //Check si il doit mourir

    //Si mort on stop le thread

    //Si stop on stop le thread
    
    // Verifis si les deux fourchettes sont unlock

    //Si c'est le cas manges

        //une fois fini de manger , envoi 

    //Une fois manger se repose

    //Une fois reposé medite

    //Une fois medité , mange


static t_phil	*init_philo(t_env *e, int id)
{
	t_phil  *philo;

	philo = malloc(sizeof(t_phil));
	if (philo == NULL)
	{
		printf("Error: malloc philo\n");
		free_exit(e, 1);
	}
	if (pthread_mutex_init(&(philo->fork), NULL) != 0)
    {
        printf("Error: init mutex philo\n");
        free_exit(e, 1);
    }
    philo->id = id;
    philo->alive = 1;
    philo->stop = 0;

    //Create pipe
	philo->pipe = 1;

    //Get temps
	philo->last_eat = 1; 
	
    //State
    philo->state = -1;

    //Chaque philo creer son thread

    //Ecris que le philo à demarer


    return (philo);
}

void    create_philos(t_env *e)
{
    int id;

    id = 0;
    while (id < e->nb_phil)
    {   
        e->all_phil[id] = init_philo(e, id);
        id++;
    }
}