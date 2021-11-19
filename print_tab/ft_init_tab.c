/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:11:24 by gannemar          #+#    #+#             */
/*   Updated: 2021/11/19 15:11:26 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_init_tab(t_format *format, char *tab, int size)
{
	if (format->flag_zero)
		ft_memset(tab, '0', size - 1);
	else
		ft_memset(tab, ' ', size - 1);
	tab[size - 1] = '\0';
}
