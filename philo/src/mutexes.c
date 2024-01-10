/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:12 by feberman          #+#    #+#             */
/*   Updated: 2024/01/10 22:09:57 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutexes(t_data *data)
{
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->running_m, NULL);
	pthread_mutex_init(&data->last_eaten_m, NULL);
	pthread_mutex_init(&data->states_m, NULL);
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

int	get_state(t_data *data, unsigned int id)
{
	long int	value;

	pthread_mutex_lock(&data->states_m);
	value = data->states[id - 1];
	pthread_mutex_unlock(&data->states_m);
	return (value);
}

void	set_state_dead(t_data *data, unsigned int id)
{
	pthread_mutex_lock(&data->states_m);
	data->states[id - 1] = DEAD;
	pthread_mutex_unlock(&data->states_m);
}