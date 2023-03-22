/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:50:11 by lgomes-o          #+#    #+#             */
/*   Updated: 2023/03/15 09:21:21 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == (char)c)
			return (((char *)str + i));
		i++;
	}
	if (c == '\0')
		return (((char *)str + i));
	return (0);
}
