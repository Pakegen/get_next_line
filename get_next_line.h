/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:56:51 by quenalla          #+#    #+#             */
/*   Updated: 2024/07/03 10:21:14 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif


#ifndef MAX_FD
# define MAX_FD 1024
#endif

char			*get_next_line(int fd);

static size_t	ft_strlen(char *str);

static char		*ft_strchr(const char *s, int c);

static char		*ft_strjoin(char const *s1, char const *s2);

static char		*ft_substr(char const *s, unsigned start, size_t len);

static char		*ft_strdup(char const *s);

#endif
