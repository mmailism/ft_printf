/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:47:43 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/27 17:10:22 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (write (1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_print_perc(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}

int	print_format(const char sp, va_list ap)
{
	int	count;

	count = 0;
	if (sp == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (sp == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (sp == 'p')
		count += ft_print_ptr(va_arg(ap, unsigned long long), 2);
	else if (sp == 'd' || sp == 'i')
		count += ft_print_nbr(va_arg(ap, int));
	else if (sp == 'u')
		count += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (sp == 'x' || sp == 'X')
		count += ft_print_ptr(va_arg(ap, unsigned int), sp);
	else if (sp == '%')
		count += ft_print_perc();
	else if (write(1, &sp, 1) == -1)
		return (-1);
	else
		write(1, &sp, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		tmp;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			tmp = print_format(*(++format), ap);
			if (tmp == -1)
				return (-1);
		}
		else
		{
			tmp = write(1, format, 1);
			if (tmp == -1)
				return (-1);
		}
		count += tmp;
		format++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int	count;
	int	n;
	int	i;

	n = 100;
	i = 127;
	count = ft_printf("abc%s\n", "def");
	ft_printf("count : %d, char : %c, ascii char : %i\n", count, n, n);
	ft_printf("big %X and small %x and percent %%\n", i, i);
	ft_printf("address : %p %p\n", "-1", NULL);
	write(1, "\n", 1);
	write(1, "and", 3);
	write(1, "\n\n", 2);
	count = printf("abc%s\n", "def");
	printf("count : %d, char : %c, ascii char : %i\n", count, n, n);
	printf("big %X and small %x and percent %%\n", i, i);
	printf("\n%d", printf("%p", NULL));
}
