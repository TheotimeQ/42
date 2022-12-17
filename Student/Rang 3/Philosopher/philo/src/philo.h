/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:38:26 by tquere            #+#    #+#             */
/*   Updated: 2022/12/17 15:29:46 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <limits.h>
# include <sys/time.h>

# include <stdio.h>

typedef struct s_phil
{	
	int						alive;
	int						id;
	int						nb_eat;
	int						state;
	long int				last_eat;
	int						stop;
	pthread_mutex_t			fork;
	pthread_t				thread;
}	t_phil;

typedef struct s_env
{	
	struct timeval			current_time;
	int						cur_id;
	long int				nb_phil;
	long int				time_die;
	long int				time_eat;
	long int				time_sleep;
	long int				nb_eat;
	t_phil					**all_phil;
	pthread_mutex_t			print_mutex;

}	t_env;

size_t		ft_strlen(const char *s);
long int	ft_atoi(const char *str);

void		check_args(t_env *e, int argc, char **argv);

void		free_philo(t_env *e);
void		create_philos(t_env *e);

void		print_mutex(t_env *e, char *str);
void		free_exit(t_env *e, int error_code);

void		stop_all_phil(t_env *e);
void		check_eat_enough(t_env *e);
void		check_died(t_env *e);

#endif
