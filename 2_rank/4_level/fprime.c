
#include <stdlib.h>
#include <stdio.h>

int	is_prime(int nb)
{
	int	i;

	i = 2;
	while (1)
	{
		if (nb % i == 0)
		{
			if (nb == i)
				return (1);
			else
				break ;
		}
		i++;
	}
	return (0);
}

void	ftprime(int nb)
{
	int	i;

	i = 2;
	while (nb > 1)
	{
		if (is_prime(i) && nb % i == 0)
		{
			printf("%d", i);
			nb /= i;
			if (nb > 1)
				printf("*");
			i = 2;
		}
		else
			i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ftprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
