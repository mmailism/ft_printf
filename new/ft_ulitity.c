/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:53:06 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/07 18:25:39 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(long n)
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

char	*ft_utoi(unsigned long n)
{
	char	*str;
	int		i;

	i = ft_numlen(n);
	str = 0;
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}
