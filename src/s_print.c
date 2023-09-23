typedef struct s_print
{
	char	*format;

	int		next;

	int		i;
	int		len;

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
}	t_print

t_print	*ft_initialise_tab(t_print *tab)
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
	return (tab);
}
