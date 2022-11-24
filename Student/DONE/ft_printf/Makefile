# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tquere <tquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:11:31 by tquere            #+#    #+#              #
#    Updated: 2022/11/24 14:41:52 by tquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     		all $(NAME) lib clean fclean re

NAME				= libftprintf.a
HEADER				= ft_printf.h

SOURCE		 		= print_pourc.c ft_print_str.c ft_printf.c print_c.c print_s.c print_p.c print_d.c print_i.c print_u.c print_x.c print_xx.c convert.c
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

clean:
			@${RM} $(OBJECTS) 

fclean:		clean
			@${RM} ${NAME}

re:			fclean all