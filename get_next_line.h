/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:56:51 by quenalla          #+#    #+#             */
/*   Updated: 2024/06/24 08:51:19 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif


#ifndef MAX_FD
# define MAX_FD 1024
#endif

char	*get_next_line(int fd);

char	*ft_strchr(char *str, int c);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strdup(char *src);


#endif
