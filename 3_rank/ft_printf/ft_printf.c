/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:49:30 by faaraujo          #+#    #+#             */
/*   Updated: 2023/10/31 21:42:35 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// includes
#include <unistd.h>
#include <stdarg.h>

// put_str
void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

// put_digit
void	put_digit(long long int nbr, int base, int *len)
{
	char	*hd;

	hd = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		put_digit((nbr / base), base, len);
	*len += write(1, &hd[nbr % base], 1);
}

// ft_print
int	ft_printf(const char *fmt, ...)
{
	int	len;

	len = 0;
	va_list	ptr;
	va_start(ptr, fmt); 
	while (*fmt)
	{
		if ((*fmt == '%') && ((*(fmt + 1) == 's') || (*(fmt + 1) == 'd') ||
		(*(fmt + 1) == 'x')))
		{
			fmt++;
			if (*fmt == 's')
				put_str(va_arg(ptr, char *), &len);
			else if (*fmt == 'd')
				put_digit((long long int)va_arg(ptr, int), 10, &len);
			else if (*fmt == 'x')
				put_digit((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, fmt, 1);
		fmt++;
	}
	return (va_end(ptr), len);
}

int	main(void)
{
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	return (0);
}