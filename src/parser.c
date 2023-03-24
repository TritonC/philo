/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:04:39 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/24 17:42:12 by mluis-fu         ###   ########.fr       */
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

void	init_values(t_table *table, char *argv[])
{
	char			**argv_split;
	long long		i;

	argv_split = split_argv(argv);
	i = ft_atoi(argv[1]);
	if (i <= 0 || i > 300)
		return ;
	i = 0;
	table->philo_quanty = ft_atoi(argv[1]);
	table->rules.t_to_die = ft_atoi(argv[2]);
	table->rules.t_to_eat = ft_atoi(argv[3]);
	table->rules.t_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->rules.eat_times = ft_atoi(argv[5]);
	else
		table->rules.eat_times = -1;
}
