#include <stdlib.h>
#include <stdio.h>

int	arr_len(int start, int end)
{
	int	total;

	total = end - start;

	if (total < 0)
		total *= -1;
	return (total + 1);
}

int	*arr(int	*array, int start, int end, int sig, int index)
{

	if (start !=  end)
		array = arr(array, start, end + sig, sig, index  + 1);
	else
		array = malloc(sizeof(int) * index + 1);
	if (array)
		array[index] = end;
	return (array);
}

int	*ft_rrange(int start, int end)
{
	// int	*array;
	// int	len;
	// int	i;

	// i = 0;
	// len = arr_len(start, end);
	// array = NULL;
	// array = malloc(sizeof(int) * len);
	// if (!array)
	// 	return (NULL);
	// while (len--)
	// {
	// 	array[i++] = end;
	// 	if (start > end)
	// 		end++;
	// 	else
	// 		end--;

	// }
	return arr(NULL, start, end, (start >= end) - (start < end), 0);
}

int	main(void)
{
	int len;
	int start = -1;
	int end = 2;
	int	*arr;

	arr = ft_rrange(start, end);
	len = arr_len(start, end);
	while (len--)
	{
		printf("%d ", *arr++);
	}
	return (0);
}

