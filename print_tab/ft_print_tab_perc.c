#include "../ft_printf.h"

void	ft_print_tab_perc(t_format *format, int *printed_count, int *error)
{
	ft_print_tab_s(format, "%", printed_count, error);
}
