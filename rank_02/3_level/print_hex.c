#include <stdlib.h>
#include <unistd.h>

#define hex "0123456789abcdef"


void	ft_hexa(int nb)
{
	int	len;

	len = 0;
	if (nb < 16)
		write(1, &hex[nb], 1);
	else
	{
		ft_hexa((nb / 16));
		ft_hexa((nb % 16));
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_hexa(atoi(av[1]));
}
