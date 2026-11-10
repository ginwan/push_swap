/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:48:50 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/09 12:43:14 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// extract the minimum index in a and push it in the stack b
void	min_extract(t_stacks *s)
{
	int	index;

	while (s->size_a > 0)
	{
		index = find_index(s->a, s->size_a, 0);
		while (index != 0)
		{
			if (index <= s->size_a / 2)
				ra(s);
			else
				rra(s);
			index = find_index(s->a, s->size_a, 0);
		}
		pb(s);
	}
	while (s->size_b > 0)
		pa(s);
}
