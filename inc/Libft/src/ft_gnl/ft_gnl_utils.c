/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:09:57 by manuel            #+#    #+#             */
/*   Updated: 2023/03/15 08:33:00 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char const *dest, char const *src)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	res = ft_calloc(sizeof(char), (ft_strlen(dest) + ft_strlen(src) + 1));
	if (!res || (!dest && !src))
		return (NULL);
	if (dest)
	{
		while (dest[i])
		{
			res[i] = dest[i];
			i++;
		}
	}
	j = 0;
	while (src[j] != 0)
	{
		res[i] = src[j];
		i++;
		j++;
	}
	return (res);
}
