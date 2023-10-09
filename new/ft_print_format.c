/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:47:08 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/09 17:43:42 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_print_nbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_print_str(num);
	free(num);
	return (len);
}

int	ft_print_unsigned(unsigned long long int n, const char *base)
{
	unsigned long long int		base_len;
	int							*num;

	num = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_print_unsigned(n / base_len, base);
		ft_print_unsigned(n % base_len, base);
	}
	else
	{
		write(1, &base[n], 1);
	num += ft_unbrlen(n, base_len);
	}
	return (num);
}

int	ft_print_perc(void)
{
	write(1, "%", 1);
	return (1);
}
