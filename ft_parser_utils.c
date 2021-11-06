#include "ft_printf.h"

void	init_format(t_format *format)
{
	ft_bzero(format, sizeof(t_format));
	format->is_width_default = TRUE;
	format->is_prec_default = TRUE;
}

void	get_flags(const char **str, t_format *format)
{
	char	c;

	while (1)
	{
		c = **str;
		if (c == '#')
			format->flag_sharp = TRUE;
		else if (c == '0')
			format->flag_zero = TRUE;
		else if (c == '-')
			format->flag_minus = TRUE;
		else if (c == ' ')
			format->flag_space = TRUE;
		else if (c == '+')
			format->flag_plus = TRUE;
		else
			break ;
		(*str)++;
	}
}

void	get_width(const char **str, t_format *format)
{
	if (!ft_isdigit(**str))
		return ;
	format->width = ft_atoi(*str);
	format->is_width_default = FALSE;
	while (ft_isdigit(**str))
		(*str)++;
}

void	get_prec(const char **str, t_format *format)
{
	if (**str != '.')
		return ;
	(*str)++;
	format->prec = ft_atoi(*str);
	format->is_prec_default = FALSE;
	while (ft_isdigit(**str))
		(*str)++;
}

int	get_conv(const char **str, t_format *format)
{
	char	c;

	c = **str;
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
	{
		format->conv = c;
		(*str)++;
		return (SUCCESS);
	}
	return (FAILE);
}
