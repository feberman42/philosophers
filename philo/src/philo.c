/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:53:58 by feberman          #+#    #+#             */
/*   Updated: 2024/01/11 13:17:55 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
