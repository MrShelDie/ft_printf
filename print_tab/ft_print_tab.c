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
	if (!format->is_prec_default
		&& (conv == 'd' || conv == 'i'
			|| conv == 'u' || conv == 'x'
			|| conv == 'X')
	)
		format->flag_zero = FALSE;
	if (format->flag_plus)
		format->flag_space = FALSE;
}

static void	get_arg(t_arg *arg, va_list args, char conv)
{
	if (conv == 'c')
		arg->c = (unsigned char)va_arg(args, int);
	else if (conv == 's')
		arg->s = va_arg(args, const char *);
	else if (conv == 'x' || conv == 'X')
		arg->x = va_arg(args, unsigned int);
}

void	print_tab(t_format *format,
			va_list args, int *printed_count)
{
	char	conv;
	int		error;
	t_arg	arg;

	error = 0;
	conv = format->conv;
	handle_flags(format);
	get_arg(&arg, args, conv);
	if (conv == '%')
		print_tab_perc(printed_count);
	else if (conv == 'c')
		print_tab_c(format, arg.c, printed_count, &error);
	else if (conv == 's')
		print_tab_s(format, arg.s, printed_count, &error);
	else if (conv == 'x' || conv == 'X')
		print_tab_x(format, arg.x, printed_count, &error);
}
