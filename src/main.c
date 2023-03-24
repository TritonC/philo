/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:04:00 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/24 22:33:48 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo_value(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->philo_quanty)
	{
		table->guest[i].rules = table->rules;
		table->guest[i].right_m = i;
		if (i + 1 == table->philo_quanty)
		{	
			table->guest[i].left_m = 0;
			table->guest[i].right_m = i;
		}
		else
			table->guest[i].left_m = i + 1;
		i++;
	}
}

void	info_status(t_table *table)
{
	
}

int	main(int argc, char *argv[])
{
	t_philo			*philo;
	t_table			table;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	if (argc != 5 || argc != 6)
		return (error_msg("invalid argument"));
	init_values(&table, argv);
	init_philo_value(&table);
	return (1);
}
