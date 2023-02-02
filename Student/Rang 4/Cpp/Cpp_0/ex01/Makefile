# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 16:24:04 by zelinsta          #+#    #+#              #
#    Updated: 2023/02/02 08:18:43 by zelinsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		fclean, all, clear, re

NAME		=	phonebook

CMP			=	c++
INC			=	incs
FLG			=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

SRCS_DIR	=	srcs
SRCS_FILE	=	main Phonebook Contact
SRCS		=  $(addsuffix .cpp, $(addprefix $(SRCS_DIR)/, $(SRCS_FILE)))

all:		clear $(NAME)

clear:
			clear

$(NAME):	$(INC)
			$(CMP) $(FLGS) $(SRCS) -I$(SRCS_DIR) -o $(NAME)

fclean:
			$(RM) $(NAME)

re:			fclean all
