/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:50:08 by majdahim          #+#    #+#             */
/*   Updated: 2021/07/11 19:51:28 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	check_and_pb(char **a, char **b, int size)
{
	int		smallnumber;
	int		ps;

	smallnumber = min(a, size);
	ps = ft_pos(a, size, smallnumber);
	if (ps <= 2)
	{
		while (ps > 0)
		{
			ra(a, size);
			ps--;
		}
	}
	else if (ps > 2)
	{
		while (ps < size)
		{
			rra(a, size);
			ps++;
		}
	}
	pb(a, b, size);
}

void	chinks01(int ps_top, int ps_down, char **stack_a, int size)
{
	if (ps_top > ps_down && ps_down != -1)
	{
		while (ps_down > 0)
		{
			rra(stack_a, size);
			ps_down--;
		}
	}
	else if (ps_top != -1)
	{
		while (ps_top > 0)
		{
			ra(stack_a, size);
			ps_top--;
		}
	}
}

void	chinks(char **stack_a, char **stack_b, char *start, char *end)
{
	int		loop;
	int		ps_top;
	int		ps_down;
	int		size;

	size = get(NULL);
	loop = 0;
	while (loop < size)
	{
		ps_top = read_top(stack_a, size, start, end);
		ps_down = read_down(stack_a, size, start, end);
		chinks01(ps_top, ps_down, stack_a, size);
		if (ps_top != -1 || ps_down != -1)
			pb(stack_a, stack_b, size);
		loop++;
	}
}

void	one_hundred(char **a, char **b, int size, int step)
{
	char	**sorted;
	int		start;
	int		end;

	sorted = sorted_stack(size, a);
	start = 0;
	end = step;
	while (start < size)
	{
		chinks(a, b, sorted[start], sorted[end]);
		if (end + step - 1 > size)
		{
			start += step;
			end = size - 1;
		}
		else
		{
			start += step;
			end = start + step;
		}
	}
	free(sorted);
	check_big_pa(a, b, size);
}

int	main(int argc, char **argv)
{
	char	**stack_a;
	char	**stack_b;
	int		size;

	get(&size);
	size = argc - 1;
	stack_a = (char **)malloc((size + 1) * sizeof(char *));
	stack_b = (char **)malloc((size + 1) * sizeof(char *));
	addelements(stack_a, size, stack_b, argv);
	if (!check_args(stack_a, size))
		return (write(2, "Error\n", 6));
	if (is_sorted(stack_a, size))
		return (0);
	if (size <= 3)
		two_or_three(stack_a, size);
	else if (size == 4 || size == 5)
		four_or_five(stack_a, stack_b, size);
	else if (size >= 6 && size <= 99)
		more(stack_a, stack_b, size);
	else if (size >= 99 && size <= 100)
		one_hundred(stack_a, stack_b, size, 8);
	else if (size >= 101)
		one_hundred(stack_a, stack_b, size, 30);
	return (0);
}
