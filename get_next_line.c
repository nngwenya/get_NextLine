/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 23:54:17 by nngwenya          #+#    #+#             */
/*   Updated: 2017/06/19 12:35:36 by fscheepe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"


int		get_next_line(const int fd, char **line)
{
	int read_bytes;
	static char buffer[BUFF_SIZE + 1];
	char *str;

	read_bytes = read(fd, buffer, BUFF_SIZE);
	buffer[BUFF_SIZE] = '\0';
	str = ft_strjoin(*line, buffer);
	free(*line);
	*line = str;

	return (read_bytes);
}

int		main(void)
{
	int		fd = open("wethinkcode.txt", O_RDONLY);
	char	*str;
	int		status = 0;
	int		i = 0;

	str = (char *)malloc(sizeof(char));
	while (i < 100)
	{
		status = get_next_line(fd, &str);

		if (status == 1)
			printf("%s\n", str);
		else
			printf("Error");
		i++;
	}
	return (0);
}
