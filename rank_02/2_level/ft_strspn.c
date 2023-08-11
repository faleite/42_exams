
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

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

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
	const char accept[] = " Test ";

	printf("%ld\n", strspn(s, accept));
	printf("%ld\n", ft_strspn(s, accept));
	return (0);
}
