/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:35:46 by quenalla          #+#    #+#             */
/*   Updated: 2024/07/17 09:57:38 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (char)c != *s)
		s++;
	if (*s == (char)c)
		return ((char *) s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	str = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str == NULL)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		dest[i + k] = s2[k];
		k++;
	}
	dest[i + k] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			k;
	char			*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		str = malloc(1);
	else if (len > (ft_strlen(s) - start))
		str = malloc((ft_strlen(s) - start) + 1);
	else
		str = malloc(len + 1);
	if (str == NULL)
		return (0);
	i = 0;
	k = 0;
	while (s[i])
	{
		if (i >= start && k < len)
			str[k++] = (char)s[i];
		i++;
	}
	str[k] = '\0';
	return (str);
}
