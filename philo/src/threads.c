/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:35:19 by feberman          #+#    #+#             */
/*   Updated: 2024/01/10 18:50:29 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
