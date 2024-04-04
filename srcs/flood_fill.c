/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:10:43 by Henriette         #+#    #+#             */
/*   Updated: 2024/04/04 13:39:41 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/ft_printf.h"
#include "../headers/get_next_line.h"

int	flood_fill(t_game *game)
{
	int	row;
	int	col;
	char **checker;
	int	path;

	checker = NULL;
	row = 0;
	col = 0;
	path = 0;
	game->coins_path = 0;
	initialize_checker(&checker, game);
	find_p(game, &row, &col);
	if (fill_rec(game, row, col, checker) == 1 && game->coins_map != game->coins_path)
	{	
		path = 1;
		ft_printf("Error\nno valid path");
	}
	//ft_printf("\npath coins: %d, map coins: %d", game->coins_path, game->coins_map);
	int i = 0;
	while (i < game->height)
	{
		free(checker[i]);
		i++;
	}
	return (path);
}

void	initialize_checker(char ***checker, t_game *game)
{
	int	row;
	
	*checker = ft_calloc(game->height, sizeof(char *));
	if (!(*checker))
		return;
	row = 0;
	while (row < game->height)
	{
		(*checker)[row] = ft_calloc(game->width + 1, sizeof(char *));
		if (!(*checker)[row])
		{
			free(*checker);
			*checker = NULL;
			return;
		}
		row++;
	}
}

int	fill_rec(t_game *game, int rows, int cols, char **checker)
{	
	int	e;

	e = 0;
	if (rows < 0 || cols < 0 || rows >= game->height || cols >= game->width)
		return (1);
	if (game->field[rows][cols] == '1' || checker[rows][cols] == 'F')
		return (1);
	//ft_printf("%c", (game->field[rows][cols]));
	if (game->field[rows][cols] == 'C')
		game->coins_path++;
	if (game->field[rows][cols] == 'E')
		e = 1;
	checker[rows][cols] = 'F';
	fill_rec(game, rows - 1, cols, checker);
	fill_rec(game, rows + 1, cols, checker);
	fill_rec(game, rows, cols - 1, checker);
	fill_rec(game, rows, cols + 1, checker);
	if (e == 1)
		return (0);
	return (1);
}

void	find_p(t_game *game, int *start_y, int *start_x)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	while (rows < game->height)
	{
		while (cols < game->width)
		{
			if (game->field[rows][cols] == 'P')
			{
				*start_y = rows;
				*start_x = cols;	
				return;
			}
			cols++;
		}
		cols = 0;
		rows++;
	}
}
