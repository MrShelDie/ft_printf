/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:13:21 by gannemar          #+#    #+#             */
/*   Updated: 2021/11/19 15:13:22 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_spec(const char **str, va_list args, int *printed_count)
{
	t_format	format;

	if (**str != '%')
		return (SUCCESS);
	ft_init_format(&format);
	if (!ft_parse(str, &format))
		return (FAILE);
	if (format.conv == '\0')
		return (SUCCESS);
	if (!ft_print_tab(&format, args, printed_count))
		return (FAILE);
	return (SUCCESS);
}

static void	ft_print_not_spec(const char **str, int *printed_count)
{
	int	write_size;

	write_size = 0;
	while ((*str)[write_size] && (*str)[write_size] != '%')
		write_size++;
	write(1, *str, write_size);
	(*str) += write_size;
	(*printed_count) += write_size;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_count;

	if (!str)
		return (-1);
	printed_count = 0;
	va_start(args, str);
	while (*str)
	{
		ft_print_not_spec(&str, &printed_count);
		if (!ft_print_spec(&str, args, &printed_count))
		{
			printed_count = -1;
			break ;
		}
	}
	va_end(args);
	return (printed_count);
}
