/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:49:53 by majdahim          #+#    #+#             */
/*   Updated: 2021/07/11 17:43:29 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_dup(char **a, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(a[i]) == ft_atoi(a[j]))
			{
				write(1, "ERROR\n", ft_strlen("ERROR\n"));
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_big_pa1(int ps, int size, char **b, int us_size)
{
	if (ps >= us_size / 2)
	{
		ps = us_size - ps;
		while (ps > 0)
		{
			rrb(b, size);
			ps--;
		}
	}
	else
	{
		while (ps > 0)
		{
			rb(b, size);
			ps--;
		}
	}
}

void	check_big_pa(char **a, char **b, int size)
{
	int		i;
	int		us_size;
	int		ps;
	int		bignum;

	i = 0;
	us_size = size;
	while (i < size)
	{
		bignum = max(b, size);
		ps = ft_pos(b, size, bignum);
		check_big_pa1(ps, size, b, us_size);
		pa(a, b, size);
		us_size--;
		i++;
	}
}

int	read_down(char **stack_a, int size, char *start, char *end)
{
	int		i;
	int		ps;

	i = size - 1;
	while (i > 0)
	{
		if (stack_a[i][0] != ' ' && ft_atoi(stack_a[i]) >= ft_atoi(start)
				&& ft_atoi(stack_a[i]) <= ft_atoi(end))
		{
			ps = ft_pos(stack_a, size, ft_atoi(stack_a[i]));
			return (size - ps);
		}
		i--;
	}
	return (-1);
}

int	read_top(char **stack_a, int size, char *start, char *end)
{
	int		i;
	int		ps;

	i = 0;
	ps = 0;
	while (i < size)
	{
		if (stack_a[i][0] != ' ' && ft_atoi(stack_a[i]) >= ft_atoi(start)
				&& ft_atoi(stack_a[i]) <= ft_atoi(end))
		{
			ps = ft_pos(stack_a, size, ft_atoi(stack_a[i]));
			return (ps);
		}
		i++;
	}
	return (-1);
}
