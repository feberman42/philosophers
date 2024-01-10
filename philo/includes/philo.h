/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:43:43 by feberman          #+#    #+#             */
/*   Updated: 2024/01/10 22:54:10 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include "errors.h"
# include "msg.h"

# define DEAD 0
# define ALIVE 1

typedef struct s_data
{
	unsigned int	philo_count;

	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	eat_count;
	int				use_eat_count;
	long long int	time_offset;
	int				*states;
	pthread_mutex_t	states_m;
	long int		*last_eaten;
	pthread_mutex_t	last_eaten_m;
	struct s_philo	*philos;
	int				running;
	pthread_mutex_t	running_m;
	pthread_mutex_t	*forks_m;
	int				*forks;
	pthread_mutex_t	write_lock;
	int				write_flag;
}	t_data;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	eat_count;
	t_data			*data;
	pthread_t		thread;
}	t_philo;

void			*routine(void *p);

//structs.c
t_data			*malloc_data(void);
t_data			*setup(int	argc, char *argv[]);
void			*free_data(t_data *data);

//input.c
t_data			*validate_input(int argc);
void			*fill_data(int argc, char *argv[], t_data *data);
int				convert_input_num(char *str, unsigned int *target);
void			convert_timescale(t_data *data);

//threads.c
int				launch_threads(t_data *data);

//mutexes.c
void			init_mutexes(t_data *data);
long int		get_last_eaten(t_data *data, unsigned int id);
void			set_last_eaten(t_data *data, unsigned int id);
int				get_state(t_data *data, unsigned int id);
void			set_state_dead(t_data *data, unsigned int id);

//philo_actions.c
int				grab_forks(t_philo *philo);
void			put_forks_back(t_philo *philo);

//print.c
void			print_log(const char *msg, t_philo *philo, int unlock);
void			set_write_flag(t_data *data, int state);

//utils.c
unsigned int	ft_strlen(const char *str);
t_philo			*get_philos_arr(t_data *data);
int				*get_states_arr(t_data *data);
long int		*get_last_eaten_arr(t_data *data);
int				init_forks_m(t_data *data);

//time.c
int				set_time_offset(t_data *data);
long int		get_time(long int offset);
long int		get_time_ms(t_data *data);

//errors.c
void			*ft_error(const char *msg);
void			*eval_input_err(int code);

//debug.c
void			print_data(t_data *data);
void			ft_putendl_fd(char *s, int fd);

#endif