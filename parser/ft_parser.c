/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:11:17 by gannemar          #+#    #+#             */
/*   Updated: 2021/11/19 15:11:18 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_parse(const char **str, t_format *format)
{
	(*str)++;
	ft_get_flags(str, format);
	ft_get_width(str, format);
	ft_get_prec(str, format);
	if (!ft_get_conv(str, format))
		return (FAILE);
	return (SUCCESS);
}
