/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:01:04 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/22 12:54:27 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <pthread.h>

# define ATC_TAKE "has taken a fork"
# define ATC_EAT "is eating"
# define ATC_SLEEP "is sleeping"
# define ATC_DIE "died"

enum e_pstate
{
	P_IS_ALIVE = 1,
	P_IS_DEAD = 0,
};

typedef struct srules
{
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	int		eat_times;
}			t_rules;

typedef struct s_philo
{
	int		*philo_id;
	int		left_m;
	int		right_m;
	t_rules	rules;
}			t_philo;

t_philo	*init_values(char *argv[]);
#endif