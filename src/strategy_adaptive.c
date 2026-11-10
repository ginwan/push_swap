/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_adaptive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:04:12 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 10:05:03 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_strategy(t_stacks *s)
{
	float	disorder;

	disorder = count_disorder(s->a, s->size_a);
	if (disorder < 0.2)
	{
		s->bench.complexity = "O(n²)";
		min_extract(s);
	}
	else if (disorder < 0.5)
	{
		s->bench.complexity = "O(n√n)";
		block_sort(s);
	}
	else
	{
		s->bench.complexity = "O(n log n)";
		radix_sort(s, 0);
	}
}
