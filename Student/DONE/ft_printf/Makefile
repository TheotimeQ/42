# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tquere <tquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:11:31 by tquere            #+#    #+#              #
#    Updated: 2022/11/24 15:54:49 by tquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     		all $(NAME) lib clean fclean re

NAME				= libftprintf.a
HEADER				= ft_printf.h

SOURCE		 		= ft_printf.c ft_write_protect.c print_c.c print_d.c print_u.c print_x.c
OBJECTS			    = $(SOURCE:%.c=%.o)

GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror

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