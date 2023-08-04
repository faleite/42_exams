
#include <unistd.h>
#include <stdio.h>

void	last_word(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] < 33 && str[i + 1] > 32)
			j = i;
		i++;
	}
	while (str[j])
	{
		if (str[j] > 32)
			write(1, &str[j], 1);
		j++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}
