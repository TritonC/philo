/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:22:11 by lgomes-o          #+#    #+#             */
/*   Updated: 2023/03/15 09:23:28 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char	*ft_strnstr(const char *b, const char *s, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s == '\0')
		return ((char *)b);
	while (*(b + i) != '\0' && (i < len))
	{
		j = 0;
		if (*(b + i) == *(s + j))
		{
			while (*(b + (i + j)) == *(s + j) && i + j < len)
			{
				if (*(s + (j + 1)) == '\0')
					return (((char *)b + i));
				j++;
			}
		}
		i++;
	}
	return (0);
}
