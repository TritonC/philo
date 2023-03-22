/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 02:08:23 by lgomes-o          #+#    #+#             */
/*   Updated: 2023/03/15 09:33:04 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/* Function that print a char variable. */
size_t	printf_char(char c)
{
	return (write(1, &c, 1));
}

/* Function that returns the length of a string variable. */
static size_t	print_str(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
	{
		write(1, (str + i), 1);
		i++;
	}
	return (i);
}

/* Function that print a string variable. */
size_t	printf_str(char *str)
{
	if (str == NULL)
		return (print_str("(null)"));
	else
		return (print_str(str));
}
