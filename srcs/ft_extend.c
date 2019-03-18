/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorelei <clorelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:41:17 by clorelei          #+#    #+#             */
/*   Updated: 2019/03/18 15:00:43 by clorelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_extend(char **p, size_t old_size)
{
	char		*new;
	char		*old;
	size_t		i;

	new = malloc(old_size * 2);
	if (!new)
		return (NULL);
	old = *p;
	i = 0;
	while (i < old_size)
	{
		new[i] = old[i];
		i++;
	}
	return (new);
}
