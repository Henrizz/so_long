/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:54:29 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/04/04 16:23:18 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/ft_printf.h"
#include "../headers/get_next_line.h"

int key_hook(int keycode, t_game *data, t_graphics *graphics)
{
	ft_printf("Key pressed: %d\n", keycode);
	ft_printf("graphics collectible pointer inside key hook: %p\n", (void *)graphics->collectible);
	if (keycode == 65307) // 65307 is the keycode for the Escape key on Linux, 53 on Mac
        {
		ft_printf("Escape key pressed\n");
		close_button(data, graphics);
	}
    	return (0);
}
