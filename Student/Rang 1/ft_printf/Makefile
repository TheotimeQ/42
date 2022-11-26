# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:11:31 by tquere            #+#    #+#              #
#    Updated: 2022/11/26 17:33:35 by zelinsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     		all $(NAME) test clean fclean re

NAME				= libftprintf.a
HEADER				= ft_printf.h

SOURCE		 		= ft_printf.c ft_write_protect.c
OBJECTS			    = $(SOURCE:%.c=%.o)

GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror
SANITIZE			= $(CFLAGS) #-g -fsanitize=address

RM 					= rm -rf
LIB 				= ar -crs

all: 		$(NAME) $(HEADER) Makefile

%.o:		%.c $(HEADER) Makefile
			$(GCC) $(CFLAGS) -include$(HEADER) -c $< -o $@

$(NAME):	$(HEADER) $(OBJECTS) Makefile
			${LIB} ${NAME} ${OBJECTS} 

test: 		$(OBJECTS) Makefile
			@$(GCC) $(SANITIZE) $(OBJECTS) -o test 

clean:
			@${RM} $(OBJECTS) 

fclean:		clean
			@${RM} ${NAME}

re:			fclean all