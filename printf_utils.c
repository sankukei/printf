/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:55:14 by leothoma          #+#    #+#             */
/*   Updated: 2024/11/24 01:55:14 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_chackal(unsigned long n)
{
	int	i;

	i = 0;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}

int	ft_convert_hexa(unsigned long n, char *set)
{
	unsigned long	res;
	int				count;
	int				sinistre[250];
	unsigned long	len;

	res = 0;
	res = n;
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

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += write(1, "0x", 2);
	count += ft_convert_hexa((unsigned long)ptr, "0123456789abcdefg");
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
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
