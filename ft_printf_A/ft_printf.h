/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:56:53 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/27 17:19:23 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_print_unsigned(unsigned int n);
int		ft_print_nbr(int n);
int		ft_print_ptr(unsigned long long n, const char base);
void	*ft_calloc(size_t count, size_t n);
int		ft_print_str(char *str);

#endif
