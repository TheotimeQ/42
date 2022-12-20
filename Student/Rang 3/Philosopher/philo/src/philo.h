/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:38:26 by tquere            #+#    #+#             */
/*   Updated: 2022/12/20 19:01:23 by tquere           ###   ########.fr       */
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
	pthread_t				thread;
	void					*e;
	int						id;
	long long int			last_eat;

	pthread_mutex_t			mutex_fork;

	pthread_mutex_t			mutex_nb_eat;
	int						nb_eat;

	pthread_mutex_t			mutex_stop;
	int						stop;        

}	t_phil;

typedef struct s_env
{	
	t_phil					**all_phil;
	long int				start_ms;
	long int				nb_phil;
	long int				time_die;
	long int				time_eat;
	long int				time_sleep;
	long int				nb_eat;
	
	pthread_mutex_t			print_mutex;
	
	pthread_mutex_t			stop_mutex;
	int						stop;
	
}	t_env;

//Libft
size_t		ft_strlen(const char *s);
char 		*ft_isnum(char *str);
long int	ft_atoi(const char *str);

//Utils philo
long int	get_ms(t_env *e);
void		check_args(t_env *e, int argc, char **argv);
void		print_lock(int id, long int time, char *str, t_env *e);
void		check_alive(t_env *e, t_phil *phil);
void		sleep_stop_die(long int last, t_env *e, t_phil *phil);

//Init philo
void		free_philo(t_env *e);
t_phil		**init_all_phil(t_env *e);
void		create_philos(t_env *e);

//Thread philo
void    	*philo_thread(void *ph);

//Utils main
void		print_mutex(t_env *e, char *str);
void		free_exit(t_env *e, int error_code);

//Other
// void		stop_all_phil(t_env *e);
// void		check_eat_enough(t_env *e);
// void		check_one_died(t_env *e);


#endif
