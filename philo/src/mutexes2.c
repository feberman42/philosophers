/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:47:28 by feberman          #+#    #+#             */
/*   Updated: 2024/01/11 13:13:36 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

unsigned int	get_ate_enough(t_data *data)
{
	unsigned int	value;

	pthread_mutex_lock(&data->ate_enough_m);
	value = data->ate_enough;
	pthread_mutex_unlock(&data->ate_enough_m);
	return (value);
}

void	incr_ate_enough(t_data *data)
{
	pthread_mutex_lock(&data->ate_enough_m);
	data->ate_enough++;
	pthread_mutex_unlock(&data->ate_enough_m);
}
