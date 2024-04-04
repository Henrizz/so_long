/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:54:29 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/04/01 20:23:00 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/ft_printf.h"
#include "../headers/get_next_line.h"

int key_hook(int keycode, t_game *data, t_graphics *graphics)
{
	ft_printf("Key pressed: %d\n", keycode);
	if (keycode == 53) // 65307 is the keycode for the Escape key on Linux
        {
		ft_printf("Escape key pressed\n");
		close_button(data, graphics);
	}
    	return (0);
}
