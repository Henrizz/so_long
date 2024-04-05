/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:21:43 by Henriette         #+#    #+#             */
/*   Updated: 2024/04/05 11:35:24 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/so_long.h"
#include "../headers/ft_printf.h"
#include "../headers/get_next_line.h"

int	close_button(t_game *game)
{
	free_field(game);
	free_images(game);
	mlx_destroy_window(game->mlx, game->win);
	//mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void free_images(t_game *game)
{
	if (game->graphics.collectible != NULL)	
    		mlx_destroy_image(game->mlx, game->graphics.collectible);
	 if (game->graphics.wall != NULL)
    		mlx_destroy_image(game->mlx, game->graphics.wall);
	if (game->graphics.floor != NULL)
    		mlx_destroy_image(game->mlx, game->graphics.floor);
	if (game->graphics.player != NULL)
   		mlx_destroy_image(game->mlx, game->graphics.player);
	if (game->graphics.exit != NULL)
    		mlx_destroy_image(game->mlx, game->graphics.exit);
	if (game->graphics.player_on_house != NULL)
    		mlx_destroy_image(game->mlx, game->graphics.player_on_house);
}
