
#include <stdio.h>
#include <string.h>

/**
 * @brief The strcspn() function calculates the length of the initial
 * segment of s which consists entirely of bytes not in reject.
 * @return The strcspn() function returns the number of bytes in the initial
 * segment of s which are not in the string reject.
*/
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


int	main(void)
{
	const char *s1 = "Text string";
	const char *rej = "s";

	printf("%ld\n", strcspn(s1, rej));
	printf("%ld\n", ft_strcspn(s1, rej));
	return (0);
}
