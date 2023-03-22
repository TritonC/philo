/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:41:01 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/15 09:44:23 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void    ft_memfree(void **double_pointer, void *simple_pointer)
{
    size_t  i;

    if (double_pointer)
    {
        i = 0;
        while (double_pointer[i])
        {
            free(double_pointer[i]);
            i++;
        }
        free(double_pointer);
    }
    if (simple_pointer)
        free(simple_pointer);
}
