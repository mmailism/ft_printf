#include "libft.h"
#include <stdlib.h>

int	ft_format(const char *format, t_struct *list, va_list ap, int pos)
{
	while (format[pos] != '\0')
	{
		if (format[pos] != '%')
			list->next += write(1, &format[pos], 1);
		else if (format[pos] == '%')
		{
			if (!)
		}

	}
}

int	ft_printf(const char *, ...)
{

}
