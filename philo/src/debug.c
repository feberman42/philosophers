/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:54:01 by feberman          #+#    #+#             */
/*   Updated: 2024/01/05 15:45:03 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_data(t_data *data)
{
	printf("Philosophers: %u\nTime_to_die: %u\nTime_to eat: %u\nTime_to_sleep: %u\nTimes_to_eat: %u\nUse eats: %i\nTime: %lli\n\n",\
			data->philo_count, data->time_to_die, data->time_to_eat, data->time_to_sleep, data->eat_count, data->use_eat_count, data->time_offset);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}