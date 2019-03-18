/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorelei <clorelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:17:30 by clorelei          #+#    #+#             */
/*   Updated: 2019/03/18 17:44:11 by clorelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_solve.h"
#include "../includes/ft_io.h"
#include "../includes/ft_std.h"

void	draw(int **dp, t_map map)
{
}

int	valid_char(char c, t_map map)
{
	return (c == map.empty || c == map.obst || c == map.full);
}

int	**create_dp(t_map map)
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
	row = 0;
	return (dp);
}

int	solve(t_map map)
{
	int		**dp;
	size_t	row;
	size_t	col;

	dp = create_dp(map);
	if (!dp)
		return (error("map error\n"));
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
	for (size_t i = 0; i < map.height; i++)
	{
		for (size_t j = 0; j < map.width; j++)
			printf("%d", dp[i][j]);
		printf("\n");
	}
	printf("\n");
	return (0);
}
