#include "ft_printf.h"
#include <stdlib.h>

int	ft_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putdigit(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunsign(va_arg(args, unsigned int)));
	else if (format == 'p')
		return (ft_putaddress(va_arg(args, unsigned long)));
	else if (format == 'x' || format == 'X')
		return (ft_putuplw(va_arg(args, unsigned int)));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);

	int	count;
	const char	*ptr

	count = 0;
	ptr = format;

//loop printf(cspdiuxX%)

	va_end(args);
	return count;
}
