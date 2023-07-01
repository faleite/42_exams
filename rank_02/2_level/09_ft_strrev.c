/*** Subject ***//*

Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);

*//*** Code ***/

char	*ft_strrev(char *s)
{
	int i = 0;
	int len = 0;
	char tmp;

	while (s[len])
		len++;
	len = len - 1;
	while (len > i)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		i++;
		len--;
	}
	return (s);
}

#include <stdio.h>

int	main(void)
{
	char s[] = "Abcd";

	printf("%s", ft_strrev(s));
	return (0);
}
