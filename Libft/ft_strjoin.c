/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:07:03 by majdahim          #+#    #+#             */
/*   Updated: 2021/07/11 19:48:43 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len1;
	int		len;

	if (!(s2) || !(s1))
		return (0);
	len = ft_strlen((char *)s1);
	len1 = ft_strlen((char *)s2);
	res = malloc(len + len1 + 1);
	if (!res)
		return (0);
	ft_strcpy(res, (char *)s1);
	ft_strcpy(&res[len], (char *)s2);
	return (res);
}
