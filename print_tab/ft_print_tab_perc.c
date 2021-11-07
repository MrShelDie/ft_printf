#include "../ft_printf.h"

void	print_tab_perc(int *printed_count)
{
	write(1, "%", 1);
	(*printed_count)++;
}
