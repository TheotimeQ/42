# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 16:24:04 by zelinsta          #+#    #+#              #
#    Updated: 2023/02/06 08:59:10 by zelinsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		fclean, all, clear, re

NAME		=	Ex01

CMP			=	c++
INC_DIR		=	incs
FLG			=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

SRCS_DIR	=	srcs
SRCS_FILE	=	main Zombie zombieHorde
SRCS		=  $(addsuffix .cpp, $(addprefix $(SRCS_DIR)/, $(SRCS_FILE)))

INC_FILE	= Zombie
INC			= $(addsuffix .hpp, $(addprefix $(INC_DIR)/, $(INC_FILE)))


all:		clear $(NAME)

clear:
			clear

$(NAME):	$(INC)
			$(CMP) $(FLGS) $(SRCS) -I$(INC_DIR) -o $(NAME)

fclean:
			$(RM) $(NAME)

re:			fclean all
