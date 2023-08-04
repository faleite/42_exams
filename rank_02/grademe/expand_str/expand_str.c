#include <unistd.h>

void	expand_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < 33 && str[i + 1] > 32)
			write(1, "   ", 3);
		else if (str[i] > 32)
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		expand_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
