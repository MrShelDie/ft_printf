#include "../ft_printf.h"

static int	get_tab_prec(t_format *format, unsigned int arg)
{
	int	arg_len;

	arg_len = ft_nudigit_base(arg, 16);
	if (!format->is_prec_default && format->prec > arg_len)
		return (format->prec);
	else
		return (arg_len);
}

static int	get_tab_width(t_format *format)
{
	int	width;

	width = format->prec;
	if (format->flag_sharp)
		width += 2;
	if (!format->is_width_default && format->width > width)
		return (format->width);
	else
		return (width);
}

void	print_tab_x(
	t_format *format, va_list args, int *printed_count, int *error
)
{
	char			*tab;
	unsigned int	arg;

	arg = va_arg(args, unsigned int);
	format->prec = get_tab_prec(format, arg);
	format->width = get_tab_width(format);
	tab = (char *)malloc(sizeof(char) * (format->width + 1));
	if (!tab)
	{
		*error = 1;
		return ;
	}
	init_tab(format, tab, format->width + 1);
	// TODO
	free(tab);
	*printed_count += format->width;
}
