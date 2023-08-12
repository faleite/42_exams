
#include <stdlib.h>
#include <stdio.h>

int	len_array(int start, int end)
{
	if (end < 0)
		end *= -1;
	if (end > start)
		return ((end - start) + 1);
	if (end < start)
		return ((start - end) + 1);
	return (1);
}

int	*ft_range(int start, int end)
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
		array[i] = start;
		if (start < end)
			start++;
		else
			start--;
		i++;
	}
	return (array);
}

int	main(void)
{
	int	len;
	int	*arr;
	int	start;
	int	end;

	start = 0;
	end = -3;
	len = len_array(start, end);
	arr = ft_range(start, end);

	printf("Tamanho do array: %d\n", len);
	while (len--)
		printf("%d ", *arr++);
	return (0);
}
