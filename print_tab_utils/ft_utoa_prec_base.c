#include "../ft_printf.h"

char	*ft_utoa_prec_base(size_t num, char *base, size_t base_size, int prec)
{
	char	*str;

	str = malloc(sizeof(char) * (prec + 1));
	if (!str)
		return (NULL);
	str[prec] = '\0';
	while (--prec != -1)
	{
		str[prec] = base[num % base_size];
		num /= base_size;
	}
	return (str);
}
