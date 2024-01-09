/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:43:43 by feberman          #+#    #+#             */
/*   Updated: 2024/01/09 19:55:23 by feberman         ###   ########.fr       */
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
	struct s_philo	*philos;
}	t_data;

typedef struct s_philo
{
	unsigned int	id;
	t_data			*data;
}	t_philo;

void			*routine(void *p);

//structs.c
t_data			*malloc_data(void);

//input.c
t_data			*validate_input(int argc, char *argv[]);
void			*fill_data(int argc, char *argv[], t_data *data);
int				convert_input_num(char *str, unsigned int *target);
void			convert_timescale(t_data *data);

//threads.c
int				launch_threads(t_data *data);

//print.c
void	print_log(const char *msg, unsigned int id, long time_offset);

//utils.c
unsigned int	ft_strlen(const char *str);
t_philo			*get_philos_arr(t_data *data);
int				*get_states_arr(t_data *data);

//time.c
int				set_time_offset(t_data *data);
long int		get_time(long int offset);

//errors.c
void			*ft_error(const char *msg);
void			*eval_input_err(int code);

//debug.c
void			print_data(t_data *data);
void			ft_putendl_fd(char *s, int fd);

#endif