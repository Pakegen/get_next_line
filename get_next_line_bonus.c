/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:56:06 by quenalla          #+#    #+#             */
/*   Updated: 2024/07/17 10:10:19 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

static char	*ft_set_ligne(char *buffer)
{
	char	*tmp;
	char	*res;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (i == 0)
	{
		if (buffer[i] == '\0')
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		res = buffer;
		buffer = NULL;
		return (res);
	}
	tmp = ft_substr(buffer, i + 1, BUFFER_SIZE);
	res = buffer;
	res[i + 1] = 0;
	buffer = tmp;
	return (res);
}

static char	*ft_ligne_lue(int fd, char *buffer, char *str)
{
	char	*tmp;
	ssize_t	byte_read;

	byte_read = 1;
	tmp = NULL;
	while (!ft_strchr(buffer, '\n'))
	{
		byte_read = read(fd, str, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (byte_read == 0)
			return (ft_set_ligne(buffer));
		str[byte_read] = '\0';
		tmp = ft_strjoin(buffer, str);
		free(buffer);
		buffer = NULL;
		buffer = tmp;
	}
	return (ft_set_ligne(buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer[LIMIT_FD];
	char		*str;
	char		*res;

	if (fd > LIMIT_FD || BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	res = ft_ligne_lue(fd, buffer[fd], str);
	free(str);
	str = NULL;
	return (res);
}
