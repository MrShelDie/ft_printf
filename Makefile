SRC	= \
ft_printf.c	\
parser/parser_utils.c		parser/parser.c											\
print_tab/init_tab.c		print_tab/print_tab_c.c		print_tab/print_tab_perc.c	\
print_tab/print_tab_s.c		print_tab/print_tab_x.c		print_tab/print_tab.c		\
print_tab/print_tab_p.c		print_tab/print_tab_u.c		print_tab/print_tab_d.c 	\
print_tab_utils/utoa_prec_base.c


OBJ		= ${SRC:.c=.o}

NAME	= libftprintf.a
LIB		= libft/libft.a

CFLSGS	= -Wall -Werror -Wextra


%.o:	%.c
	gcc -c ${CFLSGS} $< -o $@

all:	${SRC} ${LIB} ${NAME}

${NAME}:	${OBJ} 
	ar rcsT ${NAME} ${OBJ} ${LIB}

${LIB}:
	cd libft && make all && make clean && cd ..

test:
	gcc -g test.c ${SRC} libft/ft_unumlen_base.c ${LIB}

bonus:	${SRC} ${LIB} ${NAME}

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re:	fclean all


.PHONY: all bonus clean fclean