
#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

/*
int	main(void)
{
	const char *s1 = "Text string";
	const char *rej = "s";

	printf("%ld", strcspn(s1, rej));
	printf("%ld", ft_strcspn(s1, rej));
	return (0);
}
*/
