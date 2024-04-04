/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printoutfunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Henriette <Henriette@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:10:46 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/03/30 18:16:45 by Henriette        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}

int	ft_printnbr(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		length++;
	}
	if (n >= 10)
		length = length + ft_printnbr(n / 10);
	length = length + ft_printchar(n % 10 + '0');
	return (length);
}

int	ft_print_unsint(unsigned int n)
{
	int	length;

	length = 0;
	if (n >= 10)
		length = length + ft_print_unsint(n / 10);
	length = length + ft_printchar(n % 10 + '0');
	return (length);
}
