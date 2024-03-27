/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:27:53 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/03/27 17:42:35 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"


void	edited_mlx_pixel_put(t_game *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_circle(t_game *data, int center_x, int center_y, int radius, int color)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        edited_mlx_pixel_put(data, center_x + x, center_y + y, color);
        edited_mlx_pixel_put(data, center_x + y, center_y + x, color);
        edited_mlx_pixel_put(data, center_x - y, center_y + x, color);
        edited_mlx_pixel_put(data, center_x - x, center_y + y, color);
        edited_mlx_pixel_put(data, center_x - x, center_y - y, color);
        edited_mlx_pixel_put(data, center_x - y, center_y - x, color);
        edited_mlx_pixel_put(data, center_x + y, center_y - x, color);
        edited_mlx_pixel_put(data, center_x + x, center_y - y, color);

        if (err <= 0) {
            y += 1;
            err += 2*y + 1;
        }

        if (err > 0) {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

void draw_rainbow(t_game *data)
{
    int x = 0;
    int y = 0;
    int rainbow_colors[] = {0xFF0000, 0xFF7F00, 0xFFFF00, 0x00FF00, 0x0000FF, 0x4B0082, 0x9400D3};
    int num_colors = sizeof(rainbow_colors) / sizeof(rainbow_colors[0]);
    int num_slices = WINDOW_HEIGHT / num_colors;

    while (y < WINDOW_HEIGHT)
    {
        int color_index = y / num_slices;
        int color = rainbow_colors[color_index];

        while (x < WINDOW_WIDTH)
        {
            edited_mlx_pixel_put(data, x, y, color);
	    x++;
        }
	x = 0;
	y++;
    }
}
