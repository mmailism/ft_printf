#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
char	*ft_utoi(unsigned int n);

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

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

int	ft_hlxXlen(unsigned int n)
{
	int	len;
	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_put_hlxX(unsigned int num, const char base)
{
	if (num >= 16)
	{
		ft_put_hlxX(num / 16, base);
		ft_put_hlxX(num % 16, base);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (base == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (base == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
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
	return (ft_hlxXlen(n));
}
