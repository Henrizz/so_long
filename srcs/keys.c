/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:54:29 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/03/27 17:42:29 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/ft_printf.h"
#include "../headers/get_next_line.h"

int close_window(t_game *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

int key_hook(int keycode, t_game *data)
{
	ft_printf("Key pressed: %d\n", keycode);
	if (keycode == 65307) // 65307 is the keycode for the Escape key
        {
		ft_printf("Escape key pressed\n");
		close_window(data);
	}
    	return (0);
}

int close_button(t_game *data)
{
    close_window(data);
    return (0);
}
