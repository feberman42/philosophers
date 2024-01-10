/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:48:21 by feberman          #+#    #+#             */
/*   Updated: 2024/01/10 22:53:51 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_log(const char *msg, t_philo *philo, int write_flag)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (philo->data->write_flag)
		printf("%li %i %s\n", get_time_ms(philo->data), philo->id, msg);
	if (!write_flag)
		philo->data->write_flag = 0;
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	set_write_flag(t_data *data, int state)
{
	pthread_mutex_lock(&data->write_lock);
	data->write_flag = state;
	pthread_mutex_unlock(&data->write_lock);
}