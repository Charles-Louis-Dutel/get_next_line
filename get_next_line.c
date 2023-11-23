/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:01:32 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/23 14:07:54 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_temp(char *temp, char *dest)
{
	char	*s;
	int		i;
	int		j;

	s = malloc((ft_len(temp) + ft_len(dest) + 1) * sizeof(char));
	if (!temp || !dest || !s)
		return (NULL);
	i = 0;
	while (temp[i])
	{
		s[i] = temp[i];
		i++;
	}
	j = 0;
	while (dest[j])
	{
		s[i] = dest [j];
		i++;
		j++;
	}
	s[i] = '\0';
	free(temp);
	return (s);
}

char	*ft_check_temp(char *temp)
{
	int	i;

	i = 0;
	if (temp)
	{
		while (temp[i] && temp[i] != '\n')
			i++;
		if (temp[i] == '\n')
			return ((char *)&temp[i]);
	}
	return (NULL);
}

char	*ft_read(char *temp, int fd)
{
	char	*dest;
	int		value;

	if (!temp)
		temp = ft_calloc(1, 1);
	dest = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!dest)
		return (NULL);
	value = 1;
	while (value > 0)
	{
		value = read(fd, dest, BUFFER_SIZE);
		if (value == -1)
		{
			free(dest);
			free(temp);
			return (NULL);
		}
		dest[value] = '\0';
		temp = ft_update_temp(temp, dest);
		if (ft_check_temp(temp))
			break ;
	}
	free(dest);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_read(temp, fd);
	if (!temp)
	{
		free(temp);
		return (NULL);
	}
	line = ft_new_line(temp);
	temp = ft_new_temp(temp);
	return (line);
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
