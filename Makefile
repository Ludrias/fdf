# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdoose <qdoose@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/05 05:36:06 by qdoose            #+#    #+#              #
#    Updated: 2015/05/05 05:36:50 by qdoose           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GC = gcc
CFL = -Wall -Werror -Wextra
NAME = fdf
SRC =	main.c\
		getnextline/get_next_line.c

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	make -C libft
	$(GC) -o $(NAME) $(OBJ) -L./libft -lft $(CFL) -framework OpenGL -framework AppKit -lmlx
	rm -f $(OBJ)

%.o: %.c
	$(GC) $(CFL) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
