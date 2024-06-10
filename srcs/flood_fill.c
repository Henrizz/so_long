/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:10:43 by Henriette         #+#    #+#             */
/*   Updated: 2024/06/10 16:26:19 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	flood_fill(t_game *game)
{
	int		row;
	int		col;
	char	**checker;
	int		path;

	checker = NULL;
	row = 0;
	col = 0;
	path = 0;
	game->coins_path = 0;
	initialize_checker(&checker, game);
	find_p(game, &row, &col);
	if (fill_rec(game, row, col, checker) == 1 
		&& game->coins_map != game->coins_path)
	{
		path = 1;
		ft_printf("Error\nno valid path");
	}
	free_checker(game, checker);
	return (path);
}

void	free_checker(t_game *game, char **checker)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(checker[i]);
		i++;
	}
	free(checker);
}

void	initialize_checker(char ***checker, t_game *game)
{
	int	row;
	int	i;

	*checker = ft_calloc(game->height, sizeof(char *));
	if (!(*checker))
		return ;
	row = 0;
	i = 0;
	while (row < game->height)
	{
		(*checker)[row] = ft_calloc(game->width + 1, sizeof(char));
		if (!(*checker)[row])
		{
			while (i < row)
			{
				free((*checker)[i]);
				i++;
			}
			free(*checker);
			*checker = NULL;
			return ;
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
			if (game->field[rows][cols] == 'P' 
				|| game->field[rows][cols] == 'H')
			{
				*start_y = rows;
				*start_x = cols;
				return ;
			}
			cols++;
		}
		cols = 0;
		rows++;
	}
}
