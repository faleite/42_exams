
#include <unistd.h>

void	first_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] < 33 && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
			write(1, &str[i], 1);
		else
			break ;
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		first_word(av[1]);
	write(1, "\n", 1);
	return (0);
}
