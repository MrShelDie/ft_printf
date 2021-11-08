#include "../ft_printf.h"

static int	get_tab_prec(t_format *format, unsigned int arg)
{
	int	arg_len;

	arg_len = ft_ndigitu_base(arg, 16);
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

static void	fill_tab(t_format *format, char *tab, char *num_str)
{
	char	prefix[2];

	if (format->conv == 'x')
		ft_memcpy(prefix, "0x", 2);
	else
		ft_memcpy(prefix, "0X", 2);
	if (format->flag_minus)
	{
		if (format->flag_sharp)
		{
			ft_memcpy(tab, prefix, 2);
			ft_memcpy(tab + 2, num_str, format->prec);
		}
		else
			ft_memcpy(tab, num_str, format->prec);
	}
	else
	{
		if (format->flag_sharp && format->flag_zero)
			ft_memcpy(tab, prefix, 2);
		else if (format->flag_sharp)
			ft_memcpy(tab + (format->width - format->prec - 2), prefix, 2);
		ft_memcpy(tab + (format->width - format->prec), num_str, format->prec);
	}
}

static int	puthex_tab(t_format *format, char *tab, unsigned int arg)
{
	char	*num_str;

	if (format->conv == 'x')
		num_str = ft_itoa_base_prefix(arg, "0123456789abcdef", 16, format);
	else
		num_str = ft_itoa_base_prefix(arg, "0123456789ABCDEF", 16, format);
	if (!num_str)
		return (FAILE);
	fill_tab(format, tab, num_str);
	write(1, tab, format->width);
	free(num_str);
	return (SUCCESS);
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
	if (!puthex_tab(format, tab, arg))
	{
		*error = 1;
		free(tab);
		return ;
	}
	free(tab);
	*printed_count += format->width;
}
