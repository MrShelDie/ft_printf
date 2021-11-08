# include "libft.h"

int	ft_nudigit_base(unsigned long int num, unsigned long int base)
{
	int				count;

	count = 0;
	while (num / base > 0)
	{
		num /= base;
		count++;
	}
	return (count);
}
