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
BONUS	 			= 
OBJECTS_BONUS		= $(BONUS:%.c=%.o)

#Pour les test
TEST_SRC			= 
TEST_OBJECT			= $(TEST_SRC:%.c=%.o)

#Option compilation
GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror
SANITIZE			= $(CFLAGS) -g -fsanitize=address

#Autres commande
RM 					= rm -rf
CLEAR				= clear

all: 		$(NAME) Makefile

%.o:		%.c $(HEADER) 
			$(GCC) $(CFLAGS) -I$(HEADER) -I$(LIB_DIR) -c $< -o $@

$(NAME): 	clear lib $(TEST_OBJECT) $(OBJECTS) $(HEADER) Makefile
			@$(GCC) $(SANITIZE) $(TEST_OBJECT) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT)  

bonus: 		clear lib $(TEST_OBJECT) $(OBJECTS_BONUS) Makefile
			@$(GCC) $(SANITIZE) $(TEST_OBJECT) $(OBJECTS_BONUS) -o $(NAME) $(LIB_DIR)$(LIBFT) 

lib:		Makefile
			cd $(LIB_DIR) && make

clear:
			$(CLEAR)

clean:
			@${RM} ${TEST_OBJECT} $(OBJECTS_BONUS) $(OBJECTS) $(OBJ_LIB)
			@cd $(LIB_DIR) && make clean

fclean:		clear clean
			@${RM} ${LIB_NAME}
			@${RM} ${NAME}
			@cd $(LIB_DIR) && make fclean

re:			fclean all