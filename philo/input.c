/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:08:57 by feberman          #+#    #+#             */
/*   Updated: 2024/01/04 17:27:41 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	convert_input_num(char *str, unsigned int *target)
{
	unsigned int	i;

	*target = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (*target > (UINT_MAX / 10))
			return (0);
		*target *= 10;
		if (*target > (UINT_MAX - (str[i] - 48)))
			return (0);
		*target += str[i] - 48;
		i++;
	}
	if (*target > (UINT_MAX / 1000))
		return (0);
}