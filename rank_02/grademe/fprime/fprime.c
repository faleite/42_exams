#include <stdio.h>
#include <stdlib.h>

void	fprime(char *nbr)
{
	int	nb;
	int	i;
	
	nb = atoi(nbr);
	i = 1;
	if (nb == 1)
		printf("1");
	while (nb >= ++i)
	{
		while (nb % i == 0)
		{
			printf("%d", i);
			if (nb != i)
				printf("*");
			nb /= i;
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
