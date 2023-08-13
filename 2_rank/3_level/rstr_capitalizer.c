
#include <unistd.h>

void	rstr_capitalizer(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if ((s[i] >= 'a' && s[i] <= 'z')
			&& (s[i + 1] < 33 || s[i + 1] == '\0'))
			s[i] -= 32;
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			rstr_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
