/*** Subject ***//*

Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.

*//*** Code ***/

int	max(int *tab, unsigned int len)
{
	unsigned int i = 0;
	int res = tab[i];

	while (i < len)
	{
		if (res < tab[i])
			res = tab[i];
		i++;
	}
	return (res);
}

#include <stdio.h>

int	main(void)
{
	int tab[] = {2, 1, 122, 4, 8};

	printf("%d", max(tab, 5));
	return (0);
}
