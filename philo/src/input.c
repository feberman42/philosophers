/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:08:57 by feberman          #+#    #+#             */
/*   Updated: 2024/01/11 12:53:52 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*validate_input(int argc)
{
	t_data			*data;

	if (argc < 5 || argc > 6)
		return (ft_error(ERR_ARG_NUM));
	data = malloc_data();
	if (!data)
		return (ft_error(ERR_MALLOC));
	data->eat_count = 0;
	data->use_eat_count = 0;
	return (data);
}

void	*fill_data(int argc, char *argv[], t_data *data)
{
	unsigned int	tmp;

	tmp = convert_input_num(argv[1], &data->philo_count);
	if (tmp > 0)
		return (eval_input_err(tmp));
	if (data->philo_count == 0)
		return (NULL);
	tmp = convert_input_num(argv[2], &data->time_to_die);
	if (tmp > 0)
		return (eval_input_err(tmp));
	tmp = convert_input_num(argv[3], &data->time_to_eat);
	if (tmp > 0)
		return (eval_input_err(tmp));
	tmp = convert_input_num(argv[4], &data->time_to_sleep);
	if (tmp > 0)
		return (eval_input_err(tmp));
	if (check_use_eat_count(argc, argv, data) != 0)
		return (NULL);
	convert_timescale(data);
	return (data);
}

int	check_use_eat_count(int argc, char *argv[], t_data *data)
{
	unsigned int	tmp;

	if (argc == 6)
	{
		tmp = convert_input_num(argv[5], &data->eat_count);
		if (tmp > 0)
		{
			eval_input_err(tmp);
			return (1);
		}
		data->use_eat_count = 1;
		if (data->eat_count == 0)
		{
			ft_error(ATE_ENOUGH);
			return (1);
		}
	}
	return (0);
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
