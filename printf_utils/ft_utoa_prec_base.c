/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_prec_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:13:16 by gannemar          #+#    #+#             */
/*   Updated: 2021/11/19 15:13:17 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_utoa_prec_base(size_t num, char *base, size_t base_size, int prec)
{
	char	*str;

	str = malloc(sizeof(char) * (prec + 1));
	if (!str)
		return (NULL);
	str[prec] = '\0';
	while (--prec != -1)
	{
		str[prec] = base[num % base_size];
		num /= base_size;
	}
	return (str);
}
