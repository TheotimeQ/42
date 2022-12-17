# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 14:22:29 by tquere            #+#    #+#              #
#    Updated: 2022/12/15 12:25:51 by zelinsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     			all $(NAME) clear mkbuild clear clean fclean re

NAME					= philo 

BUILD_DIR				= build/
	
HEADER_DIR				= src/
HEADER_FILE				= philo.h

DIR						= src/
SRC			 			= main.c main_args.c annexe.c create_philo.c
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)
	
GCC						= gcc
CFLAGS					= -Wall -Wextra -Werror
SANITIZE				= $(CFLAGS) -g3 -fsanitize=address

RM 						= rm -rf
CLEAR					= clear

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR)/$(HEADER_FILE)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

all: 					clear mkbuild $(HEADER_DIR) $(NAME) 
						
mkbuild:
						@mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS)
						$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME)
						
clean:					
						@${RM} $(OBJECTS)
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}

re:						fclean all