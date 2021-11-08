# include "libft.h"

int	ft_ndigitu_base(unsigned int num, unsigned int base_size)
{
	int	count;

	if (base_size == 0)
		return (0);
	count = 0;
	while (num != 0)
	{
		num /= base_size;
		count++;
	}
	return (count);
}
