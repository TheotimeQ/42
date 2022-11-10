.PHONY:     		all $(NAME) sanit lib bonus clean fclean re

NAME_LIB			= libftprintf.a
NAME				= test

#Directory
BUILD_DIR  			= build
DIR_BONUS			= bonus/
LIB_DIR				=

#Sans bonus
SOURCE		 		= main.c
OBJECTS			    = $(SOURCE:%.c=$(BUILD_DIR)/%.o)
HEADER				= .

#Avec bonus
BONUS	 			= 
OBJECTS_BONUS		= $(BONUS:%.c=$(BUILD_DIR)/%.o)
HEADER_BONUS		= $(DIR_BONUS)

#Pour les test
TEST_SRC			= main.c 
TEST_OBJECT			= $(TEST_SRC:%.c=$(BUILD_DIR)/%.o) $(OBJECTS) $(OBJECTS_BONUS) #$(BUILD_DIR)/main.o

#Option compilation
GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror 
SANITIZE			= $(CFLAGS) -g -fsanitize=address

#Pour faire la lib
SOURCE_LIB		 	= 
OBJECTS_LIB		    = $(SOURCE_LIB:%.c=$(LIB_DIR)/%.o)
HEADER_LIB			= $(LIB_DIR)
LIB 				= ar -crs

#Autres commande
RM 					= rm -rf
CLEAR				= clear


all: $(NAME) Makefile

#Rule for Object
%.o:				%.c
					$(GCC) $(CFLAGS) -I$(HEADER_BONUS) -I$(HEADER) -c $< -o $@

$(BUILD_DIR)/%.o:	%.c
					$(GCC) $(CFLAGS) -I$(HEADER) -c $< -o $@

$(BUILD_DIR)/%.o:	$(DIR_BONUS)/%.c
					$(GCC) $(CFLAGS) -I$(HEADER_BONUS) -I$(HEADER) -c $< -o $@


#Rule for compile
$(NAME):	$(TEST_OBJECT) $(HEADER) Makefile 
			@echo "----Compiling----"
			@$(GCC) $(CFLAGS) $(TEST_OBJECT) -o $(NAME)

sanit: 		$(OBJECTS) $(HEADER) Makefile
			@echo "----Ready for sanitizing ? ----"
			$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME)

#Rule to make lib
lib:		${OBJECTS} Makefile
			@echo "----Making Lib----"
			@${LIB} ${NAME_LIB} ${OBJECTS}

bonus:		${OBJECTS_BONUS} Makefile
			@echo "----Making Bonus----"
			@$(GCC) $(CFLAGS) $(OBJECTS_BONUS) -o $(NAME)

clean:
			${RM} ${TEST_OBJECT}

fclean:		clean
			${RM} ${NAME}

re:			fclean all