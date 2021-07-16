/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:55:45 by majdahim          #+#    #+#             */
/*   Updated: 2021/07/11 18:56:06 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	get(int *size)
{
	static int	*_size;

	if (size)
		_size = size;
	return (*_size);
}

int	is_notnum(char *a)
{
	int	i;
	int	counter;

	i = ft_strlen(a) - 1;
	counter = 0;
	while (i >= 0)
	{
		if (!ft_isdigit(a[i]))
		{
			if (a[i] == '-')
			{
				counter++;
				if (i > 0 || counter > 1)
					return (1);
			}
			else
			{
				return (1);
			}
		}
		i--;
	}
	return (0);
}

int	check_dup(char **a, int size)
{
	int	i;
	int	j;
	int	size_a;
	int	size_b;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			size_a = ft_strlen(a[i]);
			size_b = ft_strlen(a[j]);
			if (size_a == size_b && ft_strncmp(a[i], a[j], size_a) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_bigint(char *str)
{
	int		i;
	char	*str_back;
	int		size_a;
	int		size_b;

	i = ft_atoi(str);
	size_a = ft_strlen(str);
	str_back = ft_itoa(i);
	size_b = ft_strlen(str_back);
	if (size_a != size_b)
	{
		free(str_back);
		return (1);
	}
	else
	{
		if (ft_strncmp(str, str_back, size_b) != 0)
		{
			free(str_back);
			return (1);
		}
	}
	free(str_back);
	return (0);
}

int	check_args(char **a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (is_notnum(a[i]) || is_bigint(a[i]) || check_dup(a, size))
			return (0);
		i++;
	}
	return (1);
}
