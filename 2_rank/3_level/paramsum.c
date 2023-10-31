
#include <unistd.h>


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

/************/
/* Option 1 */
/************/
int	main(int argc, char *argv[])
{
	(void)argv;
	// if (argc == 1)
	// 	write(1, "0", 1);
	// else
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}

/************/
/* Option 2 */
/************/
int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc > 1)
	{
		while (argv[i] != NULL)
			i++;
		i--;
		ft_putnbr(i);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
