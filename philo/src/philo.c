/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:53:58 by feberman          #+#    #+#             */
/*   Updated: 2024/01/05 16:07:38 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	printf("Hello from %u\n", philo->id);
	sleep(2);
	philo->data->states[philo->id - 1] = DEAD;
	return (NULL);
}

void	monitor_loop(t_data *data)
{
	unsigned int	i;

	while (1)
	{
		i = 0;
		while (i < data->philo_count)
		{
			if (data->states[i++] == DEAD)
			{
				printf("%u is dead.\n", i); //TODO build msg system w time
				return ;
			}
		}
	}
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = validate_input(argc, argv);
	if (!data)
	{
		free(data);
		return (1);
	}
	print_data(data); //TODO remove
	data->philos = get_philos_arr(data);
	if (!data->philos)
		return (1);
	data->states = get_states_arr(data);
	if (!data->states)
		return (1);
	
	launch_threads(data);
	
	monitor_loop(data);
	return (0);
}