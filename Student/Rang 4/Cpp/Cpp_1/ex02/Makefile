# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tquere <tquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 16:24:04 by zelinsta          #+#    #+#              #
#    Updated: 2023/02/13 11:22:47 by tquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		fclean, all, clear, re

NAME		=	Ex02

CMP			=	c++
INC_DIR		=	incs
FLG			=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

SRCS_DIR	=	srcs
SRCS_FILE	=	main
SRCS		=  $(addsuffix .cpp, $(addprefix $(SRCS_DIR)/, $(SRCS_FILE)))

INC_FILE	= 
INC			= $(addsuffix .hpp, $(addprefix $(INC_DIR)/, $(INC_FILE)))


all:		clear $(NAME) $(SRCS)

clear:
			clear

$(NAME):	$(INC) $(SRCS)
			$(CMP) $(FLGS) $(SRCS) -I$(INC_DIR) -o $(NAME)

fclean:
			$(RM) $(NAME)

re:			fclean all
