/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:31:55 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/04/01 19:53:30 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/ft_printf.h"
#include "../headers/get_next_line.h"

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
	t_graphics graphics;
	
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 45, game->height * 45, "Going home from 42 after a long day of coding - THE GAME");
	
	if (transfer_graphics(game, &graphics) == 1)
	{
		ft_printf("Error\nFailed to load images");
		exit(EXIT_SUCCESS);
	}
	display_graphics(game, &graphics);
    mlx_key_hook(game->win, &key_hook, &game);
	mlx_hook(game->win, 17, 0, &close_button, &game);
	ft_printf("test3\n");
	mlx_loop(game->mlx);
}

//void	close_function(t_game *game)


/*
int	main(void)
{
	t_game	game;
	
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hiiiii theeeere!");
	//game.img = mlx_new_image(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game.img = mlx_xpm_file_to_image(game.mlx, "images/aqua_cross.xpm", &game.width, &game.height );
	if (!game.img)
	{
		ft_printf("Error: Failed to load XPM image. \n");
		return (1);
	}
	game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length,
								&game.endian);
	//edited_mlx_pixel_put(&game, 5, 5, 0x00FF0000);
	//draw_circle(&game, 400, 250, 100, 0x00FF0000);
	//draw_rainbow(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
	mlx_hook(game.win, 17, 0, &close_button, &game); // Close button event
    	mlx_key_hook(game.win, &key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}*/
