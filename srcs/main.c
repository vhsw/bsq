/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorelei <clorelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:28:06 by clorelei          #+#    #+#             */
/*   Updated: 2019/03/20 18:58:42 by scold            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "../includes/ft_map.h"
#include "../includes/ft_std.h"
#include "../includes/ft_extend.h"
#include "../includes/ft_solve.h"
#include "../includes/ft_io.h"
#include "../includes/ft_string.h"

t_map g_map;

int	process_head(int desc)
{
	char	buf;
	char	num[11];
	int		i;

	g_map.height = 0;
	g_map.width = 0;
	i = -1;
	while ((read(desc, &buf, 1) == 1) && buf >= '0' && buf <= '9')
		num[++i] = buf;
	num[++i] = '\0';
	g_map.height = (ft_atoi(num));
	g_map.empty = buf;
	if ((read(desc, &num, 3) == 3) && num[2] == '\n')
	{
		g_map.obst = num[0];
		g_map.full = num[1];
	}
	else
		g_map.height = 0;
	return (EXIT_SUCCESS);
}

int	process_data(int desc)
{
	size_t	line;
	size_t	col;
	size_t	size;
	char	buf;

	process_head(desc);
	line = 0;
	size = 1;
	g_map.field = (char**)malloc(sizeof(char*) * g_map.height);
	while (line < g_map.height)
	{
		g_map.field[line] = (char*)malloc(sizeof(char) * size);
		col = 0;
		while ((read(desc, &buf, 1) > 0) && buf != '\n')
		{
			if (col >= size - 1)
				g_map.field[line] = ft_extend(&g_map.field[line], size *= 2);
			g_map.field[line][col++] = buf;
		}
		g_map.field[line++][col] = '\0';
		g_map.width = (g_map.width) ? g_map.width : col;
		g_map.height = (g_map.width == col) ? g_map.height : 0;
	}
	g_map.height = ((read(desc, &buf, 1) <= 0)) ? g_map.height : 0;
	return (g_map.height != 0 ? solve(g_map) : error(MAP_ERROR));
}

int	process_file(char *path)
{
	int		desc;
	char	dummy;

	desc = open(path, O_RDONLY);
	if (read(desc, &dummy, 1) <= 0)
	{
		close(desc);
		return (error(FILE_ERROR));
	}
	desc = open(path, O_RDONLY);
	process_data(desc);
	close(desc);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	int i;

	if (argc < 2)
	{
		process_data(STDIN_FILENO);
	}
	else
	{
		i = 0;
		while (++i < argc)
			if (ft_strcmp(argv[i], "-") == 0)
				process_data(STDIN_FILENO);
			else
				process_file(argv[i]);
	}
	return (EXIT_SUCCESS);
}
