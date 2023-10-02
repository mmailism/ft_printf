#ifndef FT_PRINT_H
# define FT_PRINT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_list
{
	struct s_list	*ap;

	int				i;
	int				len;

	int				start;
	int				next;

	int				minus; // -
	int				plus; // +
	int				space; //' '
	int				zero; //0
	int				hash; //#
	int				width //0-9
	int				point; //.
	int				poiandhas; //.#
}			t_list;

int	ft_printf(const char *format, ...);

#endif
