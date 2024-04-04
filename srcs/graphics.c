/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics->c                                         :+:      :+:    :+:   */
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

int	transfer_graphics(t_game *game, t_graphics *graphics)
{	
	graphics->width = 45;
	graphics->height = 45;
	graphics->collectible = mlx_xpm_file_to_image(game->mlx, "images/bottle_45.xpm", &(graphics->width), &(graphics->height));
	//if (graphics->collectible == NULL)
	//	return (1);
	graphics->wall = mlx_xpm_file_to_image(game->mlx, "images/wall_45.xpm", &(graphics->width), &(graphics->height));
	//if (graphics->wall == NULL)
	//	return (1);
	graphics->floor = mlx_xpm_file_to_image(game->mlx, "images/floor_45.xpm", &(graphics->width), &(graphics->height));
	//if (graphics->floor == NULL)
	//	return (1);
	graphics->player = mlx_xpm_file_to_image(game->mlx, "images/player_45.xpm", &(graphics->width), &(graphics->height));
	//if (graphics->player == NULL)
	//	return (1);
	graphics->exit = mlx_xpm_file_to_image(game->mlx, "images/home_45.xpm", &(graphics->width), &(graphics->height));
	//if (graphics->exit == NULL)
	//	return (1);
	return (0);
}

void	display_graphics(t_game *game, t_graphics *graphics)
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
				mlx_put_image_to_window(game->mlx, game->win, graphics->floor, j * 45, i * 45);
			if (game->field[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, graphics->wall, j * 45, i * 45);	
			if (game->field[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, graphics->player, j * 45, i * 45);
			if (game->field[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, graphics->collectible, j * 45, i * 45);
			if (game->field[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, graphics->exit, j * 45, i * 45);
			j++;
		}
		i++;
	}
}
