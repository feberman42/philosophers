/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:35:19 by feberman          #+#    #+#             */
/*   Updated: 2024/01/08 15:32:49 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch_threads(t_data *data)
{
	pthread_t		t;
	unsigned int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_create(&t, NULL, &routine, data->philos + i);
		pthread_detach(t);
		i++;
	}
	return (0);
}
