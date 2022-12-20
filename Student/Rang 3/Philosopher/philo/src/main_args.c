/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:05:37 by zelinsta          #+#    #+#             */
/*   Updated: 2022/12/20 17:49:32 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	check_nb(t_env *e, long int nb)
{
	if (nb < 0)
	{
		write(2, "Error : Wrong input\n", 20);
		free_exit(e, 1);
	}
	return (nb);
}

void	check_args(t_env *e, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{	
		write(2, "Wrong use : ./philo number_of_philosophers time_to_die", 54);
		write(2, " time_to_eat time_to_sleep [number_of_times_each_philos", 55);
		write(2, "opher_must_eat]\n", 16);
		free_exit(e, 1);
	}
	e->nb_phil = check_nb(e, ft_atoi(ft_isnum(argv[1])));
	e->all_phil = init_all_phil(e);
	e->time_die = check_nb(e, ft_atoi(ft_isnum(argv[2])));
	e->time_eat = check_nb(e, ft_atoi(ft_isnum(argv[3])));
	e->time_sleep = check_nb(e, ft_atoi(ft_isnum(argv[4])));
	if (argc == 6)
		e->nb_eat = check_nb(e, ft_atoi(ft_isnum(argv[5])));
}
