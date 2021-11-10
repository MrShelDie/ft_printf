#include "../ft_printf.h"

static int	get_tab_prec(t_format *format, int arg)
{
	int			arg_len;
	long int	larg;

	if (!format->is_prec_default && format->prec == 0 && arg == 0)
		return (0);
	larg = arg;
	if (larg < 0)
		larg *= -1;
	arg_len = ft_unumlen_base((size_t)larg, 10);
	if (!format->is_prec_default && format->prec > arg_len)
		return (format->prec);
	return (arg_len);
}

static int	get_tab_width(t_format *format, int arg)
{
	int	width;

	width = format->prec;
	if (arg < 0 || format->flag_plus || format->flag_space)
		width++;
	if (!format->is_width_default && format->width > width)
		return (format->width);
	return (width);
}

static void	fill_tab(t_format *format, char *tab, char *num_str, int arg)
{
	size_t	sign_pos;

	if (format->flag_minus)
	{
		if (arg < 0)
			tab[0] = '-';
		else if (format->flag_plus)
			tab[0] = '+';
		if (arg < 0 || format->flag_plus || format->flag_space)
			ft_memcpy(tab + 1, num_str, format->prec);
		else
			ft_memcpy(tab, num_str, format->prec);
	}
	else
	{
		if (format->flag_zero)
			sign_pos = 0;
		else
			sign_pos = format->width - format->prec - 1;
		if (arg < 0)
			tab[sign_pos] = '-';
		else if (format->flag_plus)
			tab[sign_pos] = '+';
		ft_memcpy(tab + (format->width - format->prec), num_str, format->prec);
	}
}

static int	put_tab(t_format *format, char *tab, int arg)
{
	char		*num_str;
	long int	larg;

	larg = arg;
	if (arg < 0)
	{
		larg *= -1;
		num_str = utoa_prec_base((size_t)larg, "0123456789", 10, format->prec);
	}
	else
		num_str = utoa_prec_base((size_t)larg, "0123456789", 10, format->prec);
	fill_tab(format, tab, num_str, arg);
	write(1, tab, format->width);
	free(num_str);
	return (SUCCESS);
}

void	print_tab_d(
	t_format *format, int arg, int *printed_count, int *error
)
{
	char	*tab;

	if (arg < 0)
	{
		format->flag_space = FALSE;
		format->flag_plus = FALSE;
	}
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
