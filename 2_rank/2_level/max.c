/** MAX
* Assignment name  : max
* Expected files   : max.c
* Allowed functions:
* --------------------------------------------------------------------------------
*
* Write the following function:
*
* int		max(int* tab, unsigned int len);
*
* The first parameter is an array of int, the second is the number of elements in
* the array.
*
* The function returns the largest number found in the array.
*
* If the array is empty, the function returns 0.
*/
#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int		result;
	unsigned int	i;

	/* if (!len || tab == NULL) */
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
