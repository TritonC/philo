/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:04:00 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/24 17:37:20 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo			*philo;
	t_table			table;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	if (argc != 5 || argc != 6)
		return (error_msg("invalid argument"));
	init_values(&table, argv);
	return (1);
}
