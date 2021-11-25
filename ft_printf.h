/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gannemar <gannemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:13:32 by gannemar          #+#    #+#             */
/*   Updated: 2021/11/25 19:46:55 by gannemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define FAILE 0
# define SUCCESS 1

# define FALSE 0
# define TRUE 1

typedef struct s_format
{
	int		flag_sharp;
	int		flag_zero;
	int		flag_minus;
	int		flag_space;
	int		flag_plus;
	int		is_width_default;
	int		is_prec_default;
	int		width;
	int		prec;
	char	conv;
}	t_format;

typedef union u_arg
{
	unsigned char	c;
	unsigned int	x;
	unsigned int	u;
	const char		*s;
	void			*p;
	int				d;
}	t_arg;

int		ft_parse(const char **str, t_format *format);
void	ft_init_format(t_format *format);
void	ft_get_flags(const char **str, t_format *format);
void	ft_get_width(const char **str, t_format *format, int *error);
void	ft_get_prec(const char **str, t_format *format, int *error);
void	ft_get_conv(const char **str, t_format *format, int *error);

void	ft_init_tab(t_format *format, char *tab, int size);
int		ft_print_tab(t_format *format, va_list args, int *printed_count);
void	ft_print_tab_perc(t_format *format, int *printed_count, int *error);
void	ft_print_tab_c(t_format *format, unsigned char arg,
			int *printed_count, int *error);
void	ft_print_tab_s(t_format *format, const char *arg,
			int *printed_count, int *error);
void	ft_print_tab_x(t_format *format, size_t arg,
			int *printed_count, int *error);
void	ft_print_tab_p(t_format *format, void *arg,
			int *printed_count, int *error);
void	ft_print_tab_u(t_format *format, unsigned int arg,
			int *printed_count, int *error);
void	ft_print_tab_d(t_format *format, int arg,
			int *printed_count, int *error);

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst,
			const void *src, size_t n);
int		ft_isdigit(int c);
int		ft_atoi(const char *str, int *error);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_utoa_prec_base(size_t num, char *base, size_t base_size, int prec);
int		ft_unumlen_base(size_t num, size_t base_size);

int		ft_printf(const char *str, ...);

#endif
