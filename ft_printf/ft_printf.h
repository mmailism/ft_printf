/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpueankl <kpueankl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:56:53 by kpueankl          #+#    #+#             */
/*   Updated: 2023/11/06 17:22:14 by kpueankl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

ssize_t	ft_print_char(int c);
ssize_t	ft_print_str(char *str);
int		ft_printf(const char *format, ...);
int		ft_print_unsigned(unsigned int n);
ssize_t	ft_strlen(const char *str);
ssize_t	u_digits(unsigned int n);
int		ft_put_unsigned(unsigned int n);
int		ft_ptrlen(uintptr_t n);
int		ft_print_hlx(unsigned int n, const char base);
int		ft_print_ptr(unsigned long long n);
int		ft_put_str(char *str);
int		ft_print_nbr(int n, int fd);

#endif
