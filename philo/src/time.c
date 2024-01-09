/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:19:50 by feberman          #+#    #+#             */
/*   Updated: 2024/01/09 20:12:06 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_time_offset(t_data *data)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL) == -1)
		return (0);
	data->time_offset = t.tv_sec * 1000000 + t.tv_usec;
	return (1);
}

long int	get_time(long int offset)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL) == -1)
		return (-1);
	return ((t.tv_sec * 1000000 + t.tv_usec) - offset);
}

long int	get_time_ms(long int offset)
{
	return (get_time(offset) / 1000);
}
