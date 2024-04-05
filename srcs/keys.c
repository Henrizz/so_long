/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:54:29 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/04/05 11:27:11 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/ft_printf.h"
#include "../headers/get_next_line.h"

int key_hook(int keycode, t_game *game)
{
	//ft_printf("Key pressed: %d\n", keycode);
	if (keycode == ESC) // 65307 is the keycode for the Escape key on Linux, 53 on Mac
		close_button(game);
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		update_player_position(keycode, game);	
    return (0);
}

int	update_player_position(int keycode, t_game *game)
{
	int	row;
	int	col;
	
	row = 0;
	col = 0;
	find_p(game, &row, &col);
	if (keycode == UP)
		move_up(game, &row, &col);
	if (keycode == DOWN)
		move_down(game, &row, &col);
	if (keycode == LEFT)
		move_left(game, &row, &col);
	if (keycode == RIGHT)
		move_right(game, &row, &col);
	return (0);
}
	/*if (keycode == UP && game->field[row - 1][col] != '1' && game->field[row - 1][col] != 'E')
	{
		if (game->field[row - 1][col] == 'C')
			game->coins_found++;
		game->field[row][col] = '0';
		game->field[row - 1][col] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.floor, col * 45, row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player, col * 45, (row - 1) * 45);
	}
	else if (keycode == DOWN && game->field[row + 1][col] != '1' && game->field[row + 1][col] != 'E')
	{
		if (game->field[row + 1][col] == 'C')
			game->coins_found++;
		game->field[row][col] = '0';
		game->field[row + 1][col] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.floor, col * 45, row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player, col * 45, (row  + 1) * 45);
	}
	else if (keycode == LEFT && game->field[row][col - 1] != '1' && game->field[row][col - 1] != 'E')
	{
		if (game->field[row][col - 1] == 'C')
			game->coins_found++;
		game->field[row][col] = '0';
		game->field[row][col - 1] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.floor, col * 45, row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player, (col - 1) * 45, row * 45);
	}
	else if (keycode == RIGHT && game->field[row][col + 1] != '1' && game->field[row][col + 1] != 'E')
	{
		if (game->field[row][col + 1] == 'C')
			game->coins_found++;
		game->field[row][col] = '0';
		game->field[row][col + 1] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.floor, col * 45, row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player, (col + 1) * 45, row * 45);
	}
	else if (((keycode == DOWN && game->field[row + 1][col] == 'E')
		|| (keycode == LEFT && game->field[row][col - 1] == 'E') || (keycode == RIGHT && game->field[row][col + 1] == 'E'))
		&& game->coins_found == game->coins_map)
			close_button(game);
	else if ((keycode == DOWN && game->field[row + 1][col] == '1')
		|| (keycode == LEFT && game->field[row][col - 1] == '1') || (keycode == RIGHT && game->field[row][col + 1] == '1'))
		return (1);
	return (0);
}	*/

int	move_up(t_game *game, int *row, int *col)
{
	if (game->field[*row - 1][*col] == '1')
		return (1);
	if (game->field[*row - 1][*col] != '1' && game->field[*row - 1][*col] != 'E' && game->field[*row][*col] != 'H')
	{
		if (game->field[*row - 1][*col] == 'C')
			game->coins_found++;
		game->field[*row][*col] = '0';
		game->field[*row - 1][*col] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.floor, *col * 45, *row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player, *col * 45, (*row - 1) * 45);
	}
	if (game->field[*row - 1][*col] == 'E' && game->coins_found == game->coins_map)
		close_button(game);
	if (game->field[*row - 1][*col] == 'E' && game->coins_found != game->coins_map)
	{
		game->field[*row][*col] = '0';
		game->field[*row - 1][*col] = 'H';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.floor, *col * 45, *row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player_on_house, *col * 45, (*row - 1) * 45);
	}	
	if (game->field[*row - 1][*col] != '1' && game->field[*row][*col] == 'H')
	{
		game->field[*row][*col] = 'E';
		game->field[*row - 1][*col] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.exit, *col * 45, *row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player, *col * 45, (*row - 1) * 45);
	}
	return (0);
}

