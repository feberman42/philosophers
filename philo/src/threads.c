/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:35:19 by feberman          #+#    #+#             */
/*   Updated: 2024/01/11 13:18:01 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *p)
{
	t_philo			*philo;
	unsigned int	id;
	t_data			*data;

	philo = (t_philo *)p;
	data = philo->data;
	id = philo->id;
	pthread_mutex_lock(&data->running_m);
	pthread_mutex_unlock(&data->running_m);
	print_log(THINK, philo, 1);
	if (id % 2 == 0)
		usleep(philo->time_to_eat / 10);
	philo_loop(data, philo, id);
	return (NULL);
}

int	launch_threads(t_data *data)
{
	unsigned int	i;
	t_philo			*philo;

	i = 0;
	while (i < data->philo_count)
	{
		philo = &data->philos[i];
		pthread_create(&philo->thread, NULL, &routine, philo);
		i++;
	}
	return (0);
}
