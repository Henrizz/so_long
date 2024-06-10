/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:03:37 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/06/10 16:26:47 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map(char *map, t_game *game)
{
	int		fd;
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

int	check_map(t_game *game, char *map)
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
	if (check_name(map) == 1 || check_components(game) == 1 
		|| check_rectangle(game) || check_surrounding(game) == 1 
		|| flood_fill(game) == 1)
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
	}
}

int	check_surrounding(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if ((game->field[i][0]) != '1' 
			|| game->field[i][game->width - 1] != '1')
		{
			ft_printf("Error\nwall is not all around map");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < game->width)
	{
		if ((game->field[0][i]) != '1' 
			|| game->field[game->height - 1][i] != '1')
		{
			ft_printf("Error\nwall is not all around map");
			return (1);
		}
		i++; 
	}
	return (0);
}

int	check_rectangle(t_game *game)
{
	int	i;

	i = 0;
	game->coins_found = 0;
	game->moves_count = 0;
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
