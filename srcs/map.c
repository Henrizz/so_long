/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:03:37 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/03/27 18:43:15 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/ft_printf.h"
#include "../headers/get_next_line.h"

int	read_map(char *map, t_game *game)
{
	int	fd;
	char	*read_m;
	
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\ncould not open file");
		return (1);
	}
	read_m = get_next_line(fd);
	if (read_m == NULL)
		exit(EXIT_FAILURE);
	game->width = ft_strlen(read_m);
	ft_printf("game width = %d", game->width);
	game->height = 1;
	ft_printf("game height = %d", game->height);
	while (read_m)
	{
		free(read_m);
		read_m = get_next_line(fd);
		game->height++;
		ft_printf("game height = %d", game->height);
	}
	close(fd);
	write_check_map(game, game->height, map);
	free(read_m);
	return (0);
}

int	write_check_map(t_game *game, int height, char* map)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(map, O_RDONLY);
	game->field = malloc(sizeof(char *) * height);
	while (i < height)
	{
		game->field[i] = get_next_line(fd);
		i++;
	}
}
