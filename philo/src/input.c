/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:08:57 by feberman          #+#    #+#             */
/*   Updated: 2024/01/08 15:32:43 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*validate_input(int argc, char *argv[])
{
	t_data			*data;

	data = malloc_data();
	if (!data)
		return (ft_error(ERR_MALLOC));
	if (argc < 5 || argc > 6)
		return (ft_error(ERR_ARG_NUM));
	data->eat_count = 0;
	data->use_eat_count = 0;
	return (fill_data(argc, argv, data));
}

void	*fill_data(int argc, char *argv[], t_data *data)
{
	unsigned int	tmp;

	tmp = convert_input_num(argv[1], &data->philo_count);
	if (tmp > 0)
		return (eval_input_err(tmp));
	tmp = convert_input_num(argv[2], &data->time_to_die);
	if (tmp > 0)
		return (eval_input_err(tmp));
	tmp = convert_input_num(argv[3], &data->time_to_eat);
	if (tmp > 0)
		return (eval_input_err(tmp));
	tmp = convert_input_num(argv[4], &data->time_to_sleep);
	if (tmp > 0)
		return (eval_input_err(tmp));
	if (argc == 6)
	{
		tmp = convert_input_num(argv[5], &data->eat_count);
		if (tmp > 0)
			return (eval_input_err(tmp));
		data->use_eat_count = 1;
	}
	convert_timescale(data);
	if (set_time_offset(data) == 0)
		return (ft_error(ERR_TIME));
	return (data);
}

int	convert_input_num(char *str, unsigned int *target)
{
	unsigned int	i;

	*target = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		if (*target > (UINT_MAX / 10))
			return (2);
		*target *= 10;
		if (*target > (UINT_MAX - (str[i] - 48)))
			return (2);
		*target += str[i] - 48;
		i++;
	}
	if (*target > (UINT_MAX / 1000))
		return (3);
	return (0);
}

void	convert_timescale(t_data *data)
{
	data->time_to_die *= 1000;
	data->time_to_eat *= 1000;
	data->time_to_sleep *= 1000;
}
