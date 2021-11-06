#include "ft_printf.h"

static void	print_tab_perc(const char **str, int *printed_count)
{
	write(1, "%", 1);
	*printed_count++;
}

static void	handle_flags(t_format *format)
{
	char	conv;

	conv = format->conv;
	if (conv != 'x' && conv != 'X')
		format->flag_sharp = FALSE;
	if (format->flag_minus || !format->is_prec_default
		|| conv == 'c' || conv == 's'
		|| conv == 'p' || conv == '%'
	)
		format->flag_zero = FALSE;
	if (format->flag_plus)
		format->flag_space = FALSE;
}

void	print_tab(const char **str, t_format *format,
			va_list args, int *printed_count)
{
	char	conv;
	t_str	tab;

	conv = format->conv;
	handle_flags(format);
	if (conv == '%')
		print_tab_perc(str, printed_count);
}
