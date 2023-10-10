/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:47:43 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/10 17:09:05 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */

#include "ft_printf.h"

int	print_format(const char sp, va_list ap)
{
	int	count;

	count = 0;
	if (sp == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (sp == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (sp == 'p')
		count += ft_print_address(va_arg(ap, unsigned long long));
	else if (sp == 'd' || sp == 'i')
		count += ft_print_nbr(va_arg(ap, int));
	else if (sp == 'u')
		count += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (sp == 'x' || sp == 'X')
		count += ft_print_hlx(va_arg(ap, unsigned int), sp);
	else if (sp == '%')
		count += ft_print_perc();
	else
		return (write(1, &sp, 1));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

// int	main()
// {
// 	int	count;
// 	int	n;
// 	int i;

// 	n = 100;
// 	i = 127;
// 	count = ft_printf("abc%s\n", "def");
// 	ft_printf("count : %d, char : %c, ascii char : %i\n", count, n, n);
// 	ft_printf("big %X and small %x and percent %%\n", i, i);
// 	ft_printf("address : %p %p\n", "-1", NULL);
// 	write(1, "\n", 1);
// 	write(1, "and", 3);
// 	write(1, "\n\n", 2);

// 	count = printf("abc%s\n", "def");
// 	printf("count : %d, char : %c, ascii char : %i\n", count, n, n);
// 	printf("big %X and small %x and percent %%\n", i, i);
// 	printf("\n%d", printf("%p", NULL));
// }
