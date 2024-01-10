/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:53:58 by feberman          #+#    #+#             */
/*   Updated: 2024/01/10 22:52:50 by feberman         ###   ########.fr       */
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
	while (1)
	{
		if (get_state(data, id) == DEAD)
			return (NULL);
		if (grab_forks(philo))
		{
			print_log(EAT, philo, 1);
			set_last_eaten(data, id);
			usleep(philo->time_to_eat);
			put_forks_back(philo);
			print_log(SLEEP, philo, 1);
			usleep(philo->time_to_sleep);
			print_log(THINK, philo, 1);
		}
		else
			usleep(10);
	}
	return (NULL);
}

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
			if (now - get_last_eaten(data, i + 1) > data->time_to_die)
			{
				print_log(DEATH, &data->philos[i], 0);
				i = 0;
				while (i < data->philo_count)
					set_state_dead(data, i++ + 1);
				i = 0;
				while (i < data->philo_count)
					pthread_join(data->philos[i++].thread, NULL);
				return ;
			}
			i++;
		}
		usleep(500);
	}
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
