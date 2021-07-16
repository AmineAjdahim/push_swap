/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:40:45 by majdahim          #+#    #+#             */
/*   Updated: 2021/07/11 19:50:41 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char		*p;
	int			i;

	p = malloc(count * size);
	if (!(p))
		return ((void *)p);
	i = 0;
	while (i < ((int)(count * size)))
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
