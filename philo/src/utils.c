/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:13:54 by feberman          #+#    #+#             */
/*   Updated: 2024/01/10 21:47:25 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

t_philo	*get_philos_arr(t_data *data)
{
	t_philo			*philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!philos)
	{
		free(data);
		return (ft_error(ERR_MALLOC));
	}
	i = 0;
	while (i < data->philo_count)
	{
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].time_to_die = data->time_to_die;
		philos[i].time_to_eat = data->time_to_eat;
		philos[i].time_to_sleep = data->time_to_sleep;
		i++;
	}
	return (philos);
}

int	*get_states_arr(t_data *data)
{
	int				*states;
	unsigned int	i;

	states = malloc(sizeof(int) * data->philo_count);
	if (!states)
	{
		free(data);
		return (ft_error(ERR_MALLOC));
	}
	i = 0;
	while (i < data->philo_count)
		states[i++] = ALIVE;
	return (states);
}

long int	*get_last_eaten_arr(t_data *data)
{
	long int		*last_eaten;
	unsigned int	i;

	last_eaten = malloc(sizeof(long int) * data->philo_count);
	if (!last_eaten)
	{
		free(data);
		return (ft_error(ERR_MALLOC));
	}
	i = 0;
	while (i < data->philo_count)
		last_eaten[i++] = 0;
	return (last_eaten);
}

int	init_forks_m(t_data *data)
{
	unsigned int	i;

	data->forks_m = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	data->forks = malloc(sizeof(int) * data->philo_count);
	if (!data->forks_m || !data->forks)
	{
		ft_error(ERR_MALLOC);
		return (1);
	}
	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_init(&data->forks_m[i], NULL);
		data->forks[i] = 1;
		i++;
	}
	return (0);
}