/*
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/

#include <unistd.h>

/*******************/
/* My first option */
/*******************/
int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	rev_print(char *s)
{
	int	len;

	len = ft_strlen(s);
	while (len)
		write(1, &s[--len], 1);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		rev_print(av[1]);
	write(1, "\n", 1);
	return (0);
}

/***********************/
/* More complex option */
/***********************/
int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(1, &s[i++], 1);
}

void	rev_print(char *s)
{
	int		len;
	int		i;
	char	tmp;

	len = ft_strlen(s) - 1;
	i = 0;
	while (i < len)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = s[i];
		len--;
		i++;
	}
	ft_putstr(s);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		rev_print(av[1]);
	write(1, "\n", 1);
	return (0);
}
