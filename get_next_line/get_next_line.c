/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzimmerm <hzimmerm@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:41:49 by hzimmerm          #+#    #+#             */
/*   Updated: 2024/03/27 15:32:10 by hzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

int	new_line_check(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_excerpt_line(char *temp)
{
	int		i;
	char	*line;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	line = (char *)ft_calloc((i + 1 + (new_line_check(temp))), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i] != 0 && temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*keep_rest(char *temp)
{
	int		i;
	int		j;
	char	*new_temp;

	i = 0;
	j = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\0')
	{
		free(temp);
		return (NULL);
	}
	new_temp = (char *)ft_calloc((ft_strlen(temp) - i + 1), sizeof(char));
	if (!new_temp)
	{
		free(temp);
		return (NULL);
	}
	i++;
	while (temp[i] != '\0')
		new_temp[j++] = temp[i++];
	new_temp[j] = '\0';
	free(temp);
	return (new_temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (temp)
			free (temp);
		temp = NULL;
		return (NULL);
	}
	if (!temp)
		temp = (char *)ft_calloc(1, sizeof(char));
	if (!temp)
		return (NULL);
	temp = ft_read_and_check(fd, temp);
	line = ft_excerpt_line(temp);
	if (!line)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	temp = keep_rest(temp);
	return (line);
}

/*
int	main(void)
{
	int		fd;
	char	*str;

	//fd = open("/dev/null", O_RDONLY);
	fd = open("1char.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}*/
