/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorelei <clorelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:17:20 by clorelei          #+#    #+#             */
/*   Updated: 2019/03/18 14:53:46 by clorelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

typedef struct	s_map {
	int			height;
	int			width;
	char		empty;
	char		obstacle;
	char		full;
	char		**field;
}				t_map;

t_map g_default_map = {0, 0, '\0', '\0', '\0', NULL};

#endif
