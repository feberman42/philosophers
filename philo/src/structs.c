/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:20:29 by feberman          #+#    #+#             */
/*   Updated: 2024/01/11 12:56:57 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*setup(int argc, char *argv[])
{
	t_data	*data;

	data = validate_input(argc);
	if (!data)
		return (NULL);
	if (!fill_data(argc, argv, data))
		return (free_data(data));
	data->philos = get_philos_arr(data);
	if (!data->philos)
		return (free_data(data));
	data->states = get_states_arr(data);
	if (!data->states)
		return (free_data(data));
	data->last_eaten = get_last_eaten_arr(data);
	if (!data->last_eaten)
		return (free_data(data));
	if (init_forks_m(data) != 0)
		return (free_data(data));
	init_mutexes(data);
	return (data);
}

t_data	*malloc_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	memset(data, 0, sizeof(t_data));
	return (data);
}

void	*free_data(t_data *data)
{
	unsigned int	i;

	if (!data)
		return (NULL);
	if (data->states)
		free(data->states);
	if (data->last_eaten)
		free(data->last_eaten);
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
	if (data->forks_m)
	{
		i = 0;
		while (i < data->philo_count)
			pthread_mutex_destroy(&data->forks_m[i++]);
		free(data->forks_m);
	}
	destoy_mutexes(data);
	free(data);
	return (NULL);
}
