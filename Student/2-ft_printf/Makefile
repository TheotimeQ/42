.PHONY:     		all $(NAME) sanit lib bonus clean fclean re

LIB_NAME			= libftprintf.a
NAME				= test

#Directory
DIR_BONUS			= bonus/
LIB_DIR				= libft/

#Sans bonus
SOURCE		 		= 
OBJECTS			    = $(SOURCE:%.c=%.o)
HEADER				= .

#Avec bonus
BONUS	 			= 
OBJECTS_BONUS		= $(BONUS:$(DIR_BONUS)/%.c=%.o)
HEADER_BONUS		= $(DIR_BONUS)

#Pour les test
TEST_SRC			= main.c 
TEST_OBJECT			= $(TEST_SRC:%.c=%.o) $(OBJECTS) $(OBJECTS_BONUS)

#Option compilation
GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror 
SANITIZE			= $(CFLAGS) -g -fsanitize=address

#Autres commande
RM 					= rm -rf
CLEAR				= clear


all: $(NAME) Makefile

#Rule for Object
%.o:				%.c
					$(GCC) $(CFLAGS) -I$(HEADER_BONUS) -I$(HEADER) -c $< -o $@

%.o:				$(DIR_BONUS)/%.c
					$(GCC) $(CFLAGS) -I$(HEADER_BONUS) -I$(HEADER) -c $< -o $@


#Rule for compile
$(NAME):	lib $(TEST_OBJECT) $(HEADER) Makefile 
			@echo "----Compiling----"
			@$(GCC) $(CFLAGS) $(TEST_OBJECT) -o $(NAME) $(LIB_NAME) 
			@echo 'run ./$(NAME) to test'

sanit: 		lib $(OBJECTS) $(HEADER) Makefile
			@echo "----Ready for sanitizing ? ----"
			$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_NAME)
			@echo 'run ./$(NAME) to test'

#Rule to make lib
lib:		Makefile
			@echo "----Making Lib----"
			cd $(LIB_DIR) && make

#Rule to make bonus
bonus:		lib ${OBJECTS_BONUS} Makefile
			@echo "----Making Bonus----"
			@$(GCC) $(CFLAGS) $(OBJECTS_BONUS) -o $(NAME)

clean:
			@echo "----Cleaning----"
			@${RM} ${TEST_OBJECT}
			@cd $(LIB_DIR) && make clean

fclean:		clean
			@echo "----Fcleaning----"
			@${RM} ${NAME}
			@cd $(LIB_DIR) && make fclean


re:			fclean all