/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_perc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:12:18 by gannemar          #+#    #+#             */
/*   Updated: 2021/11/19 15:12:19 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_tab_perc(t_format *format, int *printed_count, int *error)
{
	ft_print_tab_s(format, "%", printed_count, error);
}
