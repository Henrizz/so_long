/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:37:38 by Henriette         #+#    #+#             */
/*   Updated: 2024/06/10 17:25:45 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char const));
	if (new == 0)
	{
		free(s1);
		return (0);
	}
	while (s1[i] != 0)
		new[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
	{
		new[j] = s2[i];
		i++;
		j++;
	}
	new[j] = 0;
	free(s1);
	return (new);
}
/*
#include <stdio.h>
int	main(void)
{
	char	string1[] = "";
	char	string2[] = "der zweite ist hier";
	char	*ptr;
	ptr = ft_strjoin(string1, string2);
	printf("%s\n", ptr);
	free(ptr);
	return (0);
}*/
