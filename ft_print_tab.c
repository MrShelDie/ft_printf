#include "ft_printf.h"

static char	*create_tab(t_format *format, int len)
{
	char	*tab;

	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	if (format->flag_zero)
		ft_memset(tab, '0', len);
	else
		ft_memset(tab, ' ', len);
	tab[len] = '\0';
	return (tab);
}

static void	print_tab_perc(int *printed_count)
{
	write(1, "%", 1);
	*printed_count++;
}

static void	print_tab_c(t_format *format, va_list args, int *printed_count)
{
	int		len;
	char	*tab;

	len = 1;
	if (!format->is_width_default && format->width > len)
		len = format->width;
	tab = create_tab(format, len);
	if (format->flag_minus)
		tab[0] = va_arg(args, int);
	else
		tab[len - 1] = va_arg(args, int);
	write(1, tab, len + 1);
	free(tab);
	*printed_count += len;
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

	conv = format->conv;
	handle_flags(format);
	if (conv == '%')
		print_tab_perc(printed_count);
	else if (conv == 'c')
		print_tab_c(format, args, printed_count);
}
