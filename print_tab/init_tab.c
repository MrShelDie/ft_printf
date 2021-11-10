#include "../ft_printf.h"

void	init_tab(t_format *format, char *tab, int size)
{
	if (format->flag_zero)
		ft_memset(tab, '0', size - 1);
	else
		ft_memset(tab, ' ', size - 1);
	tab[size - 1] = '\0';
}
