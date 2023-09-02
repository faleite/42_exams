
#include <stdlib.h>
#include <stdio.h>

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	*ft_rrange(int start, int end)
{
	int	*arr;
	int	len;
	int	i;

	i = 0;
	len = ft_abs(end - start) + 1;
	arr = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		if (start < end)
		{
			arr[i] = end;
			end--;
			i++;
		}
		else
		{
			arr[i] = end;
			end++;
			i++;
		}
	}
	return (arr);
}
/*
int	main(void)
{
	int	*tab = ft_rrange(0, -3);
	int	len = ft_abs(-3 - 0) + 1;

	while (len--)
		printf("%d ", *tab++);
	return (0);
}
*/
