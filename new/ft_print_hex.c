/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:55:14 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/31 17:36:55 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			ft_print_char(n + '0');
		else
		{
			if (base == 'x')
				ft_print_char(n - 10 + 'a');
			if (base == 'X')
				ft_print_char(n - 10 + 'A');
		}
	}
}

int	ft_print_hlx(unsigned int n, const char base)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hlx(n, base);
	return (ft_ptrlen(n));
}

void	ft_put_ptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_print_char(n + '0');
		else
			ft_print_char(n - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long n)
{
	int	length;
	int	tmp;

	length = 0;
	tmp = write(1, "0x", 2);
	if (tmp == -1)
		return (-1);
	length += tmp;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		ft_put_ptr(n);
		length += ft_ptrlen(n);
	}
	return (length);
}
