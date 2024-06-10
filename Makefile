# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 15:24:33 by hzimmerm          #+#    #+#              #
#    Updated: 2024/06/10 16:20:09 by hzimmerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -g -Wall -Wextra -Werror -I/images -Isrcs/libft
LDFLAGS = -fsanitize=address
SRCS = srcs/keys.c srcs/main.c srcs/map.c srcs/flood_fill.c srcs/graphics.c srcs/free_close.c srcs/map2.c
LIBFT = srcs/libft/libft.a
LIB = srcs/libft
OBJS = $(SRCS:.c=.o)
RM = rm -rf
CC = cc
LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 

all: $(NAME)

$(NAME): $(OBJS)
	@if [ ! -d "mlx_linux" ]; then \
		echo "Cloning miniLibX..."; \
		git clone https://github.com/42Paris/minilibx-linux.git mlx_linux; \
	fi
	@make -C mlx_linux/
	@if [ ! -f "$(LIBFT)" ]; then \
		make -C $(LIB); \
	fi
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LIBFT) $(LIBS) -o $(NAME)
	
%.o : %.c
	cc $(CFLAGS) $(LDFLAGS) -I/usr/include -Imlx_linux -O3 -c $^ -o $@

valgrind: $(NAME)
	valgrind --leak-check=full ./$(NAME)

clean:
	$(RM) srcs/*.o $(LIB)/*.o

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all valgrind clean fclean re
