SRCS 	= ft_print.c ft_print2.c ft_read.c ft_small.c main.c

OBJS 	= ${SRCS:.c=.o}

NAME 	= ft_hexdump

HEAD	= stock_strs.h

GCC 	= gcc

RM 		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

.c.o: 
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS} Makefile
			${GCC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY:     all clean fclean
