/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginwan <ginwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:51:19 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 11:51:36 by ginwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double disorder)
{
	int	value;

	value = (int)(disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(value / 100, 2);
	ft_putstr_fd(".", 2);
	if (value % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(value % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_moves(t_stacks *s)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(s->bench.sa, 2);
	ft_putstr_fd("\tsb: ", 2);
	ft_putnbr_fd(s->bench.sb, 2);
	ft_putstr_fd("\tss: ", 2);
	ft_putnbr_fd(s->bench.ss, 2);
	ft_putstr_fd("\tpa: ", 2);
	ft_putnbr_fd(s->bench.pa, 2);
	ft_putstr_fd("\tpb: ", 2);
	ft_putnbr_fd(s->bench.pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(s->bench.ra, 2);
	ft_putstr_fd("\trb: ", 2);
	ft_putnbr_fd(s->bench.rb, 2);
	ft_putstr_fd("\trr: ", 2);
	ft_putnbr_fd(s->bench.rr, 2);
	ft_putstr_fd("\trra: ", 2);
	ft_putnbr_fd(s->bench.rra, 2);
	ft_putstr_fd("\trrb: ", 2);
	ft_putnbr_fd(s->bench.rrb, 2);
	ft_putstr_fd("\trrr: ", 2);
	ft_putnbr_fd(s->bench.rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_benchmark(t_stacks *s)
{
	int	total_ops;

	total_ops = s->bench.sa + s->bench.sb + s->bench.ss
		+ s->bench.pa + s->bench.pb
		+ s->bench.ra + s->bench.rb + s->bench.rr
		+ s->bench.rra + s->bench.rrb + s->bench.rrr;
	print_disorder(s->bench.disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(s->bench.strategy, 2);
	ft_putstr_fd("\nComplexity: ", 2);
	ft_putstr_fd(s->bench.complexity, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops, 2);
	ft_putstr_fd("\n", 2);
	print_moves(s);
}
