#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_args(char c, va_list args);
int	ft_chackal(unsigned long n);
int	ft_convert_hexa(void *ptr, char *set);
int	ft_print_hexa(int *arr);
int	ft_print_ptr(void *ptr);
int	ft_putnbr_unsigned(unsigned int n);

#endif
