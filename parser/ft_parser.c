#include "../ft_printf.h"

int	ft_parse(const char **str, t_format *format)
{
	(*str)++;
	ft_get_flags(str, format);
	ft_get_width(str, format);
	ft_get_prec(str, format);
	if (!ft_get_conv(str, format))
		return (FAILE);
	return (SUCCESS);
}
