/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:54:29 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/06/10 16:26:38 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_button(game);
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		update_player_position(keycode, game);
	return (0);
}

int	update_player_position(int keycode, t_game *game)
{
	int	row;
	int	col;
	int	count;

	row = 0;
	col = 0;
	count = 0;
	find_p(game, &row, &col);
	if (keycode == UP)
		count = move_up(game, &row, &col);
	if (keycode == DOWN)
		count = move_down(game, &row, &col);
	if (keycode == LEFT)
		count = move_left(game, &row, &col);
	if (keycode == RIGHT)
		count = move_right(game, &row, &col);
	if (count == 0)
	{
		game->moves_count++;
		ft_printf("%d\n", game->moves_count);
	}
	return (0);
}

int	move_up(t_game *game, int *row, int *col)
{
	if (game->field[*row - 1][*col] == '1')
		return (1);
	if (game->field[*row - 1][*col] == 'E')
	{
		if (game->coins_found == game->coins_map)
			close_button(game);
		else
		{
			game->field[*row - 1][*col] = 'H';
			game->field[*row][*col] = '0';
		}
	}
	else if (game->field[*row - 1][*col] != '1' 
		&& game->field[*row - 1][*col] != 'E')
	{
		if (game->field[*row - 1][*col] == 'C')
			game->coins_found++;
		if (game->field[*row][*col] == 'H')
			game->field[*row][*col] = 'E';
		else
			game->field[*row][*col] = '0';
		game->field[*row - 1][*col] = 'P';
	}
	display_graphics(game);
	return (0);
}

int	move_down(t_game *game, int *row, int *col)
{
	if (game->field[*row + 1][*col] == '1')
		return (1);
	if (game->field[*row + 1][*col] == 'E')
	{
		if (game->coins_found == game->coins_map)
			close_button(game);
		else
		{
			game->field[*row + 1][*col] = 'H';
			game->field[*row][*col] = '0';
		}
	}
	else if (game->field[*row + 1][*col] != '1' 
		&& game->field[*row + 1][*col] != 'E')
	{
		if (game->field[*row + 1][*col] == 'C')
			game->coins_found++;
		if (game->field[*row][*col] == 'H')
			game->field[*row][*col] = 'E';
		else
			game->field[*row][*col] = '0';
		game->field[*row + 1][*col] = 'P';
	}
	display_graphics(game);
	return (0);
}

int	move_left(t_game *game, int *row, int *col)
{
	if (game->field[*row][*col - 1] == '1')
		return (1);
	if (game->field[*row][*col - 1] == 'E')
	{
		if (game->coins_found == game->coins_map)
			close_button(game);
		else
		{
			game->field[*row][*col - 1] = 'H';
			game->field[*row][*col] = '0';
		}
	}
	else if (game->field[*row][*col - 1] != '1' 
		&& game->field[*row][*col - 1] != 'E')
	{
		if (game->field[*row][*col - 1] == 'C')
			game->coins_found++;
		if (game->field[*row][*col] == 'H')
			game->field[*row][*col] = 'E';
		else
			game->field[*row][*col] = '0';
		game->field[*row][*col - 1] = 'P';
	}
	display_graphics(game);
	return (0);
}
