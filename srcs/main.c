/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorelei <clorelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:28:06 by clorelei          #+#    #+#             */
/*   Updated: 2019/03/18 15:13:27 by clorelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/ft_io.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "../includes/ft_map.h"
#include "../includes/ft_std.h"
#include "../includes/ft_extend.h"

t_map	process_head(int desc)
{
	char	buf;
	char	num[11];
	t_map	map;
	int		i;
	int		size;

	map = g_default_map;
	i = -1;
	while (read(desc, &buf, 1) && buf >= '0' && buf <= '9')
		num[++i] = buf;
	num[++i] = '\0';
	map.height = (ft_atoi(num));
	if (!read(desc, &buf, 1))
		map.empty = buf;
	if (!read(desc, &buf, 1))
		map.obstacle = buf;
	if (!read(desc, &buf, 1))
		map.full = buf;
	if (!read(desc, &buf, 1) || buf != '\n')
		map.height = 0;
	return (map);
}

int		process_data(int desc)
{
	t_map	map;
	int		line;
	int		col;
	size_t	size;
	char	buf;

	map = process_head(desc);
	line = -1;
	size = 1;
	map.field = (char**)malloc(sizeof(char*) * map.height);
	while (++line < map.height)
	{
		map.field[line] = malloc(sizeof(char) * size);
		col = 0;
		while (read(desc, &buf, 1) && buf != '\n')
		{
			if (col >= size)
				map.field[line] = ft_extend(&map.field[line], size *= 2);
			map.field[line][col++] = buf;
		}
		map.field[line][col] = '\0';
	}
	if (map.height == 0)
		return (error("map error\n"));
	return (0);
}

int		process_file(char *path)
{
	int desc;

	desc = open(path, O_RDONLY);
	if (desc < 0)
		return (error("wrong file path\n"));
	process_data(desc);
	close(desc);
	return (0);
}

int		main(int argc, char *argv[])
{
	int i;

	if (argc < 2)
		process_data(0);
	else
	{
		i = 0;
		while (++i < argc)
		{
			printf("argv[%d] = %s\n", i, argv[i]);
			process_file(argv[i]);
		}
	}
	return (0);
}
