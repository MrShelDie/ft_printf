SRC	= \
ft_printf.c	\
parser/ft_parser_utils.c				parser/ft_parser.c													\
print_tab/ft_init_tab.c					print_tab/ft_print_tab_c.c			print_tab/ft_print_tab_perc.c	\
print_tab/ft_print_tab_s.c				print_tab/ft_print_tab_x.c			print_tab/ft_print_tab.c		\
print_tab/ft_print_tab_p.c				print_tab/ft_print_tab_u.c			print_tab/ft_print_tab_d.c 		\
print_tab_utils/ft_utoa_prec_base.c		print_tab_utils/ft_unumlen_base.c


OBJ		= ${SRC:.c=.o}

NAME	= libftprintf.a

CFLSGS	= -Wall -Werror -Wextra


%.o:	%.c
	gcc -c ${CFLSGS} $< -o $@

all:	${SRC} ${NAME}

${NAME}:	${OBJ}
	ar rcs ${NAME} ${OBJ}

bonus:	${SRC} ${NAME}

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re:	fclean all


.PHONY: all bonus clean fclean re