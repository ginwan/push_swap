/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:12:36 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 10:41:01 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// swap the top two elements of one stack
static void	swap_stack(int *stack, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

// sa: swap a
void	sa(t_stacks *s)
{
	swap_stack(s->a, s->size_a);
	s->bench.sa++;
	ft_putstr("sa\n");
}

// sb: swap b
void	sb(t_stacks *s)
{
	swap_stack(s->b, s->size_b);
	s->bench.sb++;
	ft_putstr("sb\n");
}

// ss: swap both stacks
void	ss(t_stacks *s)
{
	swap_stack(s->a, s->size_a);
	swap_stack(s->b, s->size_b);
	s->bench.ss++;
	ft_putstr("ss\n");
}
