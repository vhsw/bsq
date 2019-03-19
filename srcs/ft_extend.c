/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorelei <clorelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:41:17 by clorelei          #+#    #+#             */
/*   Updated: 2019/03/19 12:51:58 by clorelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_extend(char **p, size_t size)
{
	char		*new;
	char		*old;
	size_t		i;

	new = malloc(size);
	if (!new)
		return (NULL);
	old = *p;
	i = 0;
	while (i < size / 2)
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}
