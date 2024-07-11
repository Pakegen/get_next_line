/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:39:06 by qacjl             #+#    #+#             */
/*   Updated: 2024/07/11 13:15:25 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	ft_free(char **buffer)
{
	if (*buffer != NULL)
	{
		free(*buffer);
		buffer = NULL;
	}
}

char	*ft_set_ligne(char **buffer)
{
	char	*tmp;
	char	*res;
	int		i;

	i = 0;
	while (*buffer[i] && *buffer[i] != '\n')
		i++;
	if (i == 0)
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
	tmp = ft_substr(*buffer, i + 1, BUFFER_SIZE);
	res = *buffer;
	res[i + 1] = 0;
	*buffer = tmp;
	return (res);
}

char	*ft_ligne_lue(int fd, char **buffer, char *str)
{
	char	*tmp;
	char	*ligne;
	ssize_t	byte_read;

	ligne = ft_strchr(*buffer, '\n');
	byte_read = 1;
	tmp = NULL;
	while (ligne == NULL)
	{
		byte_read = read(fd, str, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (byte_read == 0)
			return (ft_set_ligne(buffer));
		str[byte_read] = 0;
		tmp = ft_strjoin(*buffer, str);
		ft_free(buffer);
		*buffer = tmp;
		ligne = ft_strchr(*buffer, '\n');
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
	res = ft_ligne_lue(fd, &buffer[fd], str);
	free(str);
	str = NULL;
	return (res);
}
