/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:56:51 by quenalla          #+#    #+#             */
/*   Updated: 2024/06/19 16:23:55 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdio.h>

char	*get_next_line(int fd);
/*strjoin
peut etre strnew
*/

#endif
