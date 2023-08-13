
#include <unistd.h>

void	expand_str(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] == ' ' || s[i] == '\t') && s[i + 1] > 32)
			write(1, "   ", 3);
		if (!(s[i] == ' ' || s[i] == '\t'))
			write(1, &s[i], 1);
		i++;
	}

}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
