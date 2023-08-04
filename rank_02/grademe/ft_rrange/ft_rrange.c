#include <stdlib.h>
#include <stdio.h>

int	index_len(int start, int end)
{
	if (!start && !end)
		return (0);
	if (end < 0)
		end *= -1;
	return ((end - (start)) + 1); 
}

int	*ft_rrange(int start, int end)
{
	int	*array;
	int	len;
	int	i;
	
	len = index_len(start, end);
	i = 0;
	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	while (len--)
	{
		array[i++] = end;
		if (start > end)
			end++;
		else
			end--;
	}
	return (array);
}
/*
int	main(int ac, char *av[])
{
	(void)ac;
	int a;
	int b;
	int *array;

	a = atoi(av[1]);
	b = atoi(av[2]);
	int len = index_len(a, b) + 1;
	
	array = ft_rrange(a, b);
	while (len--)
		printf("%d ", *array++);
	return(0);
}
*/
