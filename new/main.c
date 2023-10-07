#include "ft_printf.h"

int	main(void)
{
	int	count;
	int	n;
	int i;

	n = 100;
	i = 127;

	count = ft_printf("abc%s\n", "def");
	ft_printf("count : %d, char : %c, ascii char : %i\n", count, n, n);
	ft_printf("big %X and small %x and percent %%\n", i, i);
	ft_printf("address : %p\n", "m");
	write(1, "\n", 1);
	write(1, "and", 3);
	write(1, "\n\n", 2);

	count = printf("abc%s\n", "def");
	printf("count : %d, char : %c, ascii char : %i\n", count, n, n);
	printf("big %X and small %x and percent %%\n", i, i);
	printf("address : %p\n", "m");
	return (0);
}
