
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

int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*arr;

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
