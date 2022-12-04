# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tquere <tquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 14:22:29 by tquere            #+#    #+#              #
#    Updated: 2022/12/04 16:15:48 by tquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     			all $(NAME) clear mkbuild lib minilibx clear clean fclean re

NAME					= fdf
	
BUILD_DIR				= build/
	
DIR						= src/
SRC			 			= main.c parsing_map.c
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)
HEADER_DIR				= src/
HEADER_FILE				= fdf.h
	
LIBFT					= libft.a
LIB_DIR					= libft/

MINILIB					= libmlx.a
MINILIB_DIR				= minilibx_macos/
	
GCC						= gcc
CFLAGS					= -Wall -Wextra -Werror
SANITIZE				= $(CFLAGS) -g -fsanitize=address
	
RM 						= rm -rf
CLEAR					= clear

FRAMEWORKS	= \
			  OpenGL \
			  AppKit \

FRAMEWORKS	:= $(addprefix -framework , $(FRAMEWORKS))

all: 					clear mkbuild lib minilibx $(NAME) $(HEADER_DIR)
						
mkbuild:
						mkdir -p build

clear:
						$(CLEAR)

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR)/$(HEADER_FILE)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -c $< -o $@

$(NAME): 				$(OBJECTS)
						$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(FRAMEWORKS)

lib:
						@make -C $(LIB_DIR)

minilibx:
						@make -C $(MINILIB_DIR)
						
clean:					
						@${RM} $(OBJECTS_BONUS) $(OBJECTS)
						@make clean -C $(LIB_DIR)
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR)

re:						fclean all