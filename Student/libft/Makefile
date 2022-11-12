# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tquere <tquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:23:47 by tquere            #+#    #+#              #
#    Updated: 2022/11/12 15:29:12 by tquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     		all $(NAME) bonus clean fclean re

NAME				= libft.a

DIRbonus			= bonus

SOURCE		 		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJECTS			    = $(SOURCE:%.c=%.o)
HEADER				= .

BONUS	 			= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECTSbonus		= $(BONUS:%.c=%.o)
HEADERbonus		= bonus/

GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror 
LIB 				= ar -crs

RM 					= rm -rf

all: $(NAME) Makefile

%.o:		%.c
			$(GCC) $(CFLAGS) -I $(HEADERbonus) -I$(HEADER) -c $< -o $@

%.o:		$(DIRbonus)/%.c
			$(GCC) $(CFLAGS) -I $(HEADERbonus) -c $< -o $@

$(NAME): 	${OBJECTS} $(HEADER) Makefile 
			${LIB} ${NAME} ${OBJECTS}

bonus:		${OBJECTSbonus} ${OBJECTS} Makefile
			${LIB} ${NAME} ${OBJECTS} ${OBJECTSbonus}

clean:
			${RM} ${OBJECTS} ${OBJECTSbonus}

fclean:		clean
			${RM} ${NAME}

re:			fclean all