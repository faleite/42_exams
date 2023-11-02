/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:49:30 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/02 17:43:48 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	put_string(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}

void	put_digit(long long int number, int base, int *length)
{
	char	*hexadecimal = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, length);
	*length += write(1, &hexadecimal[number % base], 1);
}

int ft_printf(const char *fmt, ...)
{
	int	len;

	len = 0;
	va_list ptr;
	va_start(ptr, fmt);
	while(*fmt)
	{
		if ((*fmt == '%') && ((*(fmt + 1) == 's') || (*(fmt + 1) == 'd') ||
			(*(fmt + 1) == 'x')))
		{
			fmt++;
			if (*fmt == 's')
				put_string(va_arg(ptr, char *), &len);
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