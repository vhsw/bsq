/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorelei <clorelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 19:15:47 by clorelei          #+#    #+#             */
/*   Updated: 2019/03/18 11:49:13 by clorelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_string.h"

int		message(char *msg)
{
	write(1, msg, ft_strlen(msg));
	return (0);
}

int		error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}
