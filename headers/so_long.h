/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:09:44 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/04/04 16:38:15 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <mlx.h>
#include <fcntl.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 500

# define RIGHT 0
# define LEFT 1
# define UP 2
# define DOWN 3

typedef struct s_graphics {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	int	height;
	int	width;
}			t_graphics;


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
	t_graphics	graphics;
}				t_game;



void	edited_mlx_pixel_put(t_game *data, int x, int y, int color);
void	draw_circle(t_game *data, int center_x, int center_y, int radius, int color);
void	draw_rainbow(t_game *data);
int close_window(t_game *data);
int key_hook(int keycode, t_game *data);
int close_button(t_game *data);
void free_images(t_game *game);
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
int	transfer_graphics(t_game *game);
void	display_graphics(t_game *game);

# endif
