/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:53:58 by feberman          #+#    #+#             */
/*   Updated: 2024/01/05 12:02:58 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *p)
{
	(void)p;
	printf("Hello\n");
	return (NULL);
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
	print_data(data);
	return (0);
}