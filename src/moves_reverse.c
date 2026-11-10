/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:08:23 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 10:40:07 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// reverse rotate one stack: bottom to top
static void	reverse_rotate_stack(int *stack, int size)
{
	int	i;
	int	tmp;

	if (size < 2)
		return ;
	tmp = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}

void	rra(t_stacks *s)
{
	reverse_rotate_stack(s->a, s->size_a);
	s->bench.rra++;
	ft_putstr("rra\n");
}

void	rrb(t_stacks *s)
{
	reverse_rotate_stack(s->b, s->size_b);
	s->bench.rrb++;
	ft_putstr("rrb\n");
}

void	rrr(t_stacks *s)
{
	reverse_rotate_stack(s->a, s->size_a);
	reverse_rotate_stack(s->b, s->size_b);
	s->bench.rrr++;
	ft_putstr("rrr\n");
}
