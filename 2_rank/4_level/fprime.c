
#include <stdio.h>
#include <stdlib.h>

void	fprime(int nbr)
{
	int	i;

	if (nbr == 1)
	{
		printf("1");
		return ;
	}
	i = 2;
	while (nbr > 1)
	{
		if (nbr % i == 0)
		{
			nbr /= i;
			printf("%d", i);
			if (nbr > 1)
				printf("*");
			i = 2;
		}
		else
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
