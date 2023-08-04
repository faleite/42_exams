#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	rev_print(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i)
		write(1, &str[--i], 1);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		rev_print(av[1]);
	write(1, "\n", 1);
	return (0);
}
