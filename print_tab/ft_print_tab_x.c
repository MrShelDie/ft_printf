#include "../ft_printf.h"

static int	get_tab_prec(t_format *format, unsigned int arg)
{
	int	arg_len;

	arg_len = ft_ndigit_base(arg, 16);
	if (!format->is_prec_default && format->prec > arg_len)
		return (format->prec);
	else
		return (arg_len);
}

static int	get_tab_width(t_format *format)
{
	// TODO
}

void	print_tab_x(
	t_format *format, va_list args, int *printed_count, int *error
)
{
	char			*tab;
	unsigned int	arg;

	arg = va_arg(args, unsigned int);
	format->prec = get_tab_prec(format, arg);
	// TODO
}
