/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:43:43 by feberman          #+#    #+#             */
/*   Updated: 2024/01/05 12:30:48 by feberman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include "errors.h"

typedef	struct	s_data
{
	unsigned int	philo_count;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	eat_count;
	int				use_eat_count;
	long long int		time_offset;
}	t_data;

//structs.c
t_data	*malloc_data(void);

//input.c
t_data	*validate_input(int argc, char *argv[]);
void	*fill_data(int argc, char *argv[], t_data *data);
int		convert_input_num(char *str, unsigned int *target);
void	convert_timescale(t_data *data);

//utils.c
unsigned int	ft_strlen(const char *str);

//time.c
int			set_time_offset(t_data *data);
long int	get_time(long int offset);

//errors.c
void	*ft_error(const char *msg);
void	*eval_input_err(int	code);

//debug.c
void	print_data(t_data *data);

#endif