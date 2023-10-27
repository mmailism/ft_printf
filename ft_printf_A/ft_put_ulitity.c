/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ulitity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:01:25 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/27 16:09:42 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(uintptr_t n)
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

void	ft_put_ptr(uintptr_t n, const char base)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16, base);
		ft_put_ptr(n % 16, base);
	}
	else
	{
		if (n <= 9)
			ft_print_char((n + '0'), 1);
		else if (base == 'x')
			ft_print_char((n - 10 + 'a'), 1);
		else if (base == 'X')
			ft_print_char((n - 10 + 'A'), 1);
		else
			ft_print_char((n - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long n, const char base)
{
	int	length;

	length = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else if (ft_print_str("0x") == -1)
		return (-1);
	else
	{
		ft_put_ptr(n, base);
		length += ft_ptrlen(n);
	}
	return (length);
}
