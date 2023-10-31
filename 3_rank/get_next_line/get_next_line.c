/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:56:42 by faaraujo          #+#    #+#             */
/*   Updated: 2023/10/31 20:33:52 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		r;
	char	c;
	char	*buff;

	i = 0;
	r = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(100000);
	while ((r = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		buff[i++] = c;
		if (c == '\n')
			break ; 
	}
	buff[i] = '\0';
	if (r == -1 || i == 0 || (!buff[i - 1] && !r))
		return (free(buff), NULL);
	return (buff);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test1.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
