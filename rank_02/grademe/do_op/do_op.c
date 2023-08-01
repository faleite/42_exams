#include <stdlib.h>
#include <stdio.h>

int	do_op(char *nbr1, char *op, char *nbr2)
{
	int	nb1;
	int nb2;
	int	result;

	nb1 = atoi(nbr1);
	nb2 = atoi(nbr2);
	result = 0;
	if (op[0] == '+')
		result = nb1 + nb2;
	else if (op[0] == '-')
		result = nb1 - nb2;
	else if (op[0] == '*')
		result = nb1 * nb2;
	else if (op[0] == '/')
		result = nb1 / nb2;
	else if (op[0] == '%')
		result = nb1 % nb2;
	return (result);
}

int	main(int ac, char *av[])
{
	if (ac == 4)
		printf("%d", do_op(av[1], av[2], av[3]));
	printf("\n");
	return (0);
}
