/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:11:17 by gannemar          #+#    #+#             */
/*   Updated: 2021/11/25 19:45:52 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_parse(const char **str, t_format *format)
{
	int	error;

	error = 0;
	(*str)++;
	ft_get_flags(str, format);
	ft_get_width(str, format, &error);
	ft_get_prec(str, format, &error);
	ft_get_conv(str, format, &error);
	if (error)
		return (FAILE);
	return (SUCCESS);
}
