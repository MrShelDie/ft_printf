#include "../ft_printf.h"

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

void	print_tab(t_format *format,
			va_list args, int *printed_count)
{
	char	conv;
	int		error;

	error = 0;
	conv = format->conv;
	handle_flags(format);
	if (conv == '%')
		print_tab_perc(printed_count);
	else if (conv == 'c')
		print_tab_c(format, args, printed_count, &error);
	else if (conv == 's')
		print_tab_s(format, args, printed_count, &error);
	else if (conv == 'x')
		print_tab_x()
}
