.PHONY:     		all $(NAME) sanit lib bonus clean fclean re

NAME				= test
HEADER				= get_next_line.h

#Sans bonus
SOURCE		 		= get_next_line.c get_next_line_utils.c
OBJECTS			    = $(SOURCE:%.c=%.o)

#Avec bonus
BONUS	 			= get_next_line.c get_next_line_utils.c
OBJECTS_BONUS		= $(BONUS:%.c=%.o)

#Pour les test
TEST_SRC			= main.c 
TEST_OBJECT			= $(TEST_SRC:%.c=%.o)

#Option compilation
GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror -D BUFFER_SIZE=3
SANITIZE			= $(CFLAGS) -g -fsanitize=address

#Autres commande
RM 					= rm -rf
CLEAR				= clear

all: $(NAME) Makefile

#Rule for Object
%.o:		%.c
			$(GCC) $(CFLAGS) -include$(HEADER) -c $< -o $@

sanit: 		lib $(TEST_OBJECT) $(OBJECTS) $(HEADER) Makefile
			@echo "----Ready for basic sanitizing ? ----"
			@$(GCC) $(SANITIZE) $(TEST_OBJECT) $(OBJECTS) -o basic $(LIB_DIR)$(LIBFT)  
			@echo 'run ./basic to test'

sanit_bonus: 	lib $(TEST_OBJECT) $(OBJECTS_BONUS) $(HEADER) Makefile
				@echo "----Ready for bonus sanitizing ? ----"
				@$(GCC) $(SANITIZE) $(TEST_OBJECT) $(OBJECTS_BONUS) -o bonus $(LIB_DIR)$(LIBFT)  
				@echo 'run ./bonus to test'

clean:
			@${RM} ${TEST_OBJECT} $(OBJECTS_BONUS) $(OBJECTS) $(OBJ_LIB)
			@cd $(LIB_DIR) && make clean

fclean:		clean
			@${RM} ${LIB_NAME}
			@${RM} ${NAME}
			@cd $(LIB_DIR) && make fclean


re:			fclean all