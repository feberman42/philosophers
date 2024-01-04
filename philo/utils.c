/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:13:54 by feberman          #+#    #+#             */
/*   Updated: 2024/01/04 17:15:09 by feberman         ###   ########.fr       */
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