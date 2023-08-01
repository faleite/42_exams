#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putstr(char *nbr)
{
	while (*nbr)
		write(1, nbr++, 1);
}

int	ft_atoi(char *nbr)
{
	int i = 0;
	int res = 0;

	while (nbr[i])
	{
		res *= 10;
		res += nbr[i] - 48;
		i++;
	}
	return (res);
}

void	putnbr(int nb)
{
	if (nb < 10)
		putchar(nb + 48);
	else
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
}

void	 tab_mult(char *nbr)
{
	int nb;
	int i;

	nb = ft_atoi(nbr);
	i = 1;
	while (i <= 9)
	{
		putnbr(i);
		write(1, " x ", 3);
		putnbr(nb);
		write(1, " = ", 3);
		putnbr(nb * i);
		if (i < 9)
			putchar('\n');
		i++;
	}
	
}

int 	main(int ac, char **av)
{
	if (ac == 2)
		tab_mult(av[1]);
	putchar('\n');
	return (0);
}
