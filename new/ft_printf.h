/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iammai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:56:53 by kpueankl          #+#    #+#             */
/*   Updated: 2023/10/09 17:44:26 by iammai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_nbr(int n);
int		ft_print_unsigned(unsigned long long int n, const char *base);
int		ft_print_hlx(unsigned int n, const char base);
int		ft_print_address(unsigned long long ptr);
int		ft_print_perc(void);
void	ft_putchar_fd(char c, int fd);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
size_t	ft_unbrlen(unsigned long long int n, size_t base);
size_t	ft_strlen(const char *str);
void	ft_put_hlx(unsigned int num, const char base);
int		ft_ptrlen(uintptr_t n);
void	ft_put_ptr(uintptr_t n);
int		print_format(const char sp, va_list ap);
int		ft_printf(const char *format, ...);

#endif
