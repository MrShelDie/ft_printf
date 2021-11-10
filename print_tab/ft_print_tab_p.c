#include "../ft_printf.h"

// static int	get_tab_prec(t_format *format, void *arg)
// {
// 	int	arg_len;

// 	arg_len = ft_unumlen_base((unsigned long long int)arg, 16);
// 	if (!format->is_prec_default && format->prec > arg_len)
// 		return (format->prec);
// 	else
// 		return (arg_len);
// }

void	print_tab_p(
	t_format *format, void *arg, int *printed_count, int *error
)
{
	if (arg == NULL)
	{
		print_tab_s(format, "(nil)", printed_count, error);
		return ;
	}
	format->flag_sharp = TRUE;
	print_tab_x(format, (size_t)arg, printed_count, error);
}
