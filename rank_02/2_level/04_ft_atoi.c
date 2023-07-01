/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

/* se nao iniciar com + - ou numero, return 0 */
/* caso comecar com + ou - e proximo char nao for um numero, return 0 */
int	ft_atoi(const char *str)
{
	int i = 0;
	int pn = 1;
	int res = 0;

	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
		pn = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res *pn);
}

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%d\n", atoi(av[1]));
		printf("%d", ft_atoi(av[1]));
	}
	return (0);
}
