/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:47:08 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/27 17:20:02 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_nbrlen(n);
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[--i] = '8';
			n /= 10;
		}
		n = -n;
	}
	while (i-- && n != 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

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

int	ft_print_unsigned(unsigned int n)
{
	static char	digits[] = "0123456789";

	if (n > 9)
		ft_print_unsigned(n / 10);
	write(1, &digits[n % 10], 1);
	return (u_digits(n));
}
