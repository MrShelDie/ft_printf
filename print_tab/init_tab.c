#include "../ft_printf.h"

// char	*create_tab(t_format *format, int len)
// {
// 	char	*tab;

// 	tab = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!tab)
// 		return (NULL);
// 	if (format->flag_zero)
// 		ft_memset(tab, '0', len);
// 	else
// 		ft_memset(tab, ' ', len);
// 	tab[len] = '\0';
// 	return (tab);
// }

void	init_tab(t_format *format, char *tab, int size)
{
	if (format->flag_zero)
		ft_memset(tab, '0', size - 1);
	else
		ft_memset(tab, ' ', size - 1);
	tab[size - 1] = '\0';
}
