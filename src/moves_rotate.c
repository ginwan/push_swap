/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:06:16 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 10:40:55 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate one stack: top to bottom
static void	rotate_stack(int *stack, int size)
{
	int	i;
	int	tmp;

	if (size < 2)
		return ;
	tmp = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = tmp;
}

// ra: rotate a
void	ra(t_stacks *s)
{
	rotate_stack(s->a, s->size_a);
	s->bench.ra++;
	ft_putstr("ra\n");
}

// rb: rotate b
void	rb(t_stacks *s)
{
	rotate_stack(s->b, s->size_b);
	s->bench.rb++;
	ft_putstr("rb\n");
}

// rr: rotate both stacks
void	rr(t_stacks *s)
{
	rotate_stack(s->a, s->size_a);
	rotate_stack(s->b, s->size_b);
	s->bench.rr++;
	ft_putstr("rr\n");
}
