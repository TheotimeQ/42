# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 13:34:37 by zelinsta          #+#    #+#              #
#    Updated: 2023/02/01 13:34:38 by zelinsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		fclean, all, re

NAME		=	megaphone

CMP			=	c++
INC			=
FLG			=	-Wall -Wextra -Werror 
RM			=	rm -rf

SRCS		=	megaphone.cpp

all:		$(NAME)

$(NAME):	$(INC)
			$(CMP) $(FLGS) $(SRCS) -o $(NAME)

fclean:
			$(RM) $(NAME)

re:			fclean all
