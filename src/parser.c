/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:04:39 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/22 14:16:30 by mluis-fu         ###   ########.fr       */
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

void	init_values(t_philo *philo, char *argv[])
{
	char			**argv_split;
	long long		i;

	philo = ft_calloc(sizeof(t_philo), 1);
	argv_split = split_argv(argv);
	i = ft_atoi(argv[1]);
	if (i <= 0 || i > 300)
		return ;
	philo->philo_id = ft_calloc(sizeof(int), ft_atoi(argv[1]));
	philo->rules.t_to_die = ft_atoi(argv[2]);
	philo->rules.t_to_eat = ft_atoi(argv[3]);
	philo->rules.t_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->rules.eat_times = ft_atoi(argv[5]);
	else
		philo->rules.eat_times = -1;
}
