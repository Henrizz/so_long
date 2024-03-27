/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:03:37 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/03/27 17:59:39 by hzimmerm         ###   ########.fr       */
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
	game->height = 0;
	ft_printf("game height = %d", game->height);
	while (read_m)
	{
		free(read_m);
		read_m = get_next_line(fd);
		game->height++;
		ft_printf("game height = %d", game->height);
	}
	close(fd);
	free(read_m);
	return (0);
}
