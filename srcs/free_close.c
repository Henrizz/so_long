/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:21:43 by Henriette         #+#    #+#             */
/*   Updated: 2024/04/04 13:43:50 by hzimmerm         ###   ########.fr       */
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
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void free_images(t_game *game, t_graphics *graphics)
{
	if (graphics == NULL)
	{
		ft_printf("Error\n Graphics pointer is null");
		return;
	}
	if (graphics->collectible != NULL)	
    		mlx_destroy_image(game->mlx, graphics->collectible);
	 if (graphics->wall != NULL)
    		mlx_destroy_image(game->mlx, graphics->wall);
	if (graphics->floor != NULL)
    		mlx_destroy_image(game->mlx, graphics->floor);
	if (graphics->player != NULL)
   		mlx_destroy_image(game->mlx, graphics->player);
	if (graphics->exit != NULL)
    		mlx_destroy_image(game->mlx, graphics->exit);
	free(graphics);
}
