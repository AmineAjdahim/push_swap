/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:43:59 by majdahim          #+#    #+#             */
/*   Updated: 2021/07/11 17:43:54 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	three_numbers(char **a, int size)
{
	int		bignb;
	int		smallnb;

	bignb = max(a, size);
	smallnb = min(a, size);
	if (bignb == ft_atoi(a[2]) && smallnb == ft_atoi(a[1]))
		sa(a);
	if (bignb == ft_atoi(a[0]) && smallnb == ft_atoi(a[2]))
	{
		sa(a);
		rra(a, size);
	}
	if (bignb == ft_atoi(a[0]) && smallnb == ft_atoi(a[1]))
		ra(a, size);
	if (bignb == ft_atoi(a[1]) && smallnb == ft_atoi(a[0]))
	{
		sa(a);
		ra(a, size);
	}
	if (bignb == ft_atoi(a[1]) && smallnb == ft_atoi(a[2]))
		rra(a, size);
}

void	two_or_three(char **a, int size)
{
	if (size == 2)
		sa(a);
	if (size == 3)
		three_numbers(a, size);
}

void	five_numbers(char **a, char **b, int size)
{
	check_and_pb(a, b, size);
	check_and_pb(a, b, size - 1);
	two_or_three(a, size - 2);
	pa(a, b, size);
	pa(a, b, size);
}

void	four_or_five(char **a, char **b, int size)
{
	int		smallnumber;
	int		ps;

	smallnumber = min(a, size);
	ps = ft_pos(a, size, smallnumber);
	if (size == 4)
	{
		if (ps)
		{
			while (ps > 0)
			{
				ra(a, size);
				ps--;
			}
		}
		pb(a, b, size);
		two_or_three(a, size - 1);
		pa(a, b, size);
	}
	if (size == 5)
		five_numbers(a, b, size);
}

void	addelements(char **stack_a, int size, char **stack_b, char **argv)
{
	int		i;

	i = -1;
	while (++i < size)
		stack_a[i] = argv[i + 1];
	i = -1;
	while (++i < size)
		stack_b[i] = " ";
}
