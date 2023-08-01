#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	int j = 0;

	while (s[i])
	{

		j = 0;
		while (s[i] != reject[j] && reject[j])
			j++;
		if (!reject[j])
			i++;
		else
			return (i);
	}
	return (i);
}

/*
int	main()
{
	char s1[] = "Hello Wolrd!";
	char s2[] = "Wolrd!";

	printf("%lu\n", strcspn(s1, s2));
	printf("%lu", ft_strcspn(s1, s2));
	return (0);
}
*/