int	move_down(t_game *game, int *row, int *col)
{
	if (game->field[*row + 1][*col] == '1')
		return (1);
	if (game->field[*row + 1][*col] != '1' && game->field[*row + 1][*col] != 'E' && game->field[*row][*col] != 'H')
	{
		if (game->field[*row + 1][*col] == 'C')
			game->coins_found++;
		game->field[*row][*col] = '0';
		game->field[*row + 1][*col] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.floor, *col * 45, *row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player, *col * 45, (*row + 1) * 45);
	}
	if (game->field[*row + 1][*col] == 'E' && game->coins_found == game->coins_map)
		close_button(game);
	if (game->field[*row + 1][*col] == 'E' && game->coins_found != game->coins_map)
	{
		game->field[*row][*col] = '0';
		game->field[*row + 1][*col] = 'H';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.floor, *col * 45, *row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player_on_house, *col * 45, (*row + 1) * 45);
	}	
	if (game->field[*row + 1][*col] != '1' && game->field[*row][*col] == 'H')
	{
		game->field[*row][*col] = 'E';
		game->field[*row + 1][*col] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.exit, *col * 45, *row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player, *col * 45, (*row + 1) * 45);
	}
	return (0);
}

int	move_left(t_game *game, int *row, int *col)
{
	if (game->field[*row][*col - 1] == '1')
		return (1);
	if (game->field[*row][*col - 1] != '1' && game->field[*row][*col - 1] != 'E' && game->field[*row][*col] != 'H')
	{
		if (game->field[*row][*col - 1] == 'C')
			game->coins_found++;
		game->field[*row][*col] = '0';
		game->field[*row][*col - 1] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.floor, *col * 45, *row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player, (*col - 1) * 45, *row * 45);
	}
	if (game->field[*row][*col - 1] == 'E' && game->coins_found == game->coins_map)
		close_button(game);
	if (game->field[*row][*col - 1] == 'E' && game->coins_found != game->coins_map)
	{
		game->field[*row][*col] = '0';
		game->field[*row][*col - 1] = 'H';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.floor, *col * 45, *row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player_on_house, (*col - 1) * 45, *row * 45);
	}	
	if (game->field[*row + 1][*col] != '1' && game->field[*row][*col] == 'H')
	{
		game->field[*row][*col] = 'E';
		game->field[*row][*col - 1] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.exit, *col * 45, *row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player, (*col - 1) * 45, *row * 45);
	}
	return (0);
}
int	move_right(t_game *game, int *row, int *col)
{
	if (game->field[*row][*col + 1] == '1')
		return (1);
	if (game->field[*row][*col + 1] != '1' && game->field[*row][*col + 1] != 'E' && game->field[*row][*col] != 'H')
	{
		if (game->field[*row][*col + 1] == 'C')
			game->coins_found++;
		game->field[*row][*col] = '0';
		game->field[*row][*col + 1] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.floor, *col * 45, *row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player, (*col + 1) * 45, *row * 45);
	}
	if (game->field[*row][*col + 1] == 'E' && game->coins_found == game->coins_map)
		close_button(game);
	if (game->field[*row][*col + 1] == 'E' && game->coins_found != game->coins_map)
	{
		game->field[*row][*col] = '0';
		game->field[*row][*col + 1] = 'H';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.floor, *col * 45, *row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player_on_house, (*col + 1) * 45, *row * 45);
	}	
	if (game->field[*row + 1][*col] != '1' && game->field[*row][*col] == 'H')
	{
		game->field[*row][*col] = 'E';
		game->field[*row][*col + 1] = 'P';
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.exit, *col * 45, *row * 45);
		mlx_put_image_to_window(game->mlx, game->win, game->graphics.player, (*col + 1) * 45, *row * 45);
	}
	return (0);
}
