/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:21:19 by lgomes-o          #+#    #+#             */
/*   Updated: 2023/03/15 09:23:13 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((*(s1 + i) != '\0' && *(s2 + i) != '\0') && i < n - 1)
	{
		if ((*(s1 + i) != *(s2 + i)))
			break ;
		i++;
	}
	return (((unsigned char)*(s1 + i)) - ((unsigned char)*(s2 +(i))));
}
