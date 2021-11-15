#include "../ft_printf.h"

static void	ft_handle_flags(t_format *format)
{
	char	conv;

	conv = format->conv;
	if (conv != 'x' && conv != 'X')
		format->flag_sharp = FALSE;
	if (format->flag_minus || conv == 'c' || conv == 'p')
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

static void	ft_get_arg(t_arg *arg, va_list args, char conv)
{
	if (conv == 'i' || conv == 'd')
		arg->d = va_arg(args, int);
	else if (conv == 's')
		arg->s = va_arg(args, const char *);
	else if (conv == 'c')
		arg->c = (unsigned char)va_arg(args, int);
	else if (conv == 'p')
		arg->p = va_arg(args, void *);
	else if (conv == 'x' || conv == 'X')
		arg->x = va_arg(args, unsigned int);
	else if (conv == 'u')
		arg->u = va_arg(args, unsigned int);
}

int	ft_print_tab(t_format *format, va_list args, int *printed_count)
{
	char	conv;
	int		error;
	t_arg	arg;

	error = 0;
	conv = format->conv;
	ft_handle_flags(format);
	ft_get_arg(&arg, args, conv);
	if (conv == 'i' || conv == 'd')
		ft_print_tab_d(format, arg.d, printed_count, &error);
	else if (conv == 's')
		ft_print_tab_s(format, arg.s, printed_count, &error);
	else if (conv == 'c')
		ft_print_tab_c(format, arg.c, printed_count, &error);
	else if (conv == 'p')
		ft_print_tab_p(format, arg.p, printed_count, &error);
	else if (conv == 'x' || conv == 'X')
		ft_print_tab_x(format, arg.x, printed_count, &error);
	else if (conv == 'u')
		ft_print_tab_u(format, arg.u, printed_count, &error);
	else if (conv == '%')
		ft_print_tab_perc(format, printed_count, &error);
	if (error)
		return (FAILE);
	return (SUCCESS);
}
