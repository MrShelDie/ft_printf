#include "../ft_printf.h"

static int	get_tab_prec(t_format *format, int arg)
{
	int			arg_len;

	if (!format->is_prec_default && format->prec == 0 && arg == 0)
		return (0);
	if (arg < 0)
		arg_len = ft_unumlen_base(arg * -1, 10);
	else
		arg_len = ft_unumlen_base(arg, 10);
	if (!format->is_prec_default && format->prec > arg_len)
		return (format->prec);
	return (arg_len);
}

static int	get_tab_width(t_format *format, int arg)
{
	int	width;

	width = format->prec;
	if (arg < 0 || format->flag_space || format->flag_plus)
		width++;
	if (!format->is_width_default && format->width > width)
		return (format->width);
	return (width);
}

static int	put_tab(t_format *format, char *tab, int arg)
{
	char	*num_str;

	if (arg < 0)
		num_str = utoa_prec_base(arg * -1, "0123456789", 10, format->prec);
	else
		num_str = utoa_prec_base(arg, "0123456789", 10, format->prec);
	// TODO FILL_TAB
	write(1, tab, format->width);
	free(num_str);
	return (SUCCESS);
}

void	print_tab_d(
	t_format *format, int arg, int *printed_count, int *error
)
{
	char	*tab;

	format->prec = get_tab_prec(format, arg);
	format->width = get_tab_width(format, arg);
	tab = (char *)malloc(sizeof(char) * (format->width + 1));
	if (!tab)
	{
		*error = 1;
		return ;
	}
	init_tab(format, tab, format->width + 1);
	if (!put_tab(format, tab, arg))
	{
		*error = 1;
		free(tab);
		return ;
	}
	free(tab);
	*printed_count += format->width;
}
