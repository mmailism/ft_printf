/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ulitity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:53:06 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/31 16:05:35 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*i;
	size_t			j;

	i = s;
	j = 0;
	if (n == 0)
		return ;
	while (j < n)
	{
		i[j] = 0;
		j++;
	}
}

ssize_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

ssize_t	u_digits(unsigned int n)
{
	size_t	digits;

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
