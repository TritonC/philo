/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:01:04 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/24 17:41:59 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include "limits.h"
# include "sys/time.h"
# include "unistd.h"
# include "stdlib.h"

# define ATC_TAKE "has taken a fork"
# define ATC_EAT "is eating"
# define ATC_SLEEP "is sleeping"
# define ATC_DIE "died"

enum e_pstate
{
	P_IS_ALIVE = 1,
	P_IS_DEAD = 0,
};

typedef struct s_rules
{
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	int		eat_times;
	int		alive;
	int		dead;
}			t_rules;

typedef struct s_philo
{
	pthread_t		philos;
	int				left_m;
	int				right_m;
	t_rules			rules;
}			t_philo;

typedef struct s_table
{
	t_philo		guest[300];
	int			philo_quanty;
	t_rules		rules;
	pthread_t	waiter;
}			t_table;

void	init_values(t_table *philo, char *argv[]);
int		error_msg(const char *str);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(const char *str, char delimiter);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);

#endif