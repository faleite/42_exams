int	max(int *tab, unsigned int len)
{
	int i;
	int tmp;
	
	i = 0;
	while (i < len - 1)
	{
		if (tab[i] < tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = - 1;
		}
		i++;
	}
	return (tab[0]);
}

/*
#include <stdio.h>
int	main(void)
{
	int tab[] = {7, 42, 0, -5};
	printf("%d", max(tab, 4));
}
*/
