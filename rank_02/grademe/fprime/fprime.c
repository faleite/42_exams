#include <stdio.h>
#include <stdlib.h>

void	fprime(char *nbr)
{
	int	i;
	int	number;

	i = 1;
	number = atoi(nbr);
	if (number == 1)
		printf("1");
	while (number >= ++i)
	{
		if (number % i == 0)
		{
			printf("%d", i);
			if (number == i)
				break ;
			printf("*");
			number /= i;
			i = 1;
		}
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		fprime(av[1]);
	printf("\n");
	return (0);
}
