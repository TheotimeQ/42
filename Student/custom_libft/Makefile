# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 09:10:28 by tquere            #+#    #+#              #
#    Updated: 2022/11/21 13:36:52 by zelinsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     		all $(NAME) test bonus clean fclean re

NAME				= libft.a
HEADER				= libft.h
TEST_OUTPUT			= test

SOURCE		 		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECTS			    = $(SOURCE:%.c=build/%.o)

MY_GBC	 			= gbc_show.c gbc_add.c gbc_all_clear.c gbc_init.c gbc_remove.c 
MY_MALLOC			= ft_malloc.c ft_malloc_free_tab.c ft_malloc_print_tab.c ft_malloc_atoi.c ft_malloc_itoa.c ft_malloc_join.c ft_malloc_split.c ft_malloc_str.c ft_malloc_substr.c
MY_LIBFT			= $(MY_GBC:%.c=build/%.o) $(MY_MALLOC:%.c=build/%.o)

ALL_OBJECT			= ${OBJECTS} ${MY_LIBFT}

GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror
SANITIZE			= -Wall -Wextra -Werror -g -fsanitize=address
LIB 				= ar -crs

RM 					= rm -rf

all: 			$(NAME) Makefile

build/%.o:		basic_libft/%.c $(HEADER) Makefile
				$(GCC) $(CFLAGS) -include$(HEADER) -c $< -o $@

build/%.o:		garbage_collector/%.c $(HEADER) Makefile
				$(GCC) $(CFLAGS) -include$(HEADER) -c $< -o $@

build/%.o:		malloc_libft/%.c $(HEADER) Makefile
				$(GCC) $(CFLAGS) -include$(HEADER) -c $< -o $@

leak_checker/%.o:	leak_checker/%.c $(HEADER) Makefile
					$(GCC) $(CFLAGS) -include$(HEADER) -c $< -o $@

$(NAME): 		${ALL_OBJECT} $(MY_LIBFT) $(HEADER) Makefile 
				@${LIB} ${NAME} ${ALL_OBJECT}

test:			$(ALL_OBJECT) $(HEADER) Makefile
				@echo "----Ready for sanitizing ? ----"
				@$(GCC) $(SANITIZE) $(ALL_OBJECT) -o $(TEST_OUTPUT)  
				@echo 'run ./$(TEST_OUTPUT) to test'

clean:	
				@${RM} ${ALL_OBJECT}
				
fclean:			clean
				@${RM} ${NAME}

re:				fclean all
