.PHONY:     		all $(NAME) bonus test lib clean fclean re

LIB_NAME			= libftprintf.a
NAME				= libftprintf.a
HEADER				= ft_printf.h

LIBFT				= libft.a
LIB_DIR				= libft/

SOURCE		 		= add_zeros.c print_pourc.c ft_print_str.c ft_printf.c print_c.c print_s.c print_p.c print_d.c print_i.c print_u.c print_x.c print_xx.c convert.c
OBJECTS			    = $(SOURCE:%.c=%.o)

BONUS	 			= add_zeros.c print_pourc.c check_flag_bonus.c ft_print_str_bonus.c ft_printf.c print_c.c print_s.c print_p.c print_d.c print_i.c print_u.c print_x.c print_xx.c convert.c
OBJECTS_BONUS		= $(BONUS:%.c=%.o)

GCC					= gcc
CFLAGS				= -Wall -Wextra 
SANITIZE			= $(CFLAGS) -g -fsanitize=address

RM 					= rm -rf
LIB 				= ar -crs

all: 		$(NAME) Makefile

%.o:		%.c
			$(GCC) $(CFLAGS) -include$(HEADER) -I$(LIB_DIR) -c $< -o $@

$(NAME):	lib $(OBJECTS_BONUS) $(LIB_DIR)$(LIBFT) Makefile 
			@cp $(LIB_DIR)$(LIBFT) $(LIB_NAME) 
			@${LIB} ${LIB_NAME} ${OBJECTS_BONUS}

bonus:		lib ${OBJECTS_BONUS} $(LIB_DIR)$(LIBFT) Makefile
			@cp $(LIB_DIR)$(LIBFT) $(LIB_NAME) 
			@${LIB} ${LIB_NAME} ${OBJECTS_BONUS}

test: 		lib $(OBJECTS_BONUS) Makefile
			@$(GCC) $(SANITIZE) $(OBJECTS_BONUS) -o test $(LIB_DIR)$(LIBFT)  

lib:		Makefile
			@cd $(LIB_DIR) && make

clean:
			@${RM} ${TEST_OBJECT} $(OBJECTS_BONUS) $(OBJECTS) $(OBJ_LIB)
			@cd $(LIB_DIR) && make clean

fclean:		clean
			@${RM} ${LIB_NAME}
			@${RM} ${NAME}
			@cd $(LIB_DIR) && make fclean

re:			fclean all