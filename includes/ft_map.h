/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorelei <clorelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:17:20 by clorelei          #+#    #+#             */
/*   Updated: 2019/03/18 17:42:34 by clorelei         ###   ########.fr       */
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

#endif
