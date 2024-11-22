#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"
#include <string.h>

int	ft_print_hexa(int *arr);
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_args(*format, args);
		}
		format++;
	}
	return (count);
}

int	ft_putchar(int c)
{
	return(write(1, (char *)&c, 1));
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
        {
                return(write(1, "-2147483648", 11));
        }
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
                return(write(1, &n, 1));
        }
	return (0);
}

int	ft_chackal(unsigned long n)
{
	int	i;

	i = 0;
	while (n > 16)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}

int	ft_convert_hexa(void *ptr, char *set)
{
	unsigned long res;
	int	count;
	int	sinistre[250];
	unsigned long	len;
	
	res = 0;
	res = (unsigned long)ptr;
	len = ft_chackal(res);
	sinistre[len] = '\0';
	while (len--)
	{
		sinistre[len] = res % 16;
		sinistre[len] = set[sinistre[len]];
		res /= 16;
	}
	count = ft_print_hexa(sinistre);
	return (count);
}

int	ft_print_hexa(int *arr)
{
	int	i;

	i = 0;
	while(arr[i])
		write(1, &arr[i++], 1);
	return (i);
}

int	ft_print_ptr(void *ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_convert_hexa(ptr, "0123456789abcdefg");
	return (count);
}

int	ft_args(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'x')
		return (ft_convert_hexa(va_arg(args, void *), "0123456789abcdefg"));
	if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	return (0);
}
int main(void)
{
	void	*ptr = "azea";
	ft_printf("%c %c %c", 'a','b','c');
	printf("\n");
	ft_printf("%s", "Bonjour a tous les amis, ceci est une string de mon printf");
	printf("\n");
	ft_printf("%d %s", 667, " ekip");
	printf("\n");
	ft_printf("%x", 1234);
	printf("\n");
	ft_printf("%p", ptr);
	printf("\n");
	printf("%p", ptr);
}
