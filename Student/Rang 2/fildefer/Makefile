# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tquere <tquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 14:22:29 by tquere            #+#    #+#              #
#    Updated: 2022/12/06 17:13:43 by tquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     			all $(NAME) clear mkbuild lib minilibx clear clean fclean re

NAME					= fdf
	
BUILD_DIR				= build/
	
HEADER_DIR				= src/
HEADER_FILE				= fdf.h

DIR						= src/
SRC			 			= debug.c main.c main_malloc.c main_args.c map_error.c map_parsing.c matrice_point_3d.c matrice_malloc.c matrice_projection.c mlx_init.c mlx_image_update.c matrice_product.c matrice_scale.c matrice_translation.c matrice_translation_create.c matrice_rotation.c mlx_draw_point.c 
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)
	
LIBFT					= libft.a
LIB_DIR					= libft/

	
GCC						= gcc
CFLAGS					= #-Wall -Wextra -Werror
SANITIZE				= $(CFLAGS) -g3 -fsanitize=address

RM 						= rm -rf
CLEAR					= clear

MINILIB					= libmlx.a

MINILIB_DIR				= minilibx_macos/
MAC						= OpenGL AppKit 
MAC						:= $(addprefix -framework , $(MAC))

# MINILIB_DIR				= minilibx_linux/
# LINUX					= -Lminilibx_linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz 

all: 					clear mkbuild lib minilibx $(NAME) $(HEADER_DIR)
						
mkbuild:
						mkdir -p build

clear:
						$(CLEAR)

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR)/$(HEADER_FILE)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -I/usr/include -O3 -c $< -o $@

$(NAME): 				$(OBJECTS)
						$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(MAC) $(LINUX)
lib:
						@make -C $(LIB_DIR)

minilibx:
						@make -C $(MINILIB_DIR)
						
clean:					
						@${RM} $(OBJECTS)
						@make clean -C $(LIB_DIR)
						@make clean -C $(MINILIB_DIR)
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR)
						@make clean -C $(MINILIB_DIR)

re:						fclean all