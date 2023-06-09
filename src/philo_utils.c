/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:22:27 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/24 16:57:01 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time(struct timeval tv)
{
	gettimeofday(&tv, NULL);
	return ((1000 * tv.tv_sec) + (tv.tv_usec / 1000.0));
}

