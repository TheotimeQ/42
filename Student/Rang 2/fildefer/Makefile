# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 14:22:29 by tquere            #+#    #+#              #
#    Updated: 2023/01/31 12:10:19 by zelinsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     			all $(NAME) clear mkbuild lib minilibx clear clean fclean re

NAME					= fdf

BUILD_DIR				= build/
	
HEADER_DIR				= src/
HEADER_FILE				= fdf.h
HEADER_FILE_KEYS		= fdf_keys.h

DIR						= src/
SRC			 			= debug.c main.c main_malloc.c main_args.c map_error.c map_parsing.c matrice_point_3d.c matrice_malloc.c matrice_projection.c mlx_init.c mlx_image_update.c matrice_scale.c matrice_translation.c matrice_rotation.c matrice_rotation_prod.c draw_point.c mlx_moove.c
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)
	
LIBFT					= libft.a
LIB_DIR					= libft/

	
GCC						= gcc
CFLAGS					= -Wall -Wextra -Werror
SANITIZE				= #$(CFLAGS) -g3 -fsanitize=address

RM 						= rm -rf
CLEAR					= clear

MINILIB					= libmlx.a

# MINILIB_DIR				= minilibx_macos/
# MAC						= -framework OpenGL -framework AppKit 

MINILIB_DIR				= minilibx_linux/
LINUX					= -Lminilibx_linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR)/$(HEADER_FILE) $(HEADER_DIR)/$(HEADER_FILE_KEYS)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -I/usr/include -O3 -c $< -o $@

all: 					clear mkbuild lib minilibx $(HEADER_DIR) $(NAME) 
						
mkbuild:
						mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
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