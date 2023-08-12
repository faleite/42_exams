
#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *nb)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (nb[i] != '\0')
	{
		nbr *= 10;
		nbr += nb[i] - 48;
		++i;
	}
	return (nbr);
}

void	print_hex(int nbr)
{
	if (nbr <= 16)
		write(1, &"0123456789abcdef"[nbr], 1);
	else
	{
		print_hex(nbr / 16);
		print_hex(nbr % 16);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
