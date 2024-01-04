/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:43:43 by feberman          #+#    #+#             */
/*   Updated: 2024/01/04 17:27:27 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>

typedef	struct	s_data
{
	unsigned int	philo_count;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_spleep;
	unsigned int	eat_count;
	int				use_eat_count;
}	t_data;

//input.c
int	convert_input_num(char *str, unsigned int *target);

//utils.c
unsigned int	ft_strlen(const char *str);

#endif