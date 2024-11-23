#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

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
			write(1, format, 1);
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

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n > 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		n += '0';
		return (write(1, &n, 1));
	}
	return (0);
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
		return (ft_convert_hexa(va_arg(args, void *), "0123456789abcdefg"));
	if (c == 'X')
		return (ft_convert_hexa(va_arg(args, void *), "0123456789ABCDEFG"));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}
/*
int main(void)
{
#include <stdio.h>
	void	*ptr = "azea";
	ft_printf("%c %c %c", 'a','b','c');
	printf("\n");
	ft_printf("%s et oui", "Bonjour a tous les amis, 
	ceci est une string de mon printf");
	printf("\n");
	ft_printf("%d %s", 667, " ekip");
	printf("\n");
	ft_printf("%x", 1234);
	printf("\n");
	ft_printf("%p", ptr);
	printf("\n");
	ft_printf("%%");
	printf("\n");
	ft_printf("%u", 1231313);
}*/
