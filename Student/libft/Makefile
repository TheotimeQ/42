

.PHONY:     all sanit bonus clean fclean re

NAME		=	libft.a

SRCS 		=	ft_.c
OBJS 		=	${SRCS:.c=.o}
HEAD		=	libft.h

GCC 		=	gcc
CFLAGS 		=	-Wall -Wextra -Werror
SANIT_FLAG 	=	-g -fsanitize=address

RM 			=	rm -rf
LIB 		=   ar rc

all:	 ${NAME} moove

${NAME}:	${OBJS}	${HEAD}	Makefile
			${GCC} ${CFLAG}	${OBJS}	-o $@
			

%.o:	%.c	${HEAD} Makefile
			${GCC} ${CFLAGS} -I -c $< -o $@

make_lib:	${OBJS}
			${LIB} ${NAME} ${OBJS}

sanit:		${OBJS}	${HEAD}	Makefile
			${GCC} ${CFLAG} ${SANIT_FLAG} ${OBJS}	-o $@

bonus:
			echo "bonus"

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all