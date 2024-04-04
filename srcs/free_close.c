/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:21:43 by Henriette         #+#    #+#             */
/*   Updated: 2024/04/01 20:23:15 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/so_long.h"
#include "../headers/ft_printf.h"
#include "../headers/get_next_line.h"

int	close_button(t_game *game, t_graphics *graphics)
{
	free_images(game, graphics);
	free_field(game);
	mlx_destroy_window(game->mlx, game->win);
	//mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void free_images(t_game *game, t_graphics *graphics)
{
    mlx_destroy_image(game->mlx, graphics->collectible);
    mlx_destroy_image(game->mlx, graphics->wall);
    mlx_destroy_image(game->mlx, graphics->floor);
    mlx_destroy_image(game->mlx, graphics->player);
    mlx_destroy_image(game->mlx, graphics->exit);
}
