#include "ft_printf.h"

static int	print_spec(const char **str, va_list args, int *printed_count)
{
	t_format	format;

	if (**str != '%')
		return (SUCCESS);
	init_format(&format);
	if (!parse(str, &format))
		return (FAILE);
	print_tab(&format, args, printed_count);
	return (SUCCESS);
}

static void	print_not_spec(const char **str, int *printed_count)
{
	int	write_size;

	write_size = 0;
	while ((*str)[write_size] && (*str)[write_size] != '%')
		write_size++;
	write(1, *str, write_size);
	(*str) += write_size;
	(*printed_count) += write_size;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_count;

	if (!str)
		return (-1);
	printed_count = 0;
	va_start(args, str);
	while (*str)
	{
		print_not_spec(&str, &printed_count);
		if (!print_spec(&str, args, &printed_count))
		{
			printed_count = -1;
			break ;
		}
	}
	va_end(args);
	return (printed_count);
}
