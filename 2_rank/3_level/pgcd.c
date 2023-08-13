#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	if (a > 0 && b > 0)
	{
		while (a != b)
		{
			if (a > b)
				a -= b;
			else
				b -= a;
		}
	}
	printf("%d", a);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}
