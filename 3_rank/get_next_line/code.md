##  get_next_line.h

```c
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif // BUFFER_SIZE

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);

#endif // GET_NEXT_LINE
```

## get_next_line.c

```c
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
```

##  main

```c
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
```