/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-raki <yer-raki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:09:15 by yer-raki          #+#    #+#             */
/*   Updated: 2021/07/12 13:31:17 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"

void	check_big_pa(char **a, char **b, int size);
void	sa(char **a);
void	sb(char **b);
void	ra(char **a, int size);
void	rb(char **b, int elements_size);
void	rra(char **a, int elements_size);
void	rrb(char **b, int elements_size);
int		pb(char **a, char **b, int size);
void	pa(char **a, char **b, int size);
int		is_sorted(char **a, int size);
int		max(char **a, int size);
int		min(char **a, int size);
int		ft_pos(char **a, int size, int ps);
char	**sorted_stack(int size, char **a);
int		is_dup(char **a, int size);
void	check_big_pa(char **a, char **b, int size);
int		read_down(char **stack_a, int size, char *start, char *end);
int		read_top(char **stack_a, int size, char *start, char *end);
void	check_and_pb_more(char **a, char **b, int size);
void	two_or_three(char **a, int size);
void	four_or_five(char **a, char **b, int size);
void	check_and_pb(char **a, char **b, int size);
void	more(char **a, char **b, int size);
void	chinks(char **stack_a, char **stack_b, char *start, char *end);
void	one_hundred(char **a, char **b, int size, int step);
void	five_numbers(char **a, char **b, int size);
void	addelements(char **stack_a, int size, char **stack_b, char **argv);
int		get(int *size);
int		is_notnum(char *a);
int		check_dup(char **a, int size);
int		is_bigint(char *str);
int		check_args(char **a, int size);

#endif
