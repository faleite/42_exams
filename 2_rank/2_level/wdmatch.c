/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (0);
}

int	len_wdmatch(char *s1, char *s2)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(s2, s1[i]))
		{
			s2 = ft_strchr(s2, s1[i]);
			len++;
		}
		i++;
	}
	return (len);
}

void	wdmatch(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(s2, s1[i]))
		{
			s2 = ft_strchr(s2, s1[i]);
			write(1, &*s2, 1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		if (len_wdmatch(argv[1], argv[2]) == ft_strlen(argv[1]))
			wdmatch(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}

// void ft_putstr(char const *str)
// {
// 	int i = 0;

// 	while (str[i])
// 		write(1, &str[i++], 1);
// }

// int	main(int argc, char const *argv[])
// {
// 	int i = 0;
// 	int j = 0;

// 	if (argc == 3)
// 	{
// 		while (argv[2][j])
// 			if (argv[2][j++] == argv[1][i])
// 				i += 1;
// 		if (!argv[1][i])
// 			ft_putstr(argv[1]);
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }
