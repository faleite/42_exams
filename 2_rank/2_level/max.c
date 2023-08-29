
#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int		result;
	unsigned int	i;

	if (!len)
		return (0);
	i = 0;
	result = tab[i];
	while (i < len)
	{
		if (result < tab[i])
			result = tab[i];
		i++;
	}
	return (result);
}

int main(void)
{
	int len = 13;
	int	array[] = {2, 0, 4, 5, 1, 3, 10, 1, 5, 16, 1, 12, 18};

	printf("%d", max(array, len));
	return (0);
}
