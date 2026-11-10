/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 09:57:31 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 11:12:15 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	char	*strategy;
	char	*complexity;
	double	disorder;
}	t_bench;

typedef struct s_flags
{
	int	bench;
	int	strategy;
}	t_flags;

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	t_bench	bench;
}	t_stacks;

float	count_disorder(int *a, int size);
void	ra(t_stacks *s);
void	rb(t_stacks *s);
void	rr(t_stacks *s);
void	rra(t_stacks *s);
void	rrb(t_stacks *s);
void	rrr(t_stacks *s);
void	pb(t_stacks *s);
void	pa(t_stacks *s);
void	sa(t_stacks *s);
void	sb(t_stacks *s);
void	ss(t_stacks *s);
int		find_index(int *s, int size, int is_max);
int		*rank_numbers(int *a, int size_a);
void	min_extract(t_stacks *s);
void	block_sort(t_stacks *s);
void	max_extract(t_stacks *s);
void	radix_sort(t_stacks *s, int bit);
void	adaptive_strategy(t_stacks *s);
void	print_benchmark(t_stacks *s);
void	push_swap(t_stacks *s, t_flags *flags);
int		parse_flags(t_flags *f, int argc, char **argv, int *start);
int		check_duplicates(int *a, int size);
int		convert_to_rank(t_stacks *s);
int		validate_args(int argc, char **argv, int start);

#endif