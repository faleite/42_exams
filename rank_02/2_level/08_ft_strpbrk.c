/*** Subject ***//*

Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);

*//*** Man ***//*

DESCRIPTION:
A função strpbrk() localiza a primeira ocorrência na string s1 de qualquer um dos
bytes na string s2.

RETURN:
A função strpbrk() retorna um ponteiro para o byte em s1 que corresponde a um dos
bytes em accept, ou NULL se nenhum byte for encontrado.

*//*** Code ***/

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i;

	if (!s1 || !s2)
		return (0);
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return ((char *) s1);
			i++;
		}
		s1++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[] = "Texto de test";
	char s2[] = "eds";

	printf("Original: %s\n", strpbrk(s1, s2));
	printf("Minha ft: %s", ft_strpbrk(s1, s2));
	return (0);
}
