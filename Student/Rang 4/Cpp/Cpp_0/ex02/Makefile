.PHONY:		fclean, all, re

NAME		=	phonebook

CMP			=	c++
INC			=
FLG			=	-Wall -Wextra -Werror 
RM			=	rm -rf

SRCS_DIR	=	srcs/
SRCS_FILE	=	main phonebook
SRCS		=  $(addsuffix .cpp, $(addprefix $(SRCS_DIR)/, $(SRCS_FILE)))

all:		$(NAME)

$(NAME):	$(INC)
			$(CMP) $(FLGS) $(SRCS) -o $(NAME)

fclean:
			$(RM) $(NAME)

re:			fclean all
