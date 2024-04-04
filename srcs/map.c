/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:03:37 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/04/04 13:43:00 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/ft_printf.h"
#include "../headers/get_next_line.h"

void	get_map(char *map, t_game *game)
{
	int	fd;
	char	*read_m;
	
	fd = open(map, O_RDWR);
	if (fd == -1)
	{
		perror("Error\ncould not open file");
		exit(EXIT_FAILURE);
	}
	read_m = get_next_line(fd);
	if (read_m == NULL)
		exit(EXIT_FAILURE);
	game->width = ft_strlen(read_m) - 1;
	game->height = 0;
	while (read_m)
	{
		free(read_m);
		read_m = get_next_line(fd);
		game->height++;
	}
	close(fd);
	free(read_m);
	if (check_map(game, map) == 1)
		exit(EXIT_FAILURE);
}

int	check_map(t_game *game, char* map)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(map, O_RDWR);
	game->field = malloc(sizeof(char *) * game->height);
	if (game->field == NULL)
	{
		perror("Error\ncould not allocate memor for map");
		return (1);
	}
	while (i < game->height)
	{
		game->field[i] = get_next_line(fd);
		i++;
	}
	if (check_name(map) == 1 || check_components(game) == 1 || check_rectangle(game)
		|| check_surrounding(game) == 1 || flood_fill(game) == 1)
	{	
		free_field(game);
		return (1);
	}
	return (0);
}

void	free_field(t_game *game)
{
	int	i;

	i = 0;
	if (game->field != NULL)
	{
		while (i < game->height)
		{
			free(game->field[i]);
			game->field[i] = NULL;
			i++;
		}
		free(game->field);
		game->field = NULL;
	}
}

int	check_surrounding(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	//ft_printf("height: %d, width: %d", game->height, game->width);
	while (i < game->height)
	{
		//ft_printf("i: %d", i);
		if ((game->field[i][0]) != '1' || game->field[i][game->width - 1] != '1')
		{
			ft_printf("Error\nwall is not all around map");
			return (1);
		}
		i++;
	}
	while (j < game->width)
	{
		if ((game->field[0][j]) != '1' || game->field[game->height - 1][j] != '1')
		{
			ft_printf("Error\nwall is not all around map");
			return (1);
		}
		j++; 
	}
	return (0);
}

int	check_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if ((int)ft_strlen(game->field[i]) != game->width + 1)
		{
			ft_printf("Error\nmap is not rectangular");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_name(char *name)
{
	int	i;
	
	i = 0;
	while (name[i])
	{
		if (name[i] == '.' && name[i + 1] == 'b' && name[i + 2] == 'e' && name[i + 3] == 'r')
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
	int	p;
	int	e;

	rows = 0;
	cols = 0;
	e = 0;
	p = 0;
	game->coins_map = 0;
	while (rows < game->height)
	{
		while (cols < game->width)
		{
			if (invalid_comp(game, &rows, &cols, &p, &e) == 1)
				return (1);
			/*if (game->field[rows][cols] == 'P')
				p++;
			if (game->field[rows][cols] == 'C')
				game->coins_map++;
			if (game->field[rows][cols] == 'E')
				e++;
			if (game->field[rows][cols] != '1' && game->field[rows][cols] != '0'
				&& game->field[rows][cols] != 'P' && game->field[rows][cols] != 'C'
				&& game->field[rows][cols] != 'E' && game->field[rows][cols] != '\n' && game->field[rows][cols] != '\0')
				{
					ft_printf("Error\ninvalid components");
					return(1);
				}	*/
			cols++;
		//ft_printf("cols: %d, rows: %d, e: %d, c: %d, p: %d", cols, rows, e, c, p);
		}
		cols = 0;
		rows++;
	}
	if (p != 1 || e != 1 || game->coins_map < 1)
	{
		ft_printf("Error\ninvalid amount of elements");
		return(1);
	}
	return (0);
}

int	invalid_comp(t_game *game, int *rows, int *cols, int *p, int *e)
{
	if (game->field[*rows][*cols] == 'P')
				(*p)++;
			if (game->field[*rows][*cols] == 'C')
				game->coins_map++;
			if (game->field[*rows][*cols] == 'E')
				(*e)++;
			if (game->field[*rows][*cols] != '1' && game->field[*rows][*cols] != '0'
				&& game->field[*rows][*cols] != 'P' && game->field[*rows][*cols] != 'C'
				&& game->field[*rows][*cols] != 'E' && game->field[*rows][*cols] != '\n' && game->field[*rows][*cols] != '\0')
				{
					ft_printf("Error\ninvalid components");
					return(1);
				}	
	return (0);
}
