/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game->graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:14:45 by Henriette         #+#    #+#             */
/*   Updated: 2024/04/01 18:25:14 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/ft_printf.h"
#include "../headers/get_next_line.h"

int	transfer_graphics(t_game *game)
{	
	ft_printf("Before transfer:\n");
	ft_printf("game pointer: %p\n", (void *)game);
    ft_printf("graphics collectible pointer: %p\n", (void *)game->graphics.collectible);
    ft_printf("graphics pointer: %p\n", game->graphics);
	game->graphics.width = 45;
	game->graphics.height = 45;
	game->graphics.collectible = mlx_xpm_file_to_image(game->mlx, "images/bottle_45.xpm", &(game->graphics.width), &(game->graphics.height));
	game->graphics.wall = mlx_xpm_file_to_image(game->mlx, "images/wall_45.xpm", &(game->graphics.width), &(game->graphics.height));
	game->graphics.floor = mlx_xpm_file_to_image(game->mlx, "images/floor_45.xpm", &(game->graphics.width), &(game->graphics.height));
	game->graphics.player = mlx_xpm_file_to_image(game->mlx, "images/player_45.xpm", &(game->graphics.width), &(game->graphics.height));
	game->graphics.exit = mlx_xpm_file_to_image(game->mlx, "images/home_45.xpm", &(game->graphics.width), &(game->graphics.height));
	if (game->graphics.exit == NULL || game->graphics.collectible == NULL || game->graphics.wall == NULL || game->graphics.player == NULL)
	{
		free_images(game);
		ft_printf("are null condition:\n");
    ft_printf("graphics collectible pointer: %p\n", (void *)game->graphics.collectible);
		return (1);
	}
	ft_printf("after transfer:\n");
    ft_printf("graphics collectible pointer: %p\n", (void *)game->graphics.collectible);
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
			if (game->field[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->graphics.floor, j * 45, i * 45);
			if (game->field[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->graphics.wall, j * 45, i * 45);	
			if (game->field[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->graphics.player, j * 45, i * 45);
			if (game->field[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->graphics.collectible, j * 45, i * 45);
			if (game->field[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->graphics.exit, j * 45, i * 45);
			j++;
		}
		i++;
	}
}
