/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:00:55 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 10:49:07 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_num;
	int	bits;

	max_num = size - 1;
	bits = 0;
	while (max_num > 0)
	{
		max_num /= 2;
		bits++;
	}
	return (bits);
}

static void	sort_bit(t_stacks *s, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((s->a[0] >> bit) & 1) == 0)
			pb(s);
		else
			ra(s);
		i++;
	}
	while (s->size_b > 0)
		pa(s);
}

void	radix_sort(t_stacks *s, int bit)
{
	int	max_bits;

	if (convert_to_rank(s))
		return ;
	max_bits = get_max_bits(s->size_a);
	while (bit < max_bits)
	{
		sort_bit(s, bit, s->size_a);
		bit++;
	}
}
