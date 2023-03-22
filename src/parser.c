/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:04:39 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/22 12:38:54 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	**split_argv(char **argv)
{
	int		i;
	char	*dest;
	char	**split;

	i = 1;
	dest = ft_calloc(1, 1);
	while (argv[i])
	{
		dest = ft_strjoin(dest, argv[i]);
		dest = ft_strjoin(dest, " ");
		i++;
	}
	split = ft_split(dest, ' ');
	return (split);
}

t_philo	*init_values(char *argv[])
{
	t_philo	*philo;
	char	**argv_split;
	int		i;

	i = 1;
	philo = ft_calloc(sizeof(t_philo), 1);
	argv_split = split_argv(argv);
	philo->philo_id = ft_calloc(sizeof(int), ft_atoi(argv[1]));
	philo->rules.t_to_die = ft_atoi(argv[2]);
	philo->rules.t_to_eat = ft_atoi(argv[3]);
	philo->rules.t_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->rules.eat_times = ft_atoi(argv[5]);
	else
		philo->rules.eat_times = -1;
	return (philo);
}
