/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

/* #include <> */

/* Function write char x nbr index of char */

/* Function write string with repeat of alpha */

/* Program with param */

#include <unistd.h>

void	putchar(char c, int n)
{
	while (n)
	{
		write(1, &c, 1);
		n--;
	}
}

void	repeat_alpha(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			putchar(s[i], ((s[i] - 'A') + 1));
		else if (s[i] >= 'a' && s[i] <= 'z')
			putchar(s[i], ((s[i] - 'a') + 1));
		else
			write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}
