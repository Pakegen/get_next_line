/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:57:56 by quenalla          #+#    #+#             */
/*   Updated: 2024/06/21 11:42:09 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"


char	*line(int fd, char **buffer, char *str)
{
	ssize_t	byte_read;
	char	*tmp;
	char	*return_line;

	byte_read = 0;
	tmp = NULL;
	return_line = ft_strchr(str, '\n');
	while(return_line == NULL)
	{
		byte_read = read(fd, str, BUFFER_SIZE);
		if (byte_read <= 0)
			return (strjoin(*buffer, str));
		str[byte_read] = 0;
		tmp = ft_strjoin(*buffer, str);
		ft_free(buffer);
		*buffer = tmp;
		return_line = ft_strchr(*buffer, '\n');
	}
	return (join_line(return_line - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*str;
	char			*res;

	if(fd < 0 || MAX_FD < fd || BUFFER_SIZE <= 0)
		return (NULL);
	str = (char *)malloc(BUFFER_SIZE + 1);
	if (str == NULL)
		return (NULL);
	if(!buffer[fd])
		buffer[fd] = strdup("");
	res = line(fd, &buffer[fd], str)
}
