/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:09:44 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/06/10 16:49:52 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include "../srcs/libft/libft.h"

/* mac
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define ESC 53
*/

# define RIGHT 65363
# define LEFT 65361
# define UP 65362
# define DOWN 65364
# define ESC 65307

typedef struct s_graphics {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*exit_closed;
	void	*player_on_house;
	int		height;
	int		width;
}			t_graphics;

typedef struct s_game {
	void		*mlx;
	void		*win;
	int			coins_path;
	int			coins_map;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
	char		**field;
	int			coins_found;
	int			moves_count;
	int			p;
	int			e;
	t_graphics	graphics;
}				t_game;

int		close_window(t_game *data);
int		key_hook(int keycode, t_game *data);
int		close_button(t_game *data);
void	free_images(t_game *game);
void	get_map(char *map, t_game *game);
int		check_map(t_game *game, char *map);
int		check_name(char *name);
int		check_components(t_game *game);
int		check_rectangle(t_game *game);
int		check_surrounding(t_game *game);
int		flood_fill(t_game *game);
int		fill_rec(t_game *game, int cols, int rows, char **checker);
void	find_p(t_game *game, int *start_x, int *start_y);
//void	*ft_memcpy(void *dst, const void *src, size_t n);
void	initialize_checker(char ***checker, t_game *game);
void	free_field(t_game *game);
int		invalid_comp(t_game *game, int *rows, int *cols);
void	make_window(t_game *game);
int		transfer_graphics(t_game *game);
void	display_graphics(t_game *game);
int		update_player_position(int keycode, t_game *game);	
int		move_up(t_game *game, int *row, int *col);
int		move_down(t_game *game, int *row, int *col);
int		move_left(t_game *game, int *row, int *col);
int		move_right(t_game *game, int *row, int *col);
void	free_checker(t_game *game, char **checker);
void	put_graphics(t_game *game, int *i, int *j);

#endif
