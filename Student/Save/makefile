.PHONY:     			all $(NAME) inst sanit leaks leakss clear mkbuild lib clear clean fclean re

NAME					= exec

BUILD_DIR				= build/
	
HEADER_DIR				= inc/
HEADER_FILE				= exec.h

DIR						= src/
SRC			 			= exec_main.c exec_pipe.c exec_env.c exec_cmd.c exec.c
OBJECTS_SRC			    = $(SRC:%.c=$(BUILD_DIR)%.o)

DIR_BUILT_INT			= built_in/
BUILT_IN			 	= cd.c echo.c env.c exit.c export.c pwd.c unset.c
OBJECTS_BUILT	    	= $(BUILT_IN:%.c=$(BUILD_DIR)%.o)

DIR_ENV					= env/
ENV		 				= env_add.c env_del.c env_exist.c env_get.c env_init.c env_to_str.c env_utils.c inc_shlvl.c env_sort.c env_cpy.c
OBJECTS_ENV	    		= $(ENV:%.c=$(BUILD_DIR)%.o)

OBJECTS					= $(OBJECTS_SRC) $(OBJECTS_BUILT) $(OBJECTS_ENV) 
	
LIBFT					= libft.a
LIB_DIR					= libft/

GCC						= gcc
CFLAGS					= -Wall -Wextra -Werror
SANITIZE				= $(CFLAGS) -g3 -fsanitize=address

RM 						= rm -rf
CLEAR					= clear

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR)/$(HEADER_FILE)
						@echo -n .
						@$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -c $< -o $@

$(BUILD_DIR)%.o:		$(DIR_BUILT_INT)%.c $(HEADER_DIR)/$(HEADER_FILE)
						@echo -n .
						@$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -c $< -o $@

$(BUILD_DIR)%.o:		$(DIR_ENV)%.c $(HEADER_DIR)/$(HEADER_FILE)
						@echo -n .
						@$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -c $< -o $@

all: 					clear mkbuild lib $(HEADER_DIR) $(NAME) 
						
mkbuild:
						@mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						@$(GCC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT)
						@echo "\033[32m\n-- Done compiling exec $(NAME)--\033[0m"

inst: 					$(OBJECTS) $(LIB_DIR)$(LIBFT)
						@$(GCC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) -framework CoreFoundation
						@echo "\033[32m\n-- Done compiling exec for $(NAME)--\033[0m"

sanit:					$(CLEAR) $(OBJECTS) $(LIB_DIR)$(LIBFT)
						@$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT)
						@echo "\033[32m\n-- Done compiling sanit ./$(NAME)--\033[0m"

leaks:					$(CLEAR)
						make re
						@sleep 0.5
						@echo "\n    ------------------------------------------------------------------   "
						@echo "\033[32m\n-- Starting ./$(NAME)--\n\n\n\033[0m"
						leaks --atExit -- ./$(NAME)

leakss:					$(CLEAR)
						make re
						@sleep 0.5
						@echo "\n    ------------------------------------------------------------------   "
						@echo "\033[32m\n-- Starting ./$(NAME)--\n\n\n\033[0m"
						while (true); do leaks ./$(NAME); sleep 2; clear; done
						
lib:
						@make -C $(LIB_DIR)
						
clean:					
						@${RM} $(OBJECTS)
						@make clean -C $(LIB_DIR)
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR)

re:						fclean all