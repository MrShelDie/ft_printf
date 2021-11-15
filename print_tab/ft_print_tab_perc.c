#include "../ft_printf.h"

void	ft_print_tab_perc(int *printed_count)
{
	write(1, "%", 1);
	(*printed_count)++;
}
