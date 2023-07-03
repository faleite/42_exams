/**** Subject ***//*

Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

*//*** Code ***/

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(int nb)
{
	if (nb < 10)
		putchar(nb + '0');
	else
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
}

int	ft_atoi(char *s)
{
	int i = 0;
	int res = 0;

	while (s[i] != '\0')
	{
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	return (res);
}

int	is_prime(int nb)
{
	int i = 2;

	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	add_prime_sum(int nb)
{
	int i = 2;
	int prime_sum = 0;

	if (nb <= 0)
		return (0);
	while (i <= nb)
	{
		if (is_prime(i))
			prime_sum += i;
		i++;
	}
	return (prime_sum);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		putnbr(add_prime_sum(ft_atoi(av[1])));
	else
		putchar('0');
	putchar('\n');
	return (0);
}
