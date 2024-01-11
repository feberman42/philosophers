/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:04:38 by feberman          #+#    #+#             */
/*   Updated: 2024/01/11 13:11:59 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor_loop(t_data *data)
{
	unsigned int	i;
	long int		now;

	usleep(data->time_to_die / 10);
	while (1)
	{
		now = get_time(data->time_offset);
		i = 0;
		while (i < data->philo_count)
		{
			if (check_starve(data, i, now) != 0)
				return ;
			i++;
		}
		if (check_ate_enough(data) != 0)
			return ;
		usleep(500);
	}
}

int	check_starve(t_data *data, unsigned int i, long int now)
{
	if (now - get_last_eaten(data, i + 1) > data->time_to_die)
	{
		print_log(DEATH, &data->philos[i], 0);
		i = 0;
		while (i < data->philo_count)
			set_state_dead(data, i++ + 1);
		i = 0;
		while (i < data->philo_count)
			pthread_join(data->philos[i++].thread, NULL);
		return (1);
	}
	return (0);
}

int	check_ate_enough(t_data *data)
{
	unsigned int	i;

	if (get_ate_enough(data) == data->philo_count && data->use_eat_count)
	{
		print_log(ATE_ENOUGH, &data->philos[0], 0);
		i = 0;
		while (i < data->philo_count)
			set_state_dead(data, i++ + 1);
		i = 0;
		while (i < data->philo_count)
			pthread_join(data->philos[i++].thread, NULL);
		return (1);
	}
	return (0);
}
