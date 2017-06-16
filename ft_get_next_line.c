/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 23:54:17 by nngwenya          #+#    #+#             */
/*   Updated: 2017/06/17 00:32:08 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"


int		ft_get_next_line(const int fd, char **line)
{
	int p_fd;
	char buffer[BUFF_SIZE + 1];
	char *str;
	int i;

	str = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	p_fd = read(fd, buffer, BUFF_SIZE + 1);
	buffer[BUFF_SIZE] = '\0';
	i = 0;
	while (i < BUFF_SIZE + 1)
	{
		str[i] = buffer[i];
		i++;
	}
	*line = str;

	return (1);
}
