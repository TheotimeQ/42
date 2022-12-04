# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tquere <tquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 09:38:46 by tquere            #+#    #+#              #
#    Updated: 2022/12/04 13:35:20 by tquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     			all $(NAME) mkbuild lib clear clean fclean re

NAME					= push_swap
	
BUILD_DIR				= build/
	
DIR						= basic/
SRC			 			= args_utils.c push_swap.c stack.c stack_operation_a.c stack_operation_b.c stack_operation_both.c resolve_utils.c resolve.c chunk.c min_max.c resolve_chunk.c resolve_chunk_utils.c rot_dir.c stack_cpy.c test_min_to_top.c 
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)
HEADER					= basic/
	
LIBFT					= libft.a
LIB_DIR					= libft/
	
GCC						= gcc
CFLAGS					= -Wall -Wextra -Werror
SANITIZE				= $(CFLAGS) -g -fsanitize=address
	
RM 						= rm -rf
CLEAR					= clear

all: 					mkbuild lib $(NAME) $(HEADER)
						
mkbuild:
						mkdir -p build

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER)/push_swap.h
						$(GCC) $(CFLAGS) -I$(HEADER) -I$(LIB_DIR) -c $< -o $@

$(NAME): 				$(OBJECTS)
						$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT)  

lib:
						@make -C $(LIB_DIR)

clean:					
						@${RM} $(OBJECTS_BONUS) $(OBJECTS)
						@make clean -C $(LIB_DIR)
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR)

re:						fclean all