/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:12:48 by gannemar          #+#    #+#             */
/*   Updated: 2021/11/19 15:12:49 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_tab_prec(t_format *format, size_t arg)
{
	int	arg_len;

	if (!format->is_prec_default && format->prec == 0 && arg == 0)
		return (0);
	arg_len = ft_unumlen_base(arg, 16);
	if (!format->is_prec_default && format->prec > arg_len)
		return (format->prec);
	return (arg_len);
}

static int	ft_get_tab_width(t_format *format)
{
	int	width;

	width = format->prec;
	if (format->flag_sharp)
		width += 2;
	if (!format->is_width_default && format->width > width)
		return (format->width);
	return (width);
}

static void	ft_fill_tab(t_format *format, char *tab, char *num_str)
{
	char	prefix[2];

	if (format->conv == 'X')
		ft_memcpy(prefix, "0X", 2);
	else
		ft_memcpy(prefix, "0x", 2);
	if (format->flag_minus)
	{
		if (format->flag_sharp)
		{
			ft_memcpy(tab, prefix, 2);
			ft_memcpy(tab + 2, num_str, format->prec);
		}
		else
			ft_memcpy(tab, num_str, format->prec);
	}
	else
	{
		if (format->flag_sharp && format->flag_zero)
			ft_memcpy(tab, prefix, 2);
		else if (format->flag_sharp)
			ft_memcpy(tab + (format->width - format->prec - 2), prefix, 2);
		ft_memcpy(tab + (format->width - format->prec), num_str, format->prec);
	}
}

static int	ft_put_tab(t_format *format, char *tab, size_t arg)
{
	char	*num_str;

	if (format->conv == 'X')
		num_str = ft_utoa_prec_base(arg, "0123456789ABCDEF", 16, format->prec);
	else
		num_str = ft_utoa_prec_base(arg, "0123456789abcdef", 16, format->prec);
	if (!num_str)
		return (FAILE);
	ft_fill_tab(format, tab, num_str);
	write(1, tab, format->width);
	free(num_str);
	return (SUCCESS);
}

void	ft_print_tab_x(
	t_format *format, size_t arg, int *printed_count, int *error
)
{
	char	*tab;

	if (arg == 0)
		format->flag_sharp = FALSE;
	format->prec = get_tab_prec(format, arg);
	format->width = ft_get_tab_width(format);
	tab = (char *)malloc(sizeof(char) * (format->width + 1));
	if (!tab)
	{
		*error = 1;
		return ;
	}
	ft_init_tab(format, tab, format->width + 1);
	if (!ft_put_tab(format, tab, arg))
	{
		*error = 1;
		free(tab);
		return ;
	}
	free(tab);
	*printed_count += format->width;
}
