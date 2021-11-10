# include "libft.h"

int	ft_ndigit_base(int num, unsigned int base)
{
	long int	lnum;
	long int	lbase;
	int			count;

	if (base == 0)
		return (0);
	if (num == 0)
		return (1);
	count = 0;
	lnum = (long int)num;
	lbase = (long int)base;
	if (num < 0)
	{
		lnum *= -1;
		count++;
	}
	while (lnum != 0)
	{
		lnum /= lbase;
		count++;
	}
	return (count);
}
