
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


char	*ft_strdup(char *src)
{
	int		i;
	char	*dst;

	dst = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dst || !src)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/********************/
/* About last exame */
/*******************/
char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*dst;

	len = ft_strlen(src);
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst || !src)
		return (NULL);
	i = 0;
	while (*src != '\0')
		dst[i++] = *src++;
	dst[i] = '\0';
	return (dst);
}

// int	main(void)
// {
// 	char *s1 = "";
// 	char *s2;

// 	s2 = ft_strdup(s1);

// 	printf("%s", s2);
// 	free(s2);
// }
