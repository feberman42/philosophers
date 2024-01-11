/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:12 by feberman          #+#    #+#             */
/*   Updated: 2024/01/11 12:57:39 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutexes(t_data *data)
{
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->running_m, NULL);
	pthread_mutex_init(&data->last_eaten_m, NULL);
	pthread_mutex_init(&data->states_m, NULL);
	pthread_mutex_init(&data->ate_enough_m, NULL);
}

void	destoy_mutexes(t_data *data)
{
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->running_m);
	pthread_mutex_destroy(&data->last_eaten_m);
	pthread_mutex_destroy(&data->states_m);
	pthread_mutex_destroy(&data->ate_enough_m);
}

int	init_forks_m(t_data *data)
{
	unsigned int	i;

	data->forks_m = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	data->forks = malloc(sizeof(int) * data->philo_count);
	if (!data->forks_m || !data->forks)
	{
		ft_error(ERR_MALLOC);
		return (1);
	}
	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_init(&data->forks_m[i], NULL);
		data->forks[i] = 1;
		i++;
	}
	return (0);
}

long int	get_last_eaten(t_data *data, unsigned int id)
{
	long int	value;

	pthread_mutex_lock(&data->last_eaten_m);
	value = data->last_eaten[id - 1];
	pthread_mutex_unlock(&data->last_eaten_m);
	return (value);
}

void	set_last_eaten(t_data *data, unsigned int id)
{
	pthread_mutex_lock(&data->last_eaten_m);
	data->last_eaten[id - 1] = get_time(data->time_offset);
	pthread_mutex_unlock(&data->last_eaten_m);
}
