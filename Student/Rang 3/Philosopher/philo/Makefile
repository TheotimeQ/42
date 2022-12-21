# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tquere <tquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 14:22:29 by tquere            #+#    #+#              #
#    Updated: 2022/12/21 15:03:25 by tquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     			all $(NAME) clear mkbuild clear clean fclean re

#

NAME					= philo 

BUILD_DIR				= build/
	
HEADER_DIR				= src/
HEADER_FILE				= philo.h

DIR						= src/
SRC			 			= 	annexe.c \
							main.c main_env.c\
							philo_init.c philo_thread.c philo_utils.c \
							
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)
	
GCC						= gcc
CFLAGS					= -Wall -Wextra -Werror 
SANITIZE				= #$(CFLAGS) -g3 -fsanitize=address 

RM 						= rm -rf
CLEAR					= clear

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR)/$(HEADER_FILE)
						@echo -n .
						@$(GCC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

all: 					clear mkbuild $(HEADER_DIR) $(NAME) 
						
mkbuild:
						@mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS)
						@echo "\n-- Done compiling ./$(NAME)--"
						@$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) -lpthread 
						
clean:					
						@${RM} $(OBJECTS)
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}

re:						fclean all