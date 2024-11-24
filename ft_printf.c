/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:54:47 by leothoma          #+#    #+#             */
/*   Updated: 2024/11/24 01:54:47 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{	
	va_list	args;
	int		count;

	if (!*format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_args(*format, args);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	return (count);
}

int	ft_putchar(int c)
{
	return (write(1, (char *)&c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		n *= -1;
		count += write(1, "-", 1);
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
	{
		n += '0';
		count += write(1, &n, 1);
	}
	return (count);
}

int	ft_args(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, int)));
	if (c == 'x')
		return (ft_convert_hexa(va_arg(args, unsigned int),
				"0123456789abcdefg"));
	if (c == 'X')
		return (ft_convert_hexa(va_arg(args, unsigned int),
				"0123456789ABCDEFG"));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}
/*
int main(void)
{
#include <stdio.h>


	ft_printf(" %u ", 10);
	printf(" %u ", 100);
}*/
