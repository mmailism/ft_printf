/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:47:08 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/27 15:37:14 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int		len;
	char	*num;
	int		tmp;

	len = 0;
	num = ft_itoa(n);
	tmp = ft_print_str(num);
	if (tmp == -1)
		return (-1);
	len = tmp;
	free(num);
	return (len);
}

ssize_t	u_digits(unsigned int n)
{
	ssize_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digits += 1;
	}
	return (digits);
}

void	ft_put_unsigned(unsigned int n)
{
	static char	digits[] = "0123456789";

	if (n > 9)
		ft_put_unsigned(n / 10);
	write(1, &digits[n % 10], 1);
}

int	ft_print_unsigned(unsigned int n)
{
	if (n == -1)
		return (-1);
	ft_put_unsigned(n);
	return (u_digits(n));
}
