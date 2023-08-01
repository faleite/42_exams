#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n /= 2;
	if (n == 1)
		return (1);
	return (0);
}

/* int	main(void) */
/* { */
	/* printf("%d\n", is_power_of_2(1)); */
	/* return (0); */
/* } */
