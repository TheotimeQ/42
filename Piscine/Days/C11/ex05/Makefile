SRCS 	= $(wildcard *.c) 

OBJS 	= ${SRCS:.c=.o}

NAME 	= do-op

GCC 	= gcc

RM 		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

.c.o: 
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			${GCC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY:     all clean fclean
