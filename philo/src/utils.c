/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:13:54 by feberman          #+#    #+#             */
/*   Updated: 2024/01/08 15:33:31 by feberman         ###   ########.fr       */
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
