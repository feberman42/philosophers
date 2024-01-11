/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:19:27 by feberman          #+#    #+#             */
/*   Updated: 2024/01/11 12:58:48 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

typedef struct s_data
{
	unsigned int	philo_count;

	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	eat_count;
	unsigned int	ate_enough;
	pthread_mutex_t	ate_enough_m;
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
	unsigned int	philo_count;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	eat_count;
	unsigned int	eaten;
	t_data			*data;
	pthread_t		thread;
}	t_philo;

#endif
