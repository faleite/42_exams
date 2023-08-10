
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	last_word_len(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	while (str[len] == ' ' || str[len] == 't')
		len--;
	while (str[len] > 32)
		len--;
	return (len + 1);
}

void	last_word(char *str)
{
	int	len;

	len = last_word_len(str);
	while (str[len] > 32 && str[len] != '\0')
		write(1, &str[len++], 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
