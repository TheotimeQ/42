# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelinsta <zelinsta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 10:22:54 by tquere            #+#    #+#              #
#    Updated: 2022/11/09 17:09:58 by zelinsta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ATTENTION POUR LE RENDU , DISPOSITION DES FICHIER / MAKEFILE

.PHONY:     		all sanit make_lib bonus clean fclean re

NAME_LIB			= libft.a
NAME				= LIB_TEST

SOURCEDIR_1 		= .
SOURCEDIR_2 		= .
SOURCEDIR_BONUS		= _Bonus
BUILDDIR  			= Build
HEADERDIR 			= Header

HEADER_FILE			= $(shell find $(HEADERDIR) -name '*.h')
			
SOURCE_1			= $(shell find $(SOURCEDIR_1) -name '*.c')
SOURCE_2			= $(shell find $(SOURCEDIR_2) -name '*.c')
SOURCE_BONUS		= $(shell find $(SOURCEDIR_BONUS) -name '*.c')
SOURCE_MAIN 		= main.c $(SOURCE_1) $(SOURCE_2) $(SOURCE_BONUS)
SOURCE_MAIN_BONUS	= main.c $(SOURCE_1) $(SOURCE_2) $(SOURCE_BONUS)   

OBJECTS_MAIN	    = $(addprefix $(BUILDDIR)/,$(SOURCE_MAIN:%.c=%.o))
OBJECTS_MAIN_BONUS  = $(addprefix $(BUILDDIR)/,$(SOURCE_MAIN_BONUS:%.c=%.o))

GCC					= gcc
CFLAGS				= #-Wall -Wextra -Werror 
SANITIZE			= $(CFLAGS) -g -fsanitize=address

RM 					= rm -rf
LIB 				= ar -crs

all: $(NAME) Makefile

$(BUILDDIR)/%.o: %.c
			$(GCC) $(CFLAGS) -I$(HEADERDIR) -I$(dir $<) -c $< -o $@

$(NAME): 	$(OBJECTS_MAIN) $(HEADER_FILE) Makefile
			@$(GCC) $(CFLAGS) $(OBJECTS_MAIN) -o $(NAME)

sanit: 		$(OBJECTS_MAIN) $(HEADER_FILE) Makefile
			@$(GCC) $(SANITIZE) $(OBJECTS_MAIN) -o $(NAME)

make_lib:	${OBJECTS_MAIN} Makefile
			${LIB} ${NAME_LIB} ${OBJECTS_MAIN}

bonus:		${OBJECTS_MAIN} Makefile
			${LIB} ${NAME} ${OBJECTS_MAIN_BONUS}

clean:
			${RM} ${OBJECTS_MAIN}

fclean:		clean
			${RM} ${NAME}

re:			fclean all