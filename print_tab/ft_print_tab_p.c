/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:12:12 by gannemar          #+#    #+#             */
/*   Updated: 2021/11/19 15:12:13 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_tab_p(
	t_format *format, void *arg, int *printed_count, int *error
)
{
	if (arg == NULL)
	{
		if (format->is_prec_default)
			ft_print_tab_s(format, "0x0", printed_count, error);
		else
		{
			format->is_prec_default = TRUE;
			ft_print_tab_s(format, "0x", printed_count, error);
		}
		return ;
	}
	format->flag_sharp = TRUE;
	ft_print_tab_x(format, (size_t)arg, printed_count, error);
}
