/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:50:47 by majdahim          #+#    #+#             */
/*   Updated: 2021/07/11 17:44:20 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	pb(char **a, char **b, int size)
{
	int		i;

	i = size + 1;
	while (--i > 0)
		b[i] = b[i - 1];
	b[0] = a[0];
	i = 0;
	while (i < size - 1 && a[i + 1][0] != ' ')
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = " ";
	write(1, "pb\n", 3);
	return (size);
}

void	pa(char **a, char **b, int size)
{
	int		i;

	i = size;
	while (--i > 0)
		a[i] = a[i - 1];
	a[0] = b[0];
	i = 0;
	while (i < size - 1 && b[i + 1][0] != ' ')
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = " ";
	write(1, "pa\n", 3);
}

void	rrb(char **b, int elements_size)
{
	int		index;
	char	*t;
	int		i;

	index = 0;
	while (index < elements_size && b[index][0] != ' ')
		index++;
	t = b[index - 1];
	i = index;
	while (--i > 0)
		b[i] = b[i - 1];
	b[0] = t;
	write(1, "rrb\n", 4);
}

void	more(char **a, char **b, int size)
{
	int		bb;

	check_and_pb_more(a, b, size);
	bb = 0;
	while (bb++ <= size - 1)
		pa(a, b, size);
}

void	check_and_pb_more(char **a, char **b, int size)
{
	int		bbbbb;
	int		smallnumber;
	int		ps;

	bbbbb = 0;
	while (bbbbb <= size - 1)
	{
		smallnumber = min(a, size);
		ps = ft_pos(a, size, smallnumber);
		if (ps)
		{
			while (ps > 0)
			{
				ra(a, size);
				ps--;
			}
		}
		pb(a, b, size);
		bbbbb++;
	}
}
