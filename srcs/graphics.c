/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:14:45 by Henriette         #+#    #+#             */
/*   Updated: 2024/06/10 15:48:46 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	transfer_graphics(t_game *game)
{
	game->graphics.collectible = mlx_xpm_file_to_image(game->mlx, \
	"images/bottle_45.xpm", &(game->graphics.width), &(game->graphics.height));
	game->graphics.wall = mlx_xpm_file_to_image(game->mlx, \
	"images/wall_45.xpm", &(game->graphics.width), &(game->graphics.height));
	game->graphics.floor = mlx_xpm_file_to_image(game->mlx, \
	"images/floor_45.xpm", &(game->graphics.width), &(game->graphics.height));
	game->graphics.player = mlx_xpm_file_to_image(game->mlx, \
	"images/player_45.xpm", &(game->graphics.width), &(game->graphics.height));
	game->graphics.exit = mlx_xpm_file_to_image(game->mlx, \
	"images/home_45.xpm", &(game->graphics.width), &(game->graphics.height));
	game->graphics.player_on_house = mlx_xpm_file_to_image(game->mlx, \
	"images/player_on_house.xpm", &(game->graphics.width), \
	&(game->graphics.height));
	game->graphics.exit_closed = mlx_xpm_file_to_image(game->mlx, \
	"images/home_cl.xpm", &(game->graphics.width), &(game->graphics.height));
	if (game->graphics.exit == NULL || game->graphics.collectible == NULL 
		|| game->graphics.wall == NULL || game->graphics.player == NULL 
		|| game->graphics.player_on_house == NULL 
		|| game->graphics.exit_closed == NULL)
	{
		free_images(game);
		return (1);
	}
	return (0);
}

void	display_graphics(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			put_graphics(game, &i, &j);
			j++;
		}
		i++;
	}
}

void	put_graphics(t_game *game, int *i, int *j)
{
	if (game->field[*i][*j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->graphics.floor, *j * 45, *i * 45);
	if (game->field[*i][*j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->graphics.wall, *j * 45, *i * 45);
	if (game->field[*i][*j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->graphics.player, *j * 45, *i * 45);
	if (game->field[*i][*j] == 'C')
		mlx_put_image_to_window(game->mlx, \
		game->win, game->graphics.collectible, *j * 45, *i * 45);
	if (game->field[*i][*j] == 'E')
	{
		if (game->coins_found == game->coins_map)
			mlx_put_image_to_window(game->mlx, game->win, \
		game->graphics.exit, *j * 45, *i * 45);
		else
			mlx_put_image_to_window(game->mlx, game->win, \
		game->graphics.exit_closed, *j * 45, *i * 45);
	}
	if (game->field[*i][*j] == 'H')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->graphics.player_on_house, *j * 45, *i * 45);
}
