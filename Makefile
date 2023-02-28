# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 12:42:54 by moudrib           #+#    #+#              #
#    Updated: 2023/02/28 19:56:52 by moudrib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
CC = cc
R = \x1B[31m
G = \x1B[32m
W = \x1B[0m
B = \033[1m
CFLAGS =  -Wall -Wextra -Werror
OBJDIR = Obj/
SRC = 	ft_split.c \
		utils.c utils2.c utils3.c \
		push_swap.c list_utils.c parsing.c \
		sorting5.c sorting100.c sorting500.c \
		swap.c push.c rotate.c reverse_rotate.c

BONUS_SRC = ft_split.c \
			checker.c \
			get_next_line.c \
			list_utils.c parsing.c \
			utils.c utils2.c utils3.c \
			sorting5.c sorting100.c sorting500.c \
			swap.c push.c rotate.c reverse_rotate.c 

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJDIR),$(BONUS_SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o  $(NAME)
	@clear
	@echo
	@echo "$(G)Push_swap compilation done ✔️"
	@echo
	@echo "          $(R)██████$(W)╗ $(R)██$(W)╗   $(R)██$(W)╗$(R)███████$(W)╗$(R)██$(W)╗  $(R)██$(W)╗    $(R)███████$(W)╗ $(R)█████$(W)╗ $(R)██$(W)╗    $(R)██$(W)╗$(R)██████$(W)╗"
	@echo "          $(R)██$(W)╔══$(R)██$(W)╗$(R)██$(W)║   $(R)██$(W)║$(R)██$(W)╔════╝$(R)██$(W)║  $(R)██$(W)║    $(R)██$(W)╔════╝$(R)██$(W)╔══$(R)██$(W)╗$(R)██$(W)║    $(R)██$(W)║$(R)██$(W)╔══$(R)██$(W)╗"
	@echo "          $(R)██████$(W)╔╝$(R)██$(W)║   $(R)██$(W)║$(R)███████$(W)╗$(R)███████$(W)║    $(R)███████$(W)╗$(R)███████$(W)║$(R)██$(W)║ $(R)█$(W)╗ $(R)██$(W)║$(R)██████$(W)╔╝"
	@echo "          $(R)██╔═══╝ $(R)██║   $(R)██║╚════$(R)██║██╔══██║    ╚════██║██╔══██║██║███╗██║██╔═══╝"
	@echo "          $(R)██║     ╚$(R)██████╔╝$(R)███████║$(R)██║  ██║    ███████║██║  ██║╚███╔███╔╝██║"
	@echo "          ╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝╚═╝  ╚═╝ ╚══╝╚══╝ ╚═╝$(W)"
	@echo "                                                                           $(B)$(R)By $(W)$(B)moudrib"
	@echo
	@echo

$(OBJDIR)%.o: %.c push_swap.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(G)Compiling: $(W)$<"

bonus: $(CHECKER)

$(CHECKER): $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_SRC) -o $(CHECKER)
	@clear
	@echo
	@echo "$(G)DONE ✔️"

clean: 
	@rm -rf $(OBJ) $(BONUS_OBJ) $(OBJDIR)

fclean: clean
	@rm -f $(NAME) $(CHECKER) 

re: fclean all 

.PHONY: all clean fclean re bonus