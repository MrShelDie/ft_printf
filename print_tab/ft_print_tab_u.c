#include "../ft_printf.h"

static int	get_tab_prec(t_format *format, unsigned int arg)
{
	int	arg_len;

	if (!format->is_prec_default && format->prec == 0 && arg == 0)
		return (0);
	arg_len = ft_unumlen_base(arg, 10);
	if (!format->is_prec_default && format->prec > arg_len)
		return (format->prec);
	return (arg_len);
}

static int	ft_get_tab_width(t_format *format)
{
	if (!format->is_width_default && format->width > format->prec)
		return (format->width);
	return (format->prec);
}

static int	ft_put_tab(t_format *format, char *tab, unsigned int arg)
{
	char	*num_str;

	num_str = ft_utoa_prec_base(arg, "0123456789", 10, format->prec);
	if (!num_str)
		return (FAILE);
	if (format->flag_minus)
		ft_memcpy(tab, num_str, format->prec);
	else
		ft_memcpy(tab + (format->width - format->prec), num_str, format->prec);
	write(1, tab, format->width);
	free(num_str);
	return (SUCCESS);
}

void	ft_print_tab_u(
	t_format *format, unsigned int arg, int *printed_count, int *error
)
{
	char	*tab;

	format->prec = get_tab_prec(format, arg);
	format->width = ft_get_tab_width(format);
	tab = (char *)malloc(sizeof(char) * (format->width) + 1);
	if (!tab)
	{
		*error = 1;
		return ;
	}
	ft_init_tab(format, tab, format->width + 1);
	if (!ft_put_tab(format, tab, arg))
	{
		*error = 1;
		free(tab);
		return ;
	}
	free(tab);
	*printed_count += format->width;
}
