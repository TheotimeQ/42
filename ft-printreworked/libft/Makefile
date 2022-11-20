# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tquere <tquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:23:47 by tquere            #+#    #+#              #
#    Updated: 2022/11/20 16:05:14 by tquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     		all $(NAME) bonus clean fclean re

NAME				= libft.a

HEADER				= .
SOURCE		 		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJECTS			    = $(SOURCE:%.c=%.o)

GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror 
LIB 				= ar -crs
RANLIB				= ranlib 

RM 					= rm -rf

all: 		$(NAME) Makefile

%.o:		%.c
			$(GCC) $(CFLAGS) -I$(HEADER) -c $< -o $@

$(NAME): 	${OBJECTS} Makefile
			@${LIB} ${NAME} ${OBJECTS}
			@${RANLIB} ${NAME}

clean:
			@${RM} ${OBJECTS}
fclean:		clean
			@${RM} ${NAME}

re:			fclean all