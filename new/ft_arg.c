#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_print_char(int c);
int	ft_print_nbr(int n);
int	ft_print_str(char *str);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hlxX(unsigned int n, const char base);

int	print_format(const char sp, va_list ap)
{
	int	count;

	count = 0;
	if (sp == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (sp == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (sp == 'd' || sp == 'i')
		count += ft_print_nbr(va_arg(ap, int));
	else if (sp == 'u')
		count += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (sp == 'x' || sp == 'X')
		count += ft_print_hlxX(va_arg(ap, unsigned int));
	else
		return (write(1, &sp, 1));
	return (count);
}
