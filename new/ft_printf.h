#ifndef FT_PRINT_H
# define FT_PRINT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_list
{
	s_list	*ap;
}			va_list;

int	ft_printf(const char *format, ...);

#endif