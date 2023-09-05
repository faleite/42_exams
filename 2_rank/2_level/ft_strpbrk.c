#include <string.h>
#include <stdio.h>

/** FT_STRPBRK
 * @brief The strpbrk() function locates the first occurrence in the string s
 * of any of the bytes in the string accept.
 * @return The strpbrk() function returns a pointer to the byte in s
 * that matches one of the bytes in accept, or NULL if no such byte is found.
*/
char	*ft_strpbrk(const char *s1, const char *s2)
{
	int		j;

	while (*s1 != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (*s1 == s2[j])
				return ((char *)s1);
			j++;
		}
		s1++;
	}
	return (0);
}

/********************/
/* About last exame */
/********************/
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
