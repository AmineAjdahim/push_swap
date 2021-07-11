/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:49:34 by majdahim          #+#    #+#             */
/*   Updated: 2021/07/11 12:52:22 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_sorted(char **a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (ft_atoi(a[i]) > ft_atoi(a[i + 1]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	max(char **a, int size)
{
	int		max;
	int		i;

	max = ft_atoi(a[0]);
	i = 0;
	while (i < size && a[i][0] != ' ' && a[i][0] != '+')
	{
		if (ft_atoi(a[i]) >= max)
			max = ft_atoi(a[i]);
		i++;
	}
	return (max);
}

int	min(char **a, int size)
{
	int		i;
	int		b;

	i = 0;
	b = ft_atoi(a[0]);
	while (i < size && a[i][0] != ' ')
	{
		if (ft_atoi(a[i]) <= b)
			b = ft_atoi(a[i]);
		i++;
	}
	return (b);
}

int	ft_pos(char **a, int size, int ps)
{
	int		i;

	i = -1;
	while (++i < size)
		if (ft_atoi(a[i]) == ps && a[i][0] != ' ' && a[i][0] != '+')
			return (i);
	return (-1);
}

char	**sorted_stack(int size, char **a)
{
	char	**array;
	int		i;
	int		j;
	char	*temp;

	array = malloc(sizeof(char **) * size);
	i = -1;
	while (++i < size)
		array[i] = a[i];
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < (size))
		{
			if (ft_atoi(array[i]) > ft_atoi(array[j]))
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return (array);
}
