#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// typedef	__builtin_va_list va_list;

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

int	print_char(int c)
{
	return (write(1, &c, 1));
}
int	print_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
	write(1, "here", 4);
}

// int	print_digit(long n, int base)
// {
// 	int		count;
// 	char	*symbols;

// 	symbols = "0123456789abcdef";
// 	if (n < 0)
// 	{
// 		print_char('-');
// 		n = -n;
// 	}
// 	else if (n < base)
// 		count += print_char(symbols[n]);
// 	else
// 		count = print_digit(n / base, base);
// 	return (count + print_digit(n % base, base));
// }

int	print_format(const char sap, va_list ap)
{
	char	sp;

	if (sp == 'c')
		return (print_char(va_arg(ap, int)));
	else if (sp == 's')
		return (print_str(va_arg(ap, char *)));
	// else if (sp == 'd')
	// 	return (print_digit((long)va_arg(ap, int)));
	// else if (sp == 'x')
	// 	return (print_digit((long)va_arg(ap, int)));
	else
		return (write(1, &sp, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int	count;

	count = ft_printf("abc%s\n", "def");
	ft_printf("char1 : %d\n", count);
	write(1, "\n", 1);
	count = printf("abc%s\n", "defg");
	printf("char2 : %d\n", count);
}