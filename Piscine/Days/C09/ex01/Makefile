SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS = ${SRCS:.c=.o}

CC = gcc

HEAD = includes/ft.h

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

LIB = ar rc

LLIB = ranlib

RM = rm -f

.c.o:
	${CC} ${FLAGS} -I${HEAD} -c $< -o ${<:.c=.o}

libft.a:    commands

all:    ${NAME}

commands:    ${OBJS}
	${LIB} ${NAME} ${OBJS}
	${LLIB} ${NAME}

clean:
	${RM} ${OBJS}

fclean:        clean
	${RM} ${NAME}

re:        fclean all

.PHONY: all clean fclean re
