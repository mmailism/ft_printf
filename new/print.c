// #include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
char	*ft_utoi(unsigned int n);
size_t	ft_strlen(const char *str);
void	ft_put_hlxX(unsigned int num, const char base);
int	ft_ptr_len(int n);
void	ft_put_ptr(int n);

int	ft_print_char(int c)
{
	return write(1, &c, 1);
}

int	ft_print_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}
int	ft_print_nbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_print_str(num);
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int		length;
	char	*num;

	length = 0;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		num = ft_utoi(n);
		length += ft_print_str(num);
	}
	return (length);
}

int	ft_ptrlen(unsigned int n)
{
	int len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_put_hlxX(unsigned int n, const char base)
{
	if (n >= 16)
	{
		ft_put_hlxX(n / 16, base);
		ft_put_hlxX(n % 16, base);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (base == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (base == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hlxX(unsigned int n, const char base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hlxX(n, base);
	return (ft_ptrlen(n));
}

void	ft_putptr(unsigned long long ptr)
{
	if (ptr <= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr >= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_print_address(unsigned long long ptr)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (ptr == 0)
		length += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		length += ft_ptrlen(ptr);
	}
	return (length);
}

int	ft_print_perc(void)
{
	write(1, "%", 1);
	return (1);
}
