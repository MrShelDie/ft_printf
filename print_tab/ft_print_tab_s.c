/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:12:24 by gannemar          #+#    #+#             */
/*   Updated: 2021/11/19 15:12:25 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_tab_prec(t_format *format, const char *arg)
{
	int	arg_len;

	arg_len = ft_strlen(arg);
	if (!format->is_prec_default && format->prec < arg_len)
		return (format->prec);
	return (arg_len);
}

static int	ft_get_tab_width(t_format *format)
{
	if (!format->is_width_default && format->width > format->prec)
		return (format->width);
	return (format->prec);
}

static void	ft_put_tab(t_format *format, char *tab, const char *arg)
{
	if (format->flag_minus)
		ft_memcpy(tab, arg, format->prec);
	else
		ft_memcpy(tab + (format->width - format->prec), arg, format->prec);
	write(1, tab, format->width);
}

void	ft_print_tab_s(
	t_format *format, const char *arg, int *printed_count, int *error
)
{
	char	*tab;

	if (!arg)
		arg = "(null)";
	format->prec = get_tab_prec(format, arg);
	format->width = ft_get_tab_width(format);
	tab = (char *)malloc(sizeof(char) * (format->width + 1));
	if (!tab)
	{
		*error = 1;
		return ;
	}
	ft_init_tab(format, tab, format->width + 1);
	ft_put_tab(format, tab, arg);
	free(tab);
	*printed_count += format->width;
}
