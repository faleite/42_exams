/*** Subject ***//*

Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);

*//*** Man ***//*

DESCRIPTION:
The strspn() function calculates the length (in bytes) of the initial segment of
s which consists entirely of bytes in accept.

RETURN:
The strspn() function returns the number of bytes in the initial segment of s 
which consist only of bytes from accept.

*//*** Code ***/

#include <string.h>

/* Make the strchr function */
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (0);
}
/* Make the ft_strspn function */
size_t	ft_strspn(const char *s, const char *accept)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (ft_strchr(accept, s[i]) == 0)
			break ;
		i++;
	}
	return (i);
}


#include <stdio.h>

int	main(void)
{
	char haystack[] = "This is a test string";
	char accept[] = "tgaThis";

	printf("%zu\n", ft_strspn(haystack, accept));
	printf("Original: %zu\n", strspn(haystack, accept));
}
