.PHONY:     		all $(NAME) sanit lib bonus clean fclean re

LIB_NAME			= libftprintf.a
NAME				= test

#Libft
LIBFT				= libft.a

#Directory
DIR_BONUS			= bonus/
LIB_DIR				= libft/

#Sans bonus
SOURCE		 		= ft_printf.c print_c.c print_s.c print_p.c print_d.c print_i.c print_u.c print_x.c print_xx.c convert_base.c
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
LIB 				= ar -crs
EXTRACT_LIB			= ar -x

all: $(NAME) Makefile

#Rule for Object
%.o:				%.c
					$(GCC) $(CFLAGS) -I$(HEADER) -I$(LIB_DIR) -c $< -o $@

%.o:				$(DIR_BONUS)/%.c
					$(GCC) $(CFLAGS) -I$(HEADER_BONUS) -I$(HEADER) -I$(LIB_DIR) -c $< -o $@

#Rule for compile
$(NAME):	lib $(OBJECTS) $(OBJECTS_BONUS) ${OBJECT_LIB} Makefile 
			@echo "----Making liftprintf.a----"
			@${EXTRACT_LIB} $(LIB_DIR)$(LIBFT)  
			@${LIB} ${LIB_NAME} ${OBJECTS} ${OBJECTS_BONUS} ${OBJECT_LIB}

sanit: 		lib $(TEST_OBJECT) $(HEADER) Makefile
			@echo "----Ready for sanitizing ? ----"
			$(GCC) $(SANITIZE) $(TEST_OBJECT) -o $(NAME) $(LIB_DIR)$(LIBFT)  
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
			@${RM} ${LIB_NAME}
			@${RM} ${NAME}
			@cd $(LIB_DIR) && make fclean


re:			fclean all