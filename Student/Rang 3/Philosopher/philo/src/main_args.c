/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:05:37 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/16 11:17:13 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int    check_nb(t_env *e,long int nb)
{
    if (nb < 0)
    {
		printf("Wrong paramettre : %ld < 0",nb);
		free_exit(e, 1);
	}  
    return (nb);
}

void	check_args(t_env *e, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Wrong use : ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]");
		free_exit(e, 1);
	}
    e->nb_phil = check_nb(e, ft_atoi(argv[1]));
    e->all_phil = malloc(sizeof(t_phil *) * e->nb_phil * 20000);
	if (e->all_phil == NULL)
	{
        printf("Error: malloc list philo\n");
        free_exit(e, 1);
    }
    e->time_die = check_nb(e, ft_atoi(argv[2]));
    e->time_eat = check_nb(e, ft_atoi(argv[3]));
    e->time_sleep = check_nb(e, ft_atoi(argv[4]));
    if (argc == 6)
        e->nb_eat = check_nb(e, ft_atoi(argv[5]));
    printf("nb_phil:%ld time_die:%ld time_eat%ld time_sleep:%ld nb_eat:%ld\n",e->nb_phil,e->time_die,e->time_eat,e->time_sleep,e->nb_eat);
}