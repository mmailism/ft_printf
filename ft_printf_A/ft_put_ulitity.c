/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ulitity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:01:25 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/31 14:21:26 by iammai           ###   ########.fr       */
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
			ft_print_str((n + '0'), 1);
		else if (base == 'x')
			ft_print_str((n - 10 + 'a'), 1);
		else if (base == 'X')
			ft_print_str((n - 10 + 'A'), 1);
	}
}

int	ft_print_ptr(unsigned long long n, const char base)
{
	int	length;

	length = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		ft_put_ptr(n, base);
		length += ft_ptrlen(n);
	}
	return (length);
}

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

void	*ft_calloc(size_t count, size_t n)
{
	void	*alt;

	alt = (void *)malloc(count * n);
	if (alt == NULL)
		return (NULL);
	ft_bzero(alt, (count * n));
	return (alt);
}
