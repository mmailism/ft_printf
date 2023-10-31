/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:47:08 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/31 15:01:48 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_numlen(long n)
{
	ssize_t	i;

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

void	*ft_calloc(size_t count, size_t n)
{
	void	*alt;

	alt = (void *)malloc(count * n);
	if (alt == NULL)
		return (NULL);
	ft_bzero(alt, (count * n));
	return (alt);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_numlen(n);
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

ssize_t	ft_print_nbr(int n)
{
	ssize_t		len;
	char		*num;
	ssize_t		tmp;

	len = 0;
	num = ft_itoa(n);
	tmp = ft_print_str(num);
	if (tmp == -1)
		return (-1);
	len = tmp;
	free(num);
	return (len);
}

ssize_t	ft_print_unsigned(unsigned int n)
{
	ft_put_unsigned(n);
	return (u_digits(n));
}
