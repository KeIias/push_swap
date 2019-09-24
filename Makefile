# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algautie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 15:08:42 by algautie          #+#    #+#              #
#    Updated: 2019/09/24 11:24:57 by algautie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CH			=	checker
PS			= 	push_swap

CC 			= 	gcc
CFLAGS 		= 	-Wall -Wextra -Werror

SRC_NAME_CH	=	checks.c \
				instructions.c \
				checker.c \

SRC_NAME_PS	=	checks.c \
				instructions.c \
				normalize.c \
				push_swap.c \
				pseudo_quick_sort.c \

SRC_PATH_CH	=	./srcs/checker/
SRC_PATH_PS	=	./srcs/push_swap/

OBJ_PATH_CH	=	./objs/checker/
OBJ_PATH_PS	=	./objs/push_swap/

INC_PATH	=	./includes/
INC_NAME	=	push_swap.h

LIBFT_PATH	=	./libft/
LIBFT_NAME	=	libft.a
LIB 		= 	./libft/libft.a

INC			=	$(addprefix $(INC_PATH), $(INC_NAME))
SRC_CH		=	$(addprefix $(SRC_PATH_CH), $(SRC_NAME_CH))
SRC_PS		=	$(addprefix $(SRC_PATH_PS), $(SRC_NAME_PS))
OBJ_CH		=	$(patsubst $(SRC_PATH_CH)%.c, $(OBJ_PATH_CH)%.o, $(SRC_CH))
OBJ_PS		=	$(patsubst $(SRC_PATH_PS)%.c, $(OBJ_PATH_PS)%.o, $(SRC_PS))

all: $(CH) $(PS)

$(LIB):
	@make -sC $(LIBFT_PATH) -j

librm:
	@make -sC $(LIBFT_PATH) fclean

$(CH): $(LIB) $(OBJ_CH)
	@$(CC) $(OBJ_CH) $(LIB) -o $(CH)

$(PS): $(LIB) $(OBJ_PS)
	@$(CC) $(OBJ_PS) $(LIB) -o $(PS)

$(OBJ_PATH_CH)%.o: $(SRC_PATH_CH)%.c $(INC)
	@mkdir -p $(OBJ_PATH_CH)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH_PS)%.o: $(SRC_PATH_PS)%.c $(INC)
	@mkdir -p $(OBJ_PATH_PS)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf ./objs/

fclean: clean
	@rm -f $(CH) $(PS)

re: fclean all

.PHONY: all librm clean fclean re
