/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <iammai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:56:53 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/31 18:44:04 by iammai           ###   ########.fr       */
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
int		ft_print_nbr(int n);
char	*ft_itoa(int n);
ssize_t	ft_print_unsigned(unsigned int n);
ssize_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
ssize_t	u_digits(unsigned int n);
void	ft_put_unsigned(unsigned int n);
int		ft_ptrlen(uintptr_t n);
int		ft_print_hlx(unsigned int n, const char base);
int		ft_print_ptr(unsigned long long n);
void	ft_put_str(char *str);

#endif
