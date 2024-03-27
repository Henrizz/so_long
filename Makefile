# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 15:24:33 by hzimmerm          #+#    #+#              #
#    Updated: 2024/03/27 18:06:31 by hzimmerm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -g -Wall -Wextra -Werror -I/images
LDFLAGS = -fsanitize=address
SRCS = srcs/draw.c srcs/keys.c srcs/main.c srcs/map.c
FTPRINTF = ft_printf/printoutfunctions.c ft_printf/ptr_conv.c ft_printf/hex_conv.c ft_printf/ft_printf.c
GETNEXTLINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf
CC = cc
LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF) $(LDFLAGS) $(GETNEXTLINE) $(LIBS) -o $(NAME)
	
%.o : %.c
	cc $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $^ -o $@

valgrind: $(NAME)
	valgrind --leak-check=full ./$(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all valgrind clean fclean re
