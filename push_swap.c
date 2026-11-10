/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:26:35 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 10:17:31 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stacks *s, t_flags *flags)
{
	if (flags->strategy == SIMPLE)
	{
		s->bench.strategy = "Simple";
		s->bench.complexity = "O(n²)";
		min_extract(s);
	}
	else if (flags->strategy == MEDIUM)
	{
		s->bench.strategy = "Medium";
		s->bench.complexity = "O(n√n)";
		block_sort(s);
	}
	else if (flags->strategy == COMPLEX)
	{
		s->bench.strategy = "Complex";
		s->bench.complexity = "O(n log n)";
		radix_sort(s, 0);
	}
	else if (flags->strategy == ADAPTIVE)
	{
		s->bench.strategy = "Adaptive";
		adaptive_strategy(s);
	}
}
