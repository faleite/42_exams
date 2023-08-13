
#include <unistd.h>
#include <stdio.h>

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

int	ft_atoi(char *nb)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (nb[i] != '\0')
	{
		n *= 10;
		n += nb[i++] - 48;
	}
	return (n);
}

int	is_prime(int nbr)
{
	int	i;

	i = 2;
	while (i <= nbr)
	{
		if (nbr % i == 0)
		{
			if (nbr == i)
				return (1);
			else
				break ;
		}
		i++;
	}
	return (0);
}

int	add_prime_sum(int n)
{
	int	i;
	int	result;

	if (n == 1)
		return (1);
	i = 2;
	result = 0;
	while (i <= n)
	{
		if (is_prime(i))
			result += i;
		i++;
	}
	return (result);
}


int	main(int argc, char *argv[])
{
	int	result;

	result = 0;
	if (argc == 2)
	{
		result = add_prime_sum(ft_atoi(argv[1]));
		ft_putnbr(result);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
