/*** Subject ***//*

Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>

*//*** Code ***/

#include <unistd.h>

int	check_double(int c, char *s, int index)
{
	int i = 0;

	while (i < index)
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		s1[i++] = s2[j++];
	i--;
	j = 0;
	while (j <= i)
	{
		if (check_double(s1[j], s1, j) == 1)
			write(1, &s1[j], 1);
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
