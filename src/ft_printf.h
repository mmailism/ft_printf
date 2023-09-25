#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>

int	ft_printf(const char *str, ...);
typedef	struct s_print
{
	va_list	args;

	int		wdt; //width (0-9)
	int		prc; //precisiion
	int		zero; //zero padding
	int		hash; //#
	int		pnt; //point.
	int		dash; //-
	int		tl; //total length
	int		sign; //+(pos)&-(neg) number
	int		is_zero; //is number_zero
	int		perc; //%(percent)
	int		sp; //space flag' '
}			t_print;

t_print	*ft_tabzero(t_print *tab);

int	ft_putstr(char const *s);
int	ft_putchar(char c);
int	ft_putnbr(int n);

#endif
