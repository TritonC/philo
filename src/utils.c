/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:50:27 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/22 14:22:29 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	error_msg(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (write(1, &str, i));
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	num;
	size_t	counter;
	char	*mem;

	num = count * size;
	counter = 0;
	mem = NULL;
	if (num < size && num < count)
		return (NULL);
	mem = malloc(num);
	if (!mem)
		return (NULL);
	while (counter < num)
		mem[counter++] = 0;
	return ((void *)mem);
}

int	ft_atoi(const char *str)
{
	long long int		r;
	long long int		s;
	size_t				i;

	i = 0;
	if (*(str + i) == '\0')
		return (0);
	while ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	s = 1;
	if (*(str + i) == 45)
			s *= -1;
	if (*(str + i) == 45 || *(str + i) == 43)
		i++;
	r = 0;
	while (*(str + i) >= 48 && *(str + i) <= 57)
	{
		r = ((r * 10) + (*(str + i) - 48) * s);
		i++;
		if (r < -2147483648)
			return (0);
		if (r > 2147483647)
			return (-1);
	}
	return (r);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *) ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j) != '\0')
	{
		*(str + i) = *(s2 + j);
		j++;
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
