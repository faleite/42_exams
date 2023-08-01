#include <unistd.h>

void	str_cap(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z') 
			&& (i == 0 || str[i - 1] < 33))
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char *av[])
{
	int i = 1;
	
	while (av[i] != NULL)
	{
		str_cap(av[i]);
		i++;
	}
	if (ac == 1)
		write(1, "\n", 1);
	return (0);
}
