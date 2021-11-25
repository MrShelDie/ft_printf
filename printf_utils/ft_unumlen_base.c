/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:13:06 by gannemar          #+#    #+#             */
/*   Updated: 2021/11/19 15:13:12 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_unumlen_base(size_t num, size_t base_size)
{
	int	count;

	if (base_size == 0)
		return (0);
	if (num == 0)
		return (1);
	count = 0;
	while (num != 0)
	{
		num /= base_size;
		count++;
	}
	return (count);
}
