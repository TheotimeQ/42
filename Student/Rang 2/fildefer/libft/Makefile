# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tquere <tquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:23:47 by tquere            #+#    #+#              #
#    Updated: 2022/12/04 17:38:12 by tquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     		all $(NAME) bonus clean fclean re

NAME				= libft.a
HEADER				= libft.h

BUILD_DIR			= ../build/

SOURCE		 		= get_next_line_utils.c get_next_line.c ft_printf.c ft_write_protect.c ft_put_base_long.c ft_is_double.c ft_isnum.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJECTS			    = $(SOURCE:%.c=$(BUILD_DIR)%.o)

GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror 
LIB 				= ar -crs

RM 					= rm -rf

all: 		$(NAME) 

$(BUILD_DIR)%.o:		%.c $(HEADER) 
						$(GCC) $(CFLAGS) -include $(HEADER) -c $< -o $@

$(NAME): 				${OBJECTS} $(HEADER)  
						${LIB} ${NAME} ${OBJECTS}

clean:			
						${RM} ${OBJECTS} ${OBJECTS_BONUS}
						
fclean:					clean
						${RM} ${NAME}

re:						fclean all