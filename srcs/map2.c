/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:55:11 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/06/10 16:26:53 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_name(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '.' && name[i + 1] == 'b' && name[i + 2] == 'e' 
			&& name[i + 3] == 'r')
			return (0);
		i++;
	}
	ft_printf("Error\nno valid map format");
	return (1);
}

int	check_components(t_game *game)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	game->e = 0;
	game->p = 0;
	game->coins_map = 0;
	while (rows < game->height)
	{
		while (cols < game->width)
		{
			if (invalid_comp(game, &rows, &cols) == 1)
				return (1);
			cols++;
		}
		cols = 0;
		rows++;
	}
	if (game->p != 1 || game->e != 1 || game->coins_map < 1)
	{
		ft_printf("Error\ninvalid amount of elements");
		return (1);
	}
	return (0);
}

int	invalid_comp(t_game *game, int *rows, int *cols)
{
	if (game->field[*rows][*cols] == 'P')
		game->p++;
	if (game->field[*rows][*cols] == 'C')
		game->coins_map++;
	if (game->field[*rows][*cols] == 'E')
		game->e++;
	if (game->field[*rows][*cols] != '1' && game->field[*rows][*cols] != '0'
		&& game->field[*rows][*cols] != 'P' && game->field[*rows][*cols] != 'C'
		&& game->field[*rows][*cols] != 'E' && game->field[*rows][*cols] != '\n'
		&& game->field[*rows][*cols] != '\0')
	{
		ft_printf("Error\ninvalid components");
		return (1);
	}
	return (0);
}

int	move_right(t_game *game, int *row, int *col)
{
	if (game->field[*row][*col + 1] == '1')
		return (1);
	if (game->field[*row][*col + 1] == 'E')
	{
		if (game->coins_found == game->coins_map)
			close_button(game);
		else
		{
			game->field[*row][*col + 1] = 'H';
			game->field[*row][*col] = '0';
		}
	}
	else if (game->field[*row][*col + 1] != '1' 
		&& game->field[*row][*col + 1] != 'E')
	{
		if (game->field[*row][*col + 1] == 'C')
			game->coins_found++;
		if (game->field[*row][*col] == 'H')
			game->field[*row][*col] = 'E';
		else
			game->field[*row][*col] = '0';
		game->field[*row][*col + 1] = 'P';
	}
	display_graphics(game);
	return (0);
}
