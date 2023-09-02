/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/
#include <stdlib.h>
#include <stdio.h>

// Retorna o valor absoluto de um número
int	ft_abs(int x)
{
	int	sig;

	sig = -1;
	if (x < 0)
		return (x * sig);
	return (x);
}

/************/
/* Option 1 */
/************/
int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*arr;

	i = 0;
	len = ft_abs(start - end) + 1;
	arr = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		if (start < end)
		{
			arr[i] = start;
			start++;
			i++;
		}
		else
		{
			arr[i] = start;
			start--;
			i++;
		}
	}
	return (arr);
}

/************/
/* Option 2 */
/************/
int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*arr;

	i = 0;
	len = ft_abs(start - end) + 1;
	arr = (int *)malloc(sizeof(int) * len);
	while (start < end)
	{
		arr[i] = start;
		start++;
		i++;
	}
	arr[i] = start;
	while (start > end)
	{
		arr[i] = start;
		start--;
		i++;
	}
	arr[i] = start;
	return (arr);
}

int	main(void)
{
	int	*tab;
	int	len = ft_abs(0 - -3) + 1;

	printf("Len: %d\n", len);
	tab = ft_range(0, -3);
	while (len--)
		printf("%d ", *tab++);
	return (0);
}
