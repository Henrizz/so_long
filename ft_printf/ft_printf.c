/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:25:19 by Henriette         #+#    #+#             */
/*   Updated: 2024/03/27 16:25:05 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// parse string until % is encountered, then check the next index for conv sign
// then each conversion sign gets own situation
// return value is number of characters written

#include "../headers/ft_printf.h"

int	ft_conversion(const char c, va_list args)
{
	int	length;

	length = 0;
	if (c == 'c')
		length = ft_printchar(va_arg(args, int));
	else if (c == 's')
		length = ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		length = ft_putptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		length = ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		length = ft_print_unsint(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		length = ft_conv_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		length = ft_printchar('%');
	else if (c == '@')
		length = write(1, "%@", 2);
	else
		length = -1;
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		length;
	int		result;
	int		i;
	va_list	args;

	length = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			result = ft_conversion(format[i + 1], args);
			if (result == -1 || format[i + 1] == '\0')
				return (-1);
			length = length + result;
			i++;
		}
		else 
			length = length + ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}
/*
#include <limits.h>
int main(void)
{
	//int	n = -9;
	int result1;
	int result2;
	//char	ptr[] = "Hallo string";
	result1 = printf("buil %d%@", -1);
	printf("\n");
	result2 = ft_printf("ours %d%@", -1);
	printf("\n\n%d, %d", result1, result2);
	return (0);
}*/
