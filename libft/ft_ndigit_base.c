# include "libft.h"

int	ft_ndigit_base(long int num, unsigned long int base)
{
	long long int	lnum;
	long long int	lbase;
	int				count;

	count = 0;
	lnum = (long long int)num;
	lbase = (long long int)base;
	if (num < 0)
	{
		lnum *= -1;
		count++;
	}
	while (lnum / lbase > 0)
	{
		lnum /= lbase;
		count++;
	}
	return (count);
}
