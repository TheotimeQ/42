.PHONY:		fclean, all, clear, re

NAME					=	Ex02

CMP						=	c++
FLG						=	-Wall -Wextra -Werror -std=c++98
RM						=	rm -rf
BUILD_DIR				= 	build/

INC_DIR					=	incs
INC_FILE				= 	Animal Cat Dog Brain
INC						= 	$(addsuffix .hpp, $(addprefix $(INC_DIR)/, $(INC_FILE)))

SRCS_DIR				=	srcs
SRCS_FILE				=	main Animal Cat Dog Brain
SRCS					=  	$(addsuffix .cpp, $(addprefix $(SRCS_DIR)/, $(SRCS_FILE)))

OBJS			    	= 	$(SRCS:%.cpp=$(BUILD_DIR)%.o)

$(BUILD_DIR)%.o:		%.cpp $(INC)
						@echo -n .
						@mkdir -p $(@D)
						@$(CMP) $(FLG) -I$(INC_DIR) -c $< -o $@

all:		clear $(NAME)

clear:
			clear

$(NAME):	$(INC) $(OBJS)
			@$(CMP) $(FLG) $(OBJS) -I$(INC_DIR) -o $(NAME)
			@echo "\033[32m\n-- Done compiling $(NAME)--\033[0m"

fclean:
			$(RM) $(NAME)
			$(RM) $(BUILD_DIR)

re:			fclean all
