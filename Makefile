SRC	= \
ft_printf.c																									\
parser/ft_parser_utils.c				parser/ft_parser.c													\
print_tab/ft_init_tab.c					print_tab/ft_print_tab_c.c			print_tab/ft_print_tab_perc.c	\
print_tab/ft_print_tab_s.c				print_tab/ft_print_tab_x.c			print_tab/ft_print_tab.c		\
print_tab/ft_print_tab_p.c				print_tab/ft_print_tab_u.c			print_tab/ft_print_tab_d.c 		\
printf_utils/ft_utoa_prec_base.c		printf_utils/ft_unumlen_base.c		printf_utils/ft_strlen.c		\
printf_utils/ft_memcpy.c				printf_utils/ft_isdigit.c			printf_utils/ft_atoi.c			\
printf_utils/ft_bzero.c					printf_utils/ft_memset.c

OBJ		= ${SRC:.c=.o}

DEPS	= ${OBJ:.o=.d}

HEDR	= ft_printf.h

NAME	= libftprintf.a

CC	= gcc

CFLAGS		= -Wall -Werror -Wextra
CPPFLAGS	= -MMD -I.
ARFLAGS		= rcs


all:	${NAME}

${NAME}:	${OBJ}
	${AR} ${ARFLAGS} ${NAME} $?

%.o:	%.c
	${CC} -c ${CFLAGS} ${CPPFLAGS} $< -o $@

bonus:	${NAME}

clean:
	${RM} ${DEPS} ${OBJ}

fclean:	clean
	${RM} ${NAME}

re:	fclean all


.PHONY: all bonus clean fclean re

-include ${DEPS}