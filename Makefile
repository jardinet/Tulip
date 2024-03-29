# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 19:40:12 by mwragg            #+#    #+#              #
#    Updated: 2019/07/12 03:15:36 by mwragg           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRC=	./fdf.c \
		./parsing.c \
		./management_mlx.c  \
		./bresenham.c \
		./bonus.c

OBJ= $(SRC:.c=.o)

INCLUDES= -I fdf.h

FLAGS= -Wall -Wextra -Werror

LIBMLXINC= -L ./minilibx -lmlx -framework OpenGL -framework AppKit
LIBFTINC = -L ./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C Libft
	@make -C minilibx
	@echo "Here you go :^)"
	@gcc $(FLAGS) $(LIBFTINC) $(OBJ) -o $(NAME) $(LIBMLXINC)
%.o: %.c
	@gcc -o $@ -c $< $(FLAGS) $(INCLUDES)

clean:
	@make -C Libft clean
	@make -C minilibx clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C Libft fclean
	@rm -rf $(NAME)

re: fclean all
