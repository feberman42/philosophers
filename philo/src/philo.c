/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:53:58 by feberman          #+#    #+#             */
/*   Updated: 2024/01/11 13:06:02 by feberman         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = setup(argc, argv);
	if (!data)
		return (1);
	pthread_mutex_lock(&data->running_m);
	set_write_flag(data, 1);
	launch_threads(data);
	set_time_offset(data);
	pthread_mutex_unlock(&data->running_m);
	monitor_loop(data);
	free_data(data);
	return (0);
}
