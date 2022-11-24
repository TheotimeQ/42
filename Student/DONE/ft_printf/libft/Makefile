# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tquere <tquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:07:53 by tquere            #+#    #+#              #
#    Updated: 2022/11/24 11:08:07 by tquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libft.a
HEADER				= libft.h

SOURCE		 		= ft_substr.c ft_bzero.c ft_itoa.c ft_memset.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strlen.c ft_toupper.c 
OBJECTS			    = $(SOURCE:%.c=%.o)

BONUS	 			= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECTS_BONUS		= $(BONUS:%.c=%.o)

GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror 
LIB 				= ar -crs

RM 					= rm -rf

all: 		$(NAME) Makefile

%.o:		%.c $(HEADER) Makefile
			$(GCC) $(CFLAGS) -include $(HEADER) -c $< -o $@

$(NAME): 	${OBJECTS} $(HEADER) Makefile 
			${LIB} ${NAME} ${OBJECTS}

bonus:		${OBJECTS_BONUS} ${OBJECTS} Makefile
			${LIB} ${NAME} ${OBJECTS} ${OBJECTS_BONUS}

clean:
			${RM} ${OBJECTS} ${OBJECTS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all