# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algautie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 15:08:42 by algautie          #+#    #+#              #
#    Updated: 2019/09/23 14:28:22 by algautie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CH			=	checker
PS			= 	push_swap

CC 			= 	gcc
CFLAGS 		= 	-Wall -Wextra -Werror

SRC_NAME_PS	=	checks.c \
				instructions.c \
				normalize.c \
				push_swap.c \

SRC_NAME_CH	=	checks.c \
				instructions.c \
				checker.c \

SRC_PATH_PS	=	./sources/push_swap/
SRC_PATH_CH	=	./sources/checker/

OBJ_PATH_PS	=	./objs/push_swap/
OBJ_PATH_CH	=	./objs/checker/

INC_PATH	=	./includes/
INC_NAME	=	push_swap.h

LIBFT_PATH	=	./libft/
LIBFT_NAME	=	libft.a

INC			=	$(addprefix $(INC_PATH), $(INC_NAME))
SRC_PS		=	$(addprefix $(SRC_PATH_PS), $(SRC_NAME_PS))
SRC_CH		=	$(addprefix $(SRC_PATH_CH), $(SRC_NAME_CH))
OBJ_PS		=	$(patsubst $(SRC_PATH_PS)%.c, $(OBJ_PATH_PS)%.o, $(SRC_PS))
OBJ_CH		=	$(patsubst $(SRC_PATH_CH)%.c, $(OBJ_PATH_CH)%.o, $(SRC_CH))

all: ch ps

lib:
	@make -Cs $(LIBFT_PATH) -j

librm:
	@make -Cs $(LIBFT_PATH) fclean

ch: lib $(OBJ_CH)
	@$(CC) $(OBJ_CH) $(LIBFT_PATH) $(LIBFT_NAME) -o $(CH)

ps: lib $(OBJ_PS)
	@$(CC) $(OBJ_PS) $(LIBFT_PATH) $(LIBFT_NAME) -o $(PS)

$(CH): lib $(OBJ_CH)
	@$(CC) $(OBJ_CH) $(LIBFT_PATH) $(LIBFT_NAME) -o $(CH)

$(PS): lib $(OBJ_PS)
	@$(CC) $(OBJ_PS) $(LIBFT_PATH) $(LIBFT_NAME) -o $(PS)

$(PS_OBJ_PATH)%.o: $(SRC_PATH_PS)%.c $(INC)
	@mkdir -p $(OBJ_PATH_PS)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(CH_OBJ_PATH)%.o: $(SRC_PATH_CH)%.c $(INC)
	@mkdir -p $(OBJ_PATH_CH)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf ./objs/

fclean: clean
	@rm -f $(CH) $(PS)

re: fclean all

.PHONY: all clean fclean re
