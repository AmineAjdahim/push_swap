/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:50:28 by majdahim          #+#    #+#             */
/*   Updated: 2021/07/11 12:50:30 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sa(char **a)
{
	char	*temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(char **b)
{
	char	*temp;

	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	write(1, "sb\n", 3);
}

void	ra(char **a, int size)
{
	char	*temp;
	int		i;

	temp = a[0];
	i = 0;
	while (i < size - 1 && a[i + 1][0] != ' ')
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = temp;
	write(1, "ra\n", 3);
}

void	rb(char **b, int elements_size)
{
	char	*t;
	int		i;

	t = b[0];
	i = 0;
	while (i < elements_size - 1 && b[i + 1][0] != ' ')
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = t;
	write(1, "rb\n", 3);
}

void	rra(char **a, int elements_size)
{
	int		index;
	char	*t;
	int		i;

	index = 0;
	while (index < elements_size && a[index][0] != ' ')
		index++;
	t = a[index - 1];
	i = index;
	while (--i > 0)
		a[i] = a[i - 1];
	a[0] = t;
	write(1, "rra\n", 4);
}
