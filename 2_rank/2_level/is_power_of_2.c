/** IS_POWER_OF_2
* Assignment name  : is_power_of_2
* Expected files   : is_power_of_2.c
* Allowed functions: None
* --------------------------------------------------------------------------------
*
* Write a function that determines if a given number is a power of 2.
*
* This function returns 1 if the given number is a power of 2, otherwise it returns 0.
*
* Your function must be declared as follows:
*
* int	    is_power_of_2(unsigned int n);
*/
int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
	{
		n /= 2;
		if (n == 1)
			return (1);
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d", is_power_of_2(0));
	return (0);
}
*/
