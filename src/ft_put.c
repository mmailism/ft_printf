#include "ft_printf.h"

t_print	*ft_tabzero(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->hash = 0;
	tab->pnt = 0;
	tab->dash = 0;
	tab->tl = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->perc = 0;
	tab->sp = 0;
}

int	ft_putstr(char const *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
	return (ft_putnbr(n));
}

int	ft_putunsigned(unsigned int n)
{
	if (n >= 10)
		ft_putunsigned(n / 10);
	ft_putchar(n % 10 + '0')
	return (ft_putunsigned(n));
}

int	ft_putaddress(unsigned long adds)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2)
	if (adds == 0)
		i += write(1, "0", 1)
	else
		i = ft_strlen(adds);
	return (i);
}

int	ft_putuplw(unsigned int uplw)
{
	
}
