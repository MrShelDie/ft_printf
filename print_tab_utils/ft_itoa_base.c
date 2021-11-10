#include "../ft_printf.h"

// static void	ft_add_prefix(char *str, t_format *format)
// {
// 	char	conv;

// 	if (format->flag_zero)
// 	{
// 		ft_memcpy(str, "00", 2);
// 		return ;
// 	}
// 	conv = format->conv;
// 	if (conv == 'x')
// 		ft_memcpy(str, "0x", 2);
// 	else if (conv == 'X')
// 		ft_memcpy(str, "0X", 2);
// }

char	*ft_itoa_base(
	size_t num, char *base, size_t base_size, t_format *format
)
{
	char	*str;
	int		prec;

	prec = format->prec;
	str = malloc(sizeof(char) * (prec + 1));
	if (!str)
		return (NULL);
	str[prec] = '\0';
	while (--prec != -1)
	{
		str[prec] = base[num % base_size];
		num /= base_size;
	}
	// if (format->flag_sharp)
	// 	ft_add_prefix(str, format);
	return (str);
}
