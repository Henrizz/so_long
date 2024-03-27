/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:02:32 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/03/27 16:24:56 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_conv_print_hex(unsigned int n, const char sign)
{
	int	length;

	length = 0;
	if (n > 15)
	{
		length = length + ft_conv_print_hex(n / 16, sign);
		length = length + ft_conv_print_hex(n % 16, sign);
	}
	else
	{
		if (n <= 9)
			length = length + ft_printchar(n + '0');
		else
		{
			if (sign == 'x')
				length = length + ft_printchar(n - 10 + 'a');
			if (sign == 'X')
				length = length + ft_printchar(n - 10 + 'A');
		}
	}
	return (length);
}
