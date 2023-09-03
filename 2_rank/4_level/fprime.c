
#include <stdio.h>
#include <stdlib.h>

void	fprime(int n)
{
	int	i;

	if (n == 1)
	{
		printf("1");
		return ;
	}
	i = 2;
	while (n >= i)
	{
		if (n % i == 0)
		{
			printf("%d", i);
			if (n != i)
				printf("*");
			n /= i;
			i--;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
