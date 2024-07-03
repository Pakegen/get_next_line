/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nouveau_get_next_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:28:07 by quenalla          #+#    #+#             */
/*   Updated: 2024/07/03 14:41:11 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer[MAX_FD + 1];
	char	*res;
	char	*str;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!(str))
		return (NULL);
	if (!(buffer[fd]))
		buffer[fd] = ft_strdup("");
	res = read_line(fd, &buffer[fd], str);
	ft_free(&str);
	return (res);
}

char	*read_line(int fd, char **buffer, char *str)
{
	ssize_t	byte_read;
	char	*tmp;
	char	*check;

	tmp = NULL;
	check = ft_strchr(*buffer, '\n');
	while (check == NULL)
	{
		byte_read = read(fd, str, BUFFER_SIZE);
		if (byte_read <= 0)
			return (ft_join_line(byte_read, buffer));
		str[byte_read] = '\0';
		tmp = ft_strjoin(*buffer, str);
		ft_free(buffer);
		*buffer = tmp;
		check = ft_strchr(*buffer, '\n');
	}
	return (ft_joint_line(check - *buffer + 1, buffer));
}

void	ft_free(char **ptr)
{
	if (*ptr != '\0')
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_join_line(int position, char **buffer)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (position <= 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer, position, BUFFER_SIZE);
	res = *buffer;
	res[position] = '\0';
	*buffer = tmp;
	return (res);
}
