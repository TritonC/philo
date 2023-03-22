/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:58:12 by lgomes-o          #+#    #+#             */
/*   Updated: 2023/03/15 09:31:49 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_get_size(int num)
{
	long int		ln;
	size_t			i;

	i = 1;
	ln = num;
	if (ln < 0)
	{
		ln *= -1;
		i++;
	}
	while (ln >= 10)
	{
		ln /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	ln;
	size_t		size;
	size_t		i;

	size = ft_get_size(n);
	str = (char *) ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	ln = (long int)n;
	if (ln < 0)
	{
		*(str + i) = '-';
		ln *= -1;
	}
	i = size - 1;
	while (ln >= 10)
	{
		*(str + i) = (ln % 10) + '0';
		ln /= 10;
		i--;
	}
	*(str + i) = (ln % 10) + '0';
	return (str);
}
