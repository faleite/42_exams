
#include <stdio.h>
#include <stdlib.h>

int	do_op(const char *nb1, const char *op, char *nb2)
{
	int	n1;
	int	n2;
	int	result;

	n1 = atoi(nb1);
	n2 = atoi(nb2);
	result = 0;
	if (op[0] == '+')
		result = n1 + n2;
	else if (op[0] == '-')
		result = n1 - n2;
	else if (op[0] == '*')
		result = n1 * n2;
	else if (op[0] == '/')
		result = n1 / n2;
	else if (op[0] == '%')
		result = n1 % n2;
	return (result);
}

int	main(int argc, char *argv[])
{
	if (argc == 4)
		printf("%d", do_op(argv[1], argv[2], argv[3]));
	printf("\n");
	return (0);
}
