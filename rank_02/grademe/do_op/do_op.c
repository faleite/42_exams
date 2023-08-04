#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	do_op(char *nb1, char op[0], char *nb2)
{
	int	nbr1;
	int	nbr2;
	int	result;

	nbr1 = atoi(nb1);
	nbr2 = atoi(nb2);
	result = 0;
	if (op[0] == '+')
		result = nbr1 + nbr2;
	else if (op[0] == '-')
		result = nbr1 -	nbr2;
	else if (op[0] == '*')
		result = nbr1 * nbr2;
	else if (op[0] == '/')
		result = nbr1 / nbr2;
	else if (op[0] == '%')
		result = nbr1 % nbr2;
	return (result);
}

int	main(int ac, char *av[])
{
	if (ac == 4)
		printf("%d", do_op(av[1], av[2], av[3]));
	printf("\n");
	return (0);
}
