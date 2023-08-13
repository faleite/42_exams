
#include <stdlib.h>
#include <stdio.h>

int	len_array(int start, int end)
{
	if (end < 0)
		end *= -1;
	if (start < end)
		return ((end - start) + 1);
	if (start > end)
		return ((end + start) + 1);
	return (1);
}

int	*ft_rrange(int start, int end)
{
	int	*array;
	int	len;
	int	i;

	i = 0;
	len = len_array(start, end);
	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	while (i < len)
	{
		array[i] = end;
		if (start < end)
			end--;
		else
			end++;
		i++;
	}
	return (array);
}

// int	main(void)
// {
// 	int	*arr;
// 	int	len;

// 	len = len_array(0, 0);
// 	arr = ft_rrange(0, 0);
// 	while (len--)
// 	{
// 		printf("%d ", *arr++);
// 	}
// 	return (0);
// }
