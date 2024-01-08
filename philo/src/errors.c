/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:26:54 by feberman          #+#    #+#             */
/*   Updated: 2024/01/08 15:32:39 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_error(const char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		write(2, msg + i++, 1);
	write(2, "\n", 1);
	return (NULL);
}

void	*eval_input_err(int code)
{
	if (code == 1)
		return (ft_error(ERR_NOT_NUM));
	return (ft_error(ERR_NUM_BIG));
}
