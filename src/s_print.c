#include "ft_printf.h"
t_list	*ft_initialise_tab(t_list *tab)
{
	tab->wdt = 0;
	tab->prc =0;
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
