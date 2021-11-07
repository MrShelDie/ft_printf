#include "../ft_printf.h"

int	parse(const char **str, t_format *format)
{
	(*str)++;
	get_flags(str, format);
	get_width(str, format);
	get_prec(str, format);
	if (!get_conv(str, format))
		return (FAILE);
	return (SUCCESS);
}
