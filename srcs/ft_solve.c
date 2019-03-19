/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorelei <clorelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:17:30 by clorelei          #+#    #+#             */
/*   Updated: 2019/03/19 18:32:43 by clorelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_solve.h"
#include "../includes/ft_io.h"
#include "../includes/ft_std.h"
#include <unistd.h>

void	draw(t_map map, t_area a)
{
	size_t	row;
	size_t	col;
	char	res;

	row = 0;
	while (row < map.height)
	{
		col = 0;
		while (col < map.width)
		{
			if (row <= a.m_row && row >= (a.m_row - a.m_siz + 1) &&
				col <= a.m_col && col >= (a.m_col - a.m_siz + 1))
				res = map.full;
			else
				res = map.field[row][col];
			write(1, &res, 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int		valid_char(char c, t_map map)
{
	return (c == map.empty || c == map.obst);
}

int		**create_dp(t_map map)
{
	int		**dp;
	size_t	row;
	size_t	col;

	dp = (int**)malloc(sizeof(int*) * map.height);
	row = 0;
	while (row < map.height)
	{
		dp[row] = (int*)malloc(sizeof(int) * map.width);
		col = 0;
		while (col < map.width)
			if (valid_char(map.field[row][col], map))
			{
				if (row == 0 || col == 0)
					dp[row][col] = map.field[row][col] != map.obst;
				else
					dp[row][col] = 0;
				col++;
			}
			else
				return (NULL);
		row++;
	}
	return (dp);
}

t_area	find_max(int **dp, t_map map)
{
	size_t	row;
	size_t	col;
	t_area	area;

	row = 0;
	area.m_siz = 0;
	while (row < map.height)
	{
		col = 0;
		while (col < map.width)
		{
			if (dp[row][col] > area.m_siz)
			{
				area.m_row = row;
				area.m_col = col;
				area.m_siz = dp[row][col];
			}
			col++;
		}
		row++;
	}
	return (area);
}

int		solve(t_map map)
{
	int		**dp;
	size_t	row;
	size_t	col;

	dp = create_dp(map);
	if (!dp)
		return (error(MAP_ERROR));
	row = 1;
	while (row < map.height)
	{
		col = 1;
		while (col < map.width)
		{
			dp[row][col] = ((map.field[row][col] != map.obst) *
							(min3(dp[row - 1][col], dp[row][col - 1],
							dp[row - 1][col - 1]) + 1));
			col++;
		}
		row++;
	}
	draw(map, find_max(dp, map));
	return (EXIT_SUCCESS);
}
