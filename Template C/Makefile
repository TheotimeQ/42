# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 16:06:55 by tquere            #+#    #+#              #
#    Updated: 2022/11/07 16:58:45 by zelinsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Help makefile : https://shiftcode.fr/comprendre-les-makefiles/

.PHONY:     all clean clear fclean re

NAME	=	test

SRCS 	=	main.c
OBJS 	=	${SRCS:.c=.o}
INCS	=	header.h

GCC 	=	gcc
CFLAGS 	=	-Wall -Wextra -Werror # -g -fsanitize=address
CI		=	-I .
RM 		=	rm -rf
CLR		=	clear

OBJDIR	=	./obj

all:	clear ${NAME} moove


${NAME}:	${OBJS}	${INCS}	Makefile
			${GCC} ${CFLAG}	${OBJS}	-o $@

%.o:	%.c	${INCS} Makefile
			${GCC} ${CFLAGS} ${CI} -c $< -o $@

clean:
			mv ${OBJDIR}/*.o .
			${RM} ${OBJS}

clear:
			${CLR}

moove:
			mv *.o ${OBJDIR}

fclean:		clean
			${RM} ${NAME}

re:			fclean all


# gcc -o ca link des .o
# gcc -c ca compile 