/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:38:26 by tquere            #+#    #+#             */
/*   Updated: 2022/12/22 10:02:57 by tquere           ###   ########.fr       */
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

typedef struct s_phil
{	
	void					*e;
	int						id;
	long long int			last_eat;

}	t_phil;

typedef struct s_env
{	
	long int				start_ms;
	long int				nb_phil;
	long int				time_die;
	long int				time_eat;
	long int				time_sleep;
	long int				nb_eat;

	int						*eats;
	long int				*last_eats;
	t_phil					**all_phil;
	pthread_t				*thread;
	pthread_mutex_t			*forks;

	pthread_mutex_t			print_mutex;
	pthread_mutex_t			eat_mutex;

}	t_env;

//Libft
long int	check_nb(t_env *e, long int nb);
size_t		ft_strlen(const char *s);
char		*ft_isnum(char *str);
long int	ft_atoi(const char *str);
void		ft_putnbr(long long int nb);

//Utils philo
long int	get_ms(t_env *e);
void		print_lock(int id, long int time, char *str, t_env *e);

//Main
t_env		*init_env(void);
void		check_args(t_env *e, int argc, char **argv);

//Init philo
void		create_philos(t_env *e);

//Thread philo
void		*philo_thread(void *ph);

//Utils main
void		print_mutex(t_env *e, char *str);
void		free_exit(t_env *e, int error_code);

#endif
