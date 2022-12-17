/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:38:26 by tquere            #+#    #+#             */
/*   Updated: 2022/12/16 11:38:34 by zelinsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <limits.h>

# include <stdio.h>

typedef struct s_phil
{	
	int						alive;
	int 					id;
	pthread_mutex_t 		fork;
	int 					nb_eat;
	int						state;
	long int				last_eat;
	int						stop;
}	t_phil;

typedef struct s_env
{	
	long int 				nb_phil;
	long int 				time_die;
	long int				time_eat;
	long int				time_sleep;
	long int				nb_eat;
	int						pipe_msg;
	t_phil					**all_phil;
	pthread_mutex_t			print_mutex;
	
}	t_env;


size_t		ft_strlen(const char *s);
long int	ft_atoi(const char *str);

void		check_args(t_env *e, int argc, char **argv);

void    	free_philo(t_env *e);
void    	create_philos(t_env *e);

void    	print_mutex(t_env *e, char *str);
void		free_exit(t_env *e, int error_code);

#endif

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,


// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock