/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:08:39 by lgomes-o          #+#    #+#             */
/*   Updated: 2023/03/15 09:23:03 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (s != NULL)
	{
		str = (char *) ft_calloc(ft_strlen(s) + 1, sizeof(char));
		if (str == NULL)
			return (NULL);
		i = 0;
		while (*(s + i) != '\0')
		{
			*(str + i) = f(i, (char)*(s + i));
			i++;
		}
		return (str);
	}
	return (NULL);
}
