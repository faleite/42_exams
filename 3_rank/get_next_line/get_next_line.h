/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:59:04 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/02 16:40:42 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif // BUFFER_SIZE

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

/* Pincipal */
char	*get_next_line(int fd);

/* Utils */
size_t	ft_strlen(char *s);
char	*join_line(char *s1, char *s2);
size_t	clear_line(char *buff);

#endif // GET_NEXT_LINE_H