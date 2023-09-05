/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/

#include <stdio.h>
#include <string.h>

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

/** FT_STRSPN
 * @brief The strspn() function calculates the length (in bytes) of the initial
 * segment of s which consists entirely of bytes in accept.
 * @return returns the number of bytes in the initial segment of s which consist
 * only of bytes from accept.
*/
size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(accept, s[i]) == 0)
			break ;
		i++;
	}
	return (i);
}



int	main(void)
{
	const char s[] = "Test odeC ode";
	const char accept[] = "  TeCst od";

	printf("%ld\n", strspn(s, accept));
	printf("%ld\n", ft_strspn(s, accept));
	return (0);
}
