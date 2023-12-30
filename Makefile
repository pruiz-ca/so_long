# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/01 14:07:20 by pruiz-ca          #+#    #+#              #
#    Updated: 2021/08/13 22:30:58 by pruiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash

NAME		=	so_long

S			=	src/
O			=	obj/
I			=	inc/

NOCOL		=	\033[0m
GRN			=	\033[0;32m
ORG			=	\033[0;33m
BLU			=	\033[0;34m
CYN			=	\033[0;36m
YEL			=	\033[1;33m
PUR			=	\033[1;32m

SRCS		=	$Scheck.c $Skeys.c $Smain.c $Sparser.c $Srender.c $Sutils.c
OBJS		=	$(SRCS:$S%.c=$O%.o)

HEADER		=	-include $Iso_long.h -include $Ikeycodes.h

LIBFT		=	-L lib/libft -lft
MLIBX		=	-L lib/minilibx -lmlx -framework OpenGL -framework AppKit

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo -e "$(ORG)Compiling libft..$(NOCOL)"
				@make -C lib/libft > /dev/null 2>&1
				@echo -e "$(ORG)Compiling minilibx..$(NOCOL)"
				@make -C lib/minilibx > /dev/null 2>&1
				@echo -e "$(ORG)Compiling so_long..$(NOCOL)"
				@$(CC) $(FLAGS) $(SRCS) $(HEADER) $(LIBFT) $(MLIBX) -o $(NAME)
				@echo -e "$(PUR)Finished!$(NOCOL)"

$O%.o: 			$S%.c
				@[ -d $(O) ] || mkdir -p $(O)
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@rm -rf $(O)
				@make clean -C lib/libft
				@make clean -C lib/minilibx

fclean:			clean
				@rm -f $(NAME)
				@rm -rf *.dSYM
				@rm -f lib/libft/libft.a
				@rm -f lib/minilibx/libmlx.a
				@find . -name ".DS_Store" -delete

re:				fclean all

bonus:			all

run:			clean
				@rm -f $(NAME)
				@$(CC) $(FLAGS) $(SRCS) $(HEADER) $(LIBFT) $(MLIBX) -o $(NAME)
				@make clean
				@./$(NAME) maps/00.ber

norm:
				@norminette src inc lib/libft

.PHONY:			all clean fclean re run norm
