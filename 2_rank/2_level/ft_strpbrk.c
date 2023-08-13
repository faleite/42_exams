/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
*/

#include <string.h>
#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i;
	char *str;

	str = (char *)s1;
	while (*str != '\0')
	{
		i = 0;
		while (s2[i] != '\0')
		{
			if (*str == s2[i++])
				return (str);
		}
		str++;
	}
	return (NULL);
}

int	main(void)
{
	const char	*s = "Test code";
	const char	*accept = "";

	printf("%s\n", strpbrk(s, accept));
	printf("%s\n", ft_strpbrk(s, accept));
	return (0);
}
