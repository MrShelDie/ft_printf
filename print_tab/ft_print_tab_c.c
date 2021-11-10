#include "../ft_printf.h"

static int	get_tab_width(t_format *format)
{
	int		width;

	width = 1;
	if (!format->is_width_default && format->width > width)
		width = format->width;
	return (width);
}

static void	put_tab(t_format *format, char *tab, unsigned char arg)
{
	if (format->flag_minus)
		tab[0] = arg;
	else
		tab[format->width - 1] = arg;
	write(1, tab, format->width);
}

void	print_tab_c(
	t_format *format, unsigned char arg, int *printed_count, int *error
)
{
	char	*tab;

	format->width = get_tab_width(format);
	tab = (char *)malloc(sizeof(char) * (format->width + 1));
	if (!tab)
	{
		*error = 1;
		return ;
	}
	init_tab(format, tab, format->width + 1);
	put_tab(format, tab, arg);
	free(tab);
	*printed_count += format->width;
}
