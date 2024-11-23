#include "ft_printf.h"

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
	unsigned long	res;
	int				count;
	int				sinistre[250];
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
	while (arr[i])
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

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 10)
	{
		count += ft_putnbr_unsigned(n / 10);
		count += ft_putnbr_unsigned(n % 10);
	}
	else
	{
		n += '0';
		count += write(1, &n, 1);
	}
	return (count);
}
