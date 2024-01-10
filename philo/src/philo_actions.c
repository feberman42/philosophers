/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:22:08 by feberman          #+#    #+#             */
/*   Updated: 2024/01/10 22:38:13 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	grab_forks_l(t_data *data, t_philo *philo, unsigned int l, unsigned int r);
static int	grab_forks_r(t_data *data, t_philo *philo, unsigned int l, unsigned int r);

int	grab_forks(t_philo *philo)
{
	t_data			*data;
	unsigned int	l;
	unsigned int	r;

	data = philo->data;
	l = philo->id - 1;
	r = (l + 1) % data->philo_count;
	if (l % 2)
		return (grab_forks_l(data, philo, l, r));
	else
		return (grab_forks_r(data, philo, l, r));
}

void	put_forks_back(t_philo *philo)
{
	t_data			*data;
	unsigned int	id;

	data = philo->data;
	id = philo->id - 1;
	pthread_mutex_lock(&data->forks_m[id]);
	data->forks[id] = 1;
	pthread_mutex_unlock(&data->forks_m[id]);
	pthread_mutex_lock(&data->forks_m[(id + 1) % data->philo_count]);
	data->forks[(id + 1) % data->philo_count] = 1;
	pthread_mutex_unlock(&data->forks_m[(id + 1) % data->philo_count]);
}

static int	grab_forks_l(t_data *data, t_philo *philo, unsigned int l, unsigned int r)
{
	pthread_mutex_lock(&data->forks_m[l]);
	if (data->forks[l])
	{
		pthread_mutex_lock(&data->forks_m[r]);
		if (data->forks[r])
		{
			data->forks[l] = 0;
			print_log(FORK, philo, 1);
			data->forks[r] = 0;
			print_log(FORK, philo, 1);
			pthread_mutex_unlock(&data->forks_m[r]);
			pthread_mutex_unlock(&data->forks_m[l]);
			return (1);
		}
		pthread_mutex_unlock(&data->forks_m[r]);
	}
	pthread_mutex_unlock(&data->forks_m[l]);
	return (0);
}

static int	grab_forks_r(t_data *data, t_philo *philo, unsigned int l, unsigned int r)
{
	pthread_mutex_lock(&data->forks_m[r]);
	if (data->forks[r])
	{
		pthread_mutex_lock(&data->forks_m[l]);
		if (data->forks[l])
		{
			data->forks[r] = 0;
			print_log(FORK, philo, 1);
			data->forks[l] = 0;
			print_log(FORK, philo, 1);
			pthread_mutex_unlock(&data->forks_m[l]);
			pthread_mutex_unlock(&data->forks_m[r]);
			return (1);
		}
		pthread_mutex_unlock(&data->forks_m[l]);
	}
	pthread_mutex_unlock(&data->forks_m[r]);
	return (0);
}