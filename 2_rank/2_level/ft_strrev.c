/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		len;

	len = ft_strlen(str) - 1;
	i = 0;
	// a cada vez e trocado dois index
	// a quantidade de torca deve ser a metade do tamnho da string
	while (len > i)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}

int	main(void)
{
	char str[] = "987654321";

	printf("%s", ft_strrev(str));
	return (0);
}
