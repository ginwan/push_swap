/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:13:01 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 10:04:53 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// push a[0] to b[0]
void	pb(t_stacks *s)
{
	int	i;

	if (s->size_a < 1)
		return ;
	i = s->size_b;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = s->a[0];
	i = 0;
	while (i < s->size_a - 1)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->size_a--;
	s->size_b++;
	s->bench.pb++;
	ft_putstr("pb\n");
}

// push b[0] to a[0]
void	pa(t_stacks *s)
{
	int	i;

	if (s->size_b < 1)
		return ;
	i = s->size_a;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = s->b[0];
	i = 0;
	while (i < s->size_b - 1)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->size_b--;
	s->size_a++;
	s->bench.pa++;
	ft_putstr("pa\n");
}
