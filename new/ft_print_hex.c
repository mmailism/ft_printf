/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:55:14 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/25 14:36:14 by iammai           ###   ########.fr       */
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

// void	ft_put_hlx(unsigned int n, const char base)
// {
// 	if (n >= 16)
// 	{
// 		ft_put_hlx(n / 16, base);
// 		ft_put_hlx(n % 16, base);
// 	}
// 	else
// 	{
// 		if (n <= 9)
// 			ft_putchar_fd((n + '0'), 1);
// 		else
// 		{
// 			if (base == 'x')
// 				ft_putchar_fd((n - 10 + 'a'), 1);
// 			if (base == 'X')
// 				ft_putchar_fd((n - 10 + 'A'), 1);
// 		}
// 	}
// }

// int	ft_print_hlx(unsigned int n, const char base)
// {
// 	if (n == 0)
// 		return (write(1, "0", 1));
// 	else if (n == -1)
// 		return (-1);
// 	else
// 		ft_put_hlx(n, base);
// 	return (ft_ptrlen(n));
// }

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
			ft_print_char((n + '0'), 1);
		else if (base == 'x')
			ft_print_char((n - 10 + 'a'), 1);
		else if (base == 'X')
			ft_print_char((n - 10 + 'A'), 1);
		else
			ft_print_char((n - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else if (ft_print_str("0x") == -1)
		return (-1);
	else
	{
		ft_put_ptr(n);
		length += ft_ptrlen(n);
	}
	return (length);
}
