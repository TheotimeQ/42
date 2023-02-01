# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 16:24:04 by zelinsta          #+#    #+#              #
#    Updated: 2023/02/01 16:24:05 by zelinsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		fclean, all, clear, re

NAME		=	phonebook

CMP			=	c++
INC			=	incs
FLG			=	-Wall -Wextra -Werror 
RM			=	rm -rf

SRCS_DIR	=	srcs
SRCS_FILE	=	main phonebook contact
SRCS		=  $(addsuffix .cpp, $(addprefix $(SRCS_DIR)/, $(SRCS_FILE)))

all:		clear $(NAME)

clear:
			clear

$(NAME):	$(INC)
			$(CMP) $(FLGS) $(SRCS) -I$(SRCS_DIR) -o $(NAME)

fclean:
			$(RM) $(NAME)

re:			fclean all
