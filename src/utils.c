/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:05:47 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 10:49:36 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find index min or max
int	find_index(int *s, int size, int is_max)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	if (size <= 0)
		return (-1);
	while (i < size)
	{
		if (is_max == 0)
		{
			if (s[i] < s[index])
				index = i;
		}
		else
		{
			if (s[i] > s[index])
				index = i;
		}
		i++;
	}
	return (index);
}

// extract the maximum index in b and push it in the stack a
void	max_extract(t_stacks *s)
{
	int	index;

	while (s->size_b > 0)
	{
		index = find_index(s->b, s->size_b, 1);
		while (index != 0)
		{
			if (index <= s->size_b / 2)
				rb(s);
			else
				rrb(s);
			index = find_index(s->b, s->size_b, 1);
		}
		pa(s);
	}
}

// rank numbers inside stack
int	*rank_numbers(int *a, int size_a)
{
	int	rank;
	int	i;
	int	j;
	int	*rank_arr;

	rank_arr = malloc(size_a * sizeof(int));
	if (!rank_arr)
		return (NULL);
	i = 0;
	while (i < size_a)
	{
		rank = 0;
		j = 0;
		while (j < size_a)
		{
			if (a[i] > a[j])
			{
				rank++;
			}
			j++;
		}
		rank_arr[i] = rank;
		i++;
	}
	return (rank_arr);
}

int	check_duplicates(int *a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (a[i] == a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	convert_to_rank(t_stacks *s)
{
	int	*rank;
	int	i;

	rank = rank_numbers(s->a, s->size_a);
	if (!rank)
		return (1);
	i = 0;
	while (i < s->size_a)
	{
		s->a[i] = rank[i];
		i++;
	}
	free(rank);
	return (0);
}
