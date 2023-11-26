/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:03:59 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/26 13:11:40 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_list(t_list *temp)
{
	t_list	*current;
	t_list	*next;

	current = temp;
	while (current)
	{
		free(current->data);
		next = current->next;
		free(current);
		current = next;
	}
}

void	ft_update_temp(char *dest, t_list **temp, int value)
{
	int		i;
	t_list	*last;
	t_list	*next_temp;

	next_temp = malloc(sizeof(t_list));
	if (!next_temp)
		return ;
	next_temp->next = NULL;
	next_temp->data = malloc(sizeof(char) * (value + 1));
	if (!next_temp->data)
		return ;
	i = 0;
	while (dest[i] && i < value)
	{
		next_temp->data[i] = dest[i];
		i++;
	}
	next_temp->data[i] = '\0';
	if (*temp == NULL)
	{
		*temp = next_temp;
		return ;
	}
	last = ft_get_last(*temp);
	last->next = next_temp;
}

int	ft_check_temp(t_list *temp)
{
	int		i;
	t_list	*last;

	if (!temp)
		return (0);
	last = ft_get_last(temp);
	i = 0;
	while (last->data[i])
	{
		if (last->data[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_read(t_list **temp, int fd)
{
	char	*dest;
	int		value;

	value = 1;
	while (!ft_check_temp(*temp) && value != 0)
	{
		dest = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!dest)
			return ;
		value = read(fd, dest, BUFFER_SIZE);
		if (value == -1)
		{
			free(dest);
			free(*temp);
			return ;
		}
		dest[value] = '\0';
		ft_update_temp(dest, temp, value);
		free(dest);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*temp[4096];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read(&temp[fd], fd);
	if (!temp[fd])
		return (NULL);
	line = NULL;
	line = ft_new_line(temp[fd]);
	ft_new_temp(&temp[fd]);
	if (line[0] == '\0')
	{
		ft_free_list(temp[fd]);
		temp[fd] = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
/*
int main()
{
	int	fd;
	char *test;

	test = NULL;
	fd = open("test.txt", O_RDONLY);
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
