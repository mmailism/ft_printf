#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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

int	ft_print_ptr(unsigned long long ptr)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (ptr == 0)
		length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		length += ft_ptr_len(ptr);
	}
	return (length);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}