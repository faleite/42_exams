
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	last_word(char *s)
{
	int	len;

	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\t')
		len--;
	while (s[len] > 32)
		len--;
	len++;
	while (s[len] > 32)
		write(1, &s[len++], 1);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}

/*******************/
/* About last exam */
/*******************/
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
