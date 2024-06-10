/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:31:55 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/06/10 16:26:43 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nNo valid argument");
		exit(EXIT_SUCCESS);
	}
	get_map(argv[1], &game);
	make_window(&game);
	return (0);
}

void	make_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 45, game->height * 45, \
		"Going home from 42 after a long day of coding - THE GAME");
	if (transfer_graphics(game) == 1)
	{
		ft_printf("Error\nFailed to load images");
		exit(EXIT_FAILURE);
	}
	display_graphics(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 0, close_button, game);
	mlx_loop(game->mlx);
}
