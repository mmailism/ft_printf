/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:47:08 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/22 21:56:56 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	if ( write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_print_str(char *str)
{
	if (!str)
	{
		if ( write(1, "(null)",6) == -1)
			return (-1);
		return (6);
	}

	int	i;
	i = 0;
	while (str[i])
	{
		if (write (1, &str[i],1) == -1)
			return (-1);
		i++;
	}
	return(i);

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
		return(-1);
	len = tmp;
	free(num);
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	ft_put_unsigned(n);
	return (u_digits(n));
}

int	ft_print_perc(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
