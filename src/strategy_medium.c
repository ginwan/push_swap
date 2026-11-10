/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:59:10 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 10:53:19 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_block_size(int size)
{
	int	block;

	block = 1;
	while (block * block < size)
		block++;
	return (block * 2);
}

void	block_sort(t_stacks *s)
{
	int	block;
	int	low;
	int	pushed;

	if (convert_to_rank(s))
		return ;
	block = get_block_size(s->size_a);
	low = 0;
	while (s->size_a > 0)
	{
		pushed = 0;
		while (pushed < block && s->size_a > 0)
		{
			if (s->a[0] >= low && s->a[0] < low + block)
			{
				pb(s);
				pushed++;
			}
			else
				ra(s);
		}
		low += block;
	}
	max_extract(s);
}
