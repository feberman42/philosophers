/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:22:08 by feberman          #+#    #+#             */
/*   Updated: 2024/01/15 11:55:59 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	grab_forks_order(t_philo *philo, unsigned int l, unsigned int r);

void	philo_loop(t_data *data, t_philo *philo, unsigned int id)
{
	while (1)
	{
		if (get_state(data, id) == DEAD || philo->philo_count == 1)
			break ;
		if (grab_forks(philo))
		{
			print_log(EAT, philo, 1);
			philo_eat(philo);
			put_forks_back(philo);
			print_log(SLEEP, philo, 1);
			usleep(philo->time_to_sleep);
			print_log(THINK, philo, 1);
			usleep(100);
		}
		else
			usleep(10);
	}
}

int	grab_forks(t_philo *philo)
{
	t_data			*data;
	unsigned int	l;
	unsigned int	r;

	data = philo->data;
	l = philo->id - 1;
	r = (l + 1) % data->philo_count;
	if (l % 2)
		return (grab_forks_order(philo, l, r));
	else
		return (grab_forks_order(philo, r, l));
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

static int	grab_forks_order(t_philo *philo, unsigned int l, unsigned int r)
{
	t_data	*data;

	data = philo->data;
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

void	philo_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	set_last_eaten(data, philo->id);
	usleep(philo->time_to_eat);
	philo->eaten++;
	if (philo->eaten == philo->eat_count)
		incr_ate_enough(data);
}
