.PHONY:     		all $(NAME) $(NAME_BONUS) bonus lib clear clean fclean re

NAME				= push_swap
NAME_BONUS			= checker

#Build
BUILD_DIR			= build/

#Sans bonus
DIR					= basic/
SRC			 		= main.c debug.c stack.c stack_operation_a.c stack_operation_b.c stack_operation_both.c resolve_utils.c resolve.c
OBJECTS			    = $(SRC:%.c=$(BUILD_DIR)%.o)
HEADER				= .

#Avec bonus
DIR_BONUS			= bonus/
SRC_BONUS			= checker_bonus.c get_line_bonus.c get_line_utils_bonus.c
OBJECTS_BONUS		= $(SRC_BONUS:%.c=$(BUILD_DIR)%.o)
HEADER_BONUS		= bonus/

#Libft
LIBFT				= libft.a
LIB_DIR				= libft/

#Option compilation
GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror
SANITIZE			= $(CFLAGS) -g -fsanitize=address

#Autres commande
RM 					= rm -rf
CLEAR				= clear

all: 					lib $(NAME) $(HEADER) Makefile

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER) 
						$(GCC) $(CFLAGS) -I$(HEADER) -I$(LIB_DIR) -c $< -o $@

$(BUILD_DIR)%.o:		$(DIR_BONUS)%.c $(HEADER_BONUS) 
						$(GCC) $(CFLAGS) -I$(HEADER_BONUS) -I$(LIB_DIR) -c $< -o $@

$(NAME): 				$(OBJECTS)
						$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT)  

bonus: 					$(OBJECTS_BONUS)
						$(GCC) $(SANITIZE) $(OBJECTS_BONUS) -o $(NAME_BONUS) $(LIB_DIR)$(LIBFT) 

lib:
						@make -C $(LIB_DIR)

clean:
						@${RM} $(OBJECTS_BONUS) $(OBJECTS)
						@make clean -C $(LIB_DIR)

fclean:					clean
						@${RM} ${NAME} $(NAME_BONUS)
						@make fclean -C $(LIB_DIR)

re:						fclean all