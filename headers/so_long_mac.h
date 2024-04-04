/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:09:44 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/04/01 20:24:40 by Henriette        ###   ########.fr       */
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

# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125

typedef struct s_game {
	void *mlx;
   	void *win;
	int	coins_path;
	int	coins_map;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int	height;
	int	width;
	char **field;
	int	row;
	int	col;
}				t_game;

typedef struct s_graphics {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	int	height;
	int	width;
}			t_graphics;


void	edited_mlx_pixel_put(t_game *data, int x, int y, int color);
void	draw_circle(t_game *data, int center_x, int center_y, int radius, int color);
void	draw_rainbow(t_game *data);
int close_window(t_game *data);
int key_hook(int keycode, t_game *data, t_graphics *graphics);
int close_button(t_game *data, t_graphics *graphics);
void free_images(t_game *game, t_graphics *graphics);
void	get_map(char *map, t_game *game);
int	check_map(t_game *game, char* map);
int	check_name(char *name);
int	check_components(t_game *game);
int	check_rectangle(t_game *game);
int	check_surrounding(t_game *game);
int	flood_fill(t_game *game);
int	fill_rec(t_game *game, int cols, int rows, char **checker);
void	find_p(t_game *game, int *start_x, int *start_y);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	initialize_checker(char ***checker, t_game *game);
void	free_field(t_game *game);
int	invalid_comp(t_game *game, int *rows, int *cols, int *p, int *e);
void	make_window(t_game *game);
int	transfer_graphics(t_game *game, t_graphics *graphics);
void	display_graphics(t_game *game, t_graphics *graphics);

# endif