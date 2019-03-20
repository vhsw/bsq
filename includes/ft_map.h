/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorelei <clorelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:17:20 by clorelei          #+#    #+#             */
/*   Updated: 2019/03/20 18:20:33 by scold            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

# include <stdlib.h>

typedef struct	s_map
{
	size_t		height;
	size_t		width;
	char		empty;
	char		obst;
	char		full;
	char		**field;
}				t_map;

typedef struct	s_area
{
	size_t		m_row;
	size_t		m_col;
	int			m_siz;
}				t_area;

# define MAP_ERROR "map error\n"
# define FILE_ERROR "map error\n"

#endif
