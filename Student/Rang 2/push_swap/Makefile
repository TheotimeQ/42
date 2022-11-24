.PHONY:     		all $(NAME) bonus lib clear clean fclean re

NAME				= push_swap
HEADER				= .

#Libft
LIBFT				= libft.a
LIB_DIR				= libft/
OBJ_LIB			    = $(find ./$(libft) -name "*.o")

#Sans bonus
SOURCE		 		= main.c push_swap.c stack.c stack_operation_a.c stack_operation_b.c stack_operation_both.c
OBJECTS			    = $(SOURCE:%.c=%.o)

#Avec bonus
BONUS	 			= checker_bonus.c
OBJECTS_BONUS		= $(BONUS:%.c=%.o)

#Option compilation
GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror
SANITIZE			= $(CFLAGS) -g -fsanitize=address

#Autres commande
RM 					= rm -rf
CLEAR				= clear

all: 		lib $(NAME) $(HEADER) Makefile

%.o:		%.c $(HEADER) 
			$(GCC) $(CFLAGS) -I$(HEADER) -I$(LIB_DIR) -c $< -o $@

$(NAME): 	lib $(TEST_OBJECT) $(OBJECTS) $(HEADER) Makefile
			@$(GCC) $(SANITIZE) $(TEST_OBJECT) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT)  

bonus: 		lib $(TEST_OBJECT) $(OBJECTS_BONUS) Makefile
			@$(GCC) $(SANITIZE) $(TEST_OBJECT) $(OBJECTS_BONUS) -o $(NAME) $(LIB_DIR)$(LIBFT) 

lib:		Makefile
			make -C $(LIB_DIR)

clean:
			${RM} $(OBJECTS_BONUS) $(OBJECTS) $(OBJ_LIB)
			make clean -C $(LIB_DIR)

fclean:		clear clean
			@${RM} ${NAME}
			make fclean -C $(LIB_DIR)

re:			fclean all