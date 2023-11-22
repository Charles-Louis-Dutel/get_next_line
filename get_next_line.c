/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:01:32 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/22 15:21:29 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>

void	ft_update_temp(char *dest, char temp[])
{
	int	i;
	int	j;

	i = 0;
	if (temp[i] != '\0')
	{
		while (temp[i])
			i++;
	}
	if (dest)
	{
		j = 0;
		while (dest[j])
		{
			temp[i] = dest[j];
			i++;
			j++;
		}
		temp[i] = '\0';
	}
}

int	ft_check_temp(char temp[])
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n' || temp[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	temp[100000];
	char		*dest;
	char		*line;
	int			trigger;
	int			value;

	trigger = 0;
	while (trigger == 0)
	{
		dest = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!dest)
			return (NULL);
		value = read(fd, dest, BUFFER_SIZE);
		ft_update_temp(dest, temp);
		free (dest);
		if (ft_check_temp(temp) == 1 || value < BUFFER_SIZE)
			trigger = 1;
	}
	if (ft_check_temp(temp) == 1)
	{
		line = ft_new_line(temp);
		ft_new_temp(temp);
		return (line);
	}
	return (NULL);
}
/*
int main()
{
	int	fd;
	char *test;

	fd = open("caca.txt", O_RDONLY);
	while (1)
	{
		test = get_next_line(fd);
		if (test == NULL)
			break;
		printf("%s", test);
		free(test);
	}
	return 0;
}*/
