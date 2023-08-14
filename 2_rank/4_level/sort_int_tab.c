
#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				tmp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	main(void)
{
	int				i;
	unsigned int	size;

	int	tab[] = {2, 5, 1, 4, 3};
	size = 5;
	i = 0;
	sort_int_tab(tab, size);
	while (i < size)
		printf("%d ", tab[i++]);
}
