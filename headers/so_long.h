/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:09:44 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/03/27 17:44:24 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 500

# define RIGHT 0
# define LEFT 1
# define UP 2
# define DOWN 3

typedef struct s_game {
	void *mlx;
   	void *win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int	height;
	int	width;
}				t_game;


void	edited_mlx_pixel_put(t_game *data, int x, int y, int color);
void	draw_circle(t_game *data, int center_x, int center_y, int radius, int color);
void	draw_rainbow(t_game *data);
int close_window(t_game *data);
int key_hook(int keycode, t_game *data);
int close_button(t_game *data);
int	read_map(char *map, t_game *game);


# endif
