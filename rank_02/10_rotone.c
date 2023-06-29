/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *str)
{
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'y') 
			|| (*str >= 'A' && *str <= 'Y'))
			putchar(*str + 1);
		else if (*str == 'z')
			putchar('a');
		else if (*str == 'Z')
			putchar('A');
		else
			putchar(*str);
		++str;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	putchar('\n');
	return (0);
}
