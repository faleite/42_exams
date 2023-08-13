
#include <unistd.h>

int	ft_atoi(char *nb)
{
	int	n;

	n = 0;
	while (*nb)
	{
		n *= 10;
		n += *nb - 48;
		++nb;
	}
	return (n);
}

void	ft_putnbr(int nb)
{
	if (nb < 10)
		write(1, &"0123456789"[nb], 1);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	tab_mult(int nb)
{
	int	i;

	i = 0;
	while (++i < 10)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(nb);
		write(1, " = ", 3);
		ft_putnbr(i * nb);
		if (i < 9)
			write(1, "\n", 1);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		tab_mult(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
