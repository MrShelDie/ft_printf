#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define FAILE 0
# define SUCCESS 1

# define FALSE 0
# define TRUE 1

typedef struct s_format
{
	unsigned int	flag_sharp : 1;
	unsigned int	flag_zero : 1;
	unsigned int	flag_minus : 1;
	unsigned int	flag_space : 1;
	unsigned int	flag_plus : 1;
	unsigned int	is_width_default : 1;
	unsigned int	is_prec_default : 1;
	char			conv;
	int				width;
	int				prec;
}	t_format;

typedef struct s_str
{
	char	*str;
	size_t	size;
}	t_str;

int		parse(const char **str, t_format *format);
void	init_format(t_format *format);
void	get_flags(const char **str, t_format *format);
void	get_width(const char **str, t_format *format);
void	get_prec(const char **str, t_format *format);
int		get_conv(const char **str, t_format *format);
void	print_tab(const char **str, t_format *format,
			va_list args, int *printed_count);

#endif
