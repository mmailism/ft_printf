/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:47:08 by kpueankl          #+#    #+#             */
/*   Updated: 2023/11/02 14:09:39 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_nbrlen_base(int n, size_t base)
{
	ssize_t	i;

	i = 1;
	while (n >= (int)base)
	{
		n /= base;
		i++;
	}
	return (i);
}

int	ft_print_nbr(int n, int fd)
{
	const char	*base = "0123456789";
	int			nbr_len;

	nbr_len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr_len += ft_print_nbr(-n, fd);
	}
	else if (n >= 10)
	{
		ft_print_nbr((n / 10), fd);
		ft_print_nbr((n % 10), fd);
	}
	else
		write (fd, &base[n], 1);
	nbr_len += ft_nbrlen_base(n, ft_strlen(base));
	return (nbr_len);
}

ssize_t	ft_print_unsigned(unsigned int n)
{
	ft_put_unsigned(n);
	return (u_digits(n));
}
