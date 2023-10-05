/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:55:14 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/05 17:56:38 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned int n)
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

void	ft_put_hlx(unsigned int n, const char base)
{
	if (n >= 16)
	{
		ft_put_hlx(n / 16, base);
		ft_put_hlx(n % 16, base);
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

int	ft_print_hlx(unsigned int n, const char base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hlx(n, base);
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
