/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 03:23:00 by majdahim          #+#    #+#             */
/*   Updated: 2021/07/11 19:49:43 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char			*temp;
	unsigned long	len;

	len = ft_strlen((char *)src);
	temp = (char *)malloc(len + 1);
	if (!(temp))
		return (0);
	memcpy(temp, (char *)src, len);
	temp[len] = '\0';
	return (temp);
}
