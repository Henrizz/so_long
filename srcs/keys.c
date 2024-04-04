/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:54:29 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/04/04 17:20:47 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/ft_printf.h"
#include "../headers/get_next_line.h"

int key_hook(int keycode, t_game *game)
{
	ft_printf("Key pressed: %d\n", keycode);
	if (keycode == ESC) // 65307 is the keycode for the Escape key on Linux, 53 on Mac
		close_button(game);
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		update_player_position(keycode, game);	
    	return (0);
}
