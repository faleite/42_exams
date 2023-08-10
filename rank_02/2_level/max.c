
#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	unsigned int i;

	i = 0;
	while (len--)
	{
		while (tab[0] < tab[i])
		{
			tab[0] = tab[i];
		}
		i++;
	}
	return (tab[0]);
}

int main(void)
{
	int len = 13;
	int	array[] = {2, 0, 4, 5, 1, 3, 10, 1, 5, 16, 1, 12, 18};

	printf("%d", max(array, len));
	return (0);
}
