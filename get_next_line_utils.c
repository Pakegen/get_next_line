/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:57:54 by quenalla          #+#    #+#             */
/*   Updated: 2024/06/24 08:50:53 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s1[i])
		i++;
	while (s2[k])
		s1[i + k]  = s2[k];
	s1[i + k] = '\0';
	return (s1);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	ft_duplication(src, dest);
	return (dest);
}

static void	ft_duplication(char *src, char *dest)
{
	int	i;
	int	k;

	i = 0;
	k = ft_strlen(src);
	dest[k] = '\0';
	while (i < k)
	{
		dest[i] = '\0';
	}
	i = 0;
	while (i < k)
	{
		dest[i] = src[i];
		i++;
	}
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		str[i++];
	return (i);
}
