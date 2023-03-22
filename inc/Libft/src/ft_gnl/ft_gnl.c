/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:29:57 by mluis-fu          #+#    #+#             */
/*   Updated: 2023/03/15 08:33:46 by mluis-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_and_free(char *buffer, char *sub_bufer)
{
	char	*aux;

	aux = ft_strjoin_gnl(buffer, sub_bufer);
	free(buffer);
	return (aux);
}

char	*check_line(char *str)
{
	int		count;
	char	*line;

	count = 0;
	if (!str[count])
		return (NULL);
	while (str[count] && str[count] != '\n')
		count++;
	line = ft_calloc(count + 2, sizeof(char));
	count = 0;
	while (str[count] && str[count] != '\n')
	{
		line[count] = str[count];
		count++;
	}
	if (str[count] == '\n' && str[count])
		line[count] = '\n';
	return (line);
}

char	*read_and_save(int fd, char *buff)
{
	char	*sub_buff;
	ssize_t	bytes_count;

	if (!buff)
		buff = ft_calloc(1, 1);
	sub_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!sub_buff)
		return (NULL);
	bytes_count = 1;
	while (bytes_count > 0)
	{
		bytes_count = read(fd, sub_buff, BUFFER_SIZE);
		if (bytes_count == -1)
		{
			free (sub_buff);
			free (buff);
			return (NULL);
		}
		sub_buff[bytes_count] = '\0';
		buff = ft_join_and_free(buff, sub_buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free (sub_buff);
	return (buff);
}

char	*rest_of_file(char *buffer)
{
	int		i;
	int		j;
	char	*sub_buffer;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	sub_buffer = ft_calloc(ft_strlen(buffer) - i + 1, 1);
	i++;
	j = 0;
	while (buffer[i])
		sub_buffer[j++] = buffer [i++];
	free (buffer);
	return (sub_buffer);
}

char	*get_next_line(int fd)
{
	char		*line_print;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_save (fd, buffer);
	if (!buffer)
		return (NULL);
	line_print = check_line(buffer);
	buffer = rest_of_file(buffer);
	return (line_print);
}
