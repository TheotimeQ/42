.PHONY:     		all $(NAME) sanit lib bonus clean fclean re

LIB_NAME			= libftprintf.a
NAME				= test
HEADER				= ft_printf.h

#Libft
LIBFT				= libft.a
LIB_DIR				= libft/
SRC_LIB		 		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ_LIB			    = $(SRC_LIB:%.c=$(LIB_DIR)/%.o)

#Sans bonus
SOURCE		 		= 
OBJECTS			    = $(SOURCE:%.c=%.o)

#Avec bonus
BONUS	 			= 
OBJECTS_BONUS		= $(BONUS:%.c=%.o)

#Pour les test
TEST_SRC			= main.c 
TEST_OBJECT			= $(TEST_SRC:%.c=%.o)

#Option compilation
GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror 
SANITIZE			= $(CFLAGS) -g -fsanitize=address

#Autres commande
RM 					= rm -rf
CLEAR				= clear

all: $(NAME) Makefile

#Rule for Object
%.o:		%.c
			$(GCC) $(CFLAGS) -include$(HEADER) -I$(LIB_DIR) -c $< -o $@

sanit: 		lib $(TEST_OBJECT) $(OBJECTS) $(HEADER) Makefile
			@echo "----Ready for sanitizing ? ----"
			@$(GCC) $(SANITIZE) $(TEST_OBJECT) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT)  
			@echo 'run ./$(NAME) to test'

sanit_bonus: 	lib $(TEST_OBJECT) $(OBJECTS_BONUS) $(HEADER) Makefile
				@echo "----Ready for sanitizing ? ----"
				@$(GCC) $(SANITIZE) $(TEST_OBJECT) $(OBJECTS_BONUS) -o $(NAME) $(LIB_DIR)$(LIBFT)  
				@echo 'run ./$(NAME) to test'

clean:
			@echo "----Cleaning----"
			@${RM} ${TEST_OBJECT} $(OBJECTS_BONUS) $(OBJECTS) $(OBJ_LIB)
			@cd $(LIB_DIR) && make clean

fclean:		clean
			@echo "----Fcleaning----"
			@${RM} ${LIB_NAME}
			@${RM} ${NAME}
			@cd $(LIB_DIR) && make fclean


re:			fclean all