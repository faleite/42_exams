/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:56:42 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/02 17:00:10 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	if (s[len] == '\n')
		return (len + 1);
	return (len);
}

char	*join_line(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(s3))
		return (NULL);
	while (s1 && s1[i])
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		s3[j++] = s2[i];
		if (s2[i++] == '\n')
			break ;
	}
	s3[j] = '\0';
	free(s1);
	return (s3);
}

size_t	clear_line(char *buff)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	res = 0;
	while (buff[i])
	{
		if (res)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			res = 1;
		buff[i] = 0;
		i++;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (buff[0] || (read(fd, buff, BUFFER_SIZE) > 0))
	{
		line = join_line(line, buff);
		if (clear_line(buff) == 1)
			break ;
		if (read(fd, buff, BUFFER_SIZE) < 0)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test1.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}