#include "../ft_printf.h"

static int	get_tab_prec(t_format *format, const char *arg)
{
	int	arg_len;

	arg_len = ft_strlen(arg);
	if (!format->is_prec_default && format->prec < arg_len)
		return (format->prec);
	else
		return (arg_len);
}

static int	get_tab_width(t_format *format)
{
	if (!format->is_width_default && format->width > format->prec)
		return (format->width);
	return (format->prec);
}

static void	putstr_tab(t_format *format, char *tab, const char *arg)
{
	if (format->flag_minus)
		ft_memcpy(tab, arg, format->prec);
	else
		ft_memcpy(tab + (format->width - format->prec), arg, format->prec);
	write(1, tab, format->width);
}

void	print_tab_s(
	t_format *format, const char *arg, int *printed_count, int *error
)
{
	char	*tab;

	if (!arg)
		arg = "(null)";
	format->prec = get_tab_prec(format, arg);
	format->width = get_tab_width(format);
	tab = (char *)malloc(sizeof(char) * (format->width + 1));
	if (!tab)
	{
		*error = 1;
		return ;
	}
	init_tab(format, tab, format->width + 1);
	putstr_tab(format, tab, arg);
	free(tab);
	*printed_count += format->width;
}
