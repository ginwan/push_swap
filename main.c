/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 08:55:42 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 10:34:16 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stacks(t_stacks *s, int size)
{
	s->size_a = size;
	s->size_b = 0;
	s->a = malloc(size * sizeof(int));
	s->b = malloc(size * sizeof(int));
	if (!s->a || !s->b)
	{
		free(s->a);
		free(s->b);
		return (1);
	}
	return (0);
}

static void	fill_stack(t_stacks *s, char **argv, int start)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	while (argv[i])
		s->a[j++] = ft_atoi(argv[i++]);
}

static int	check_input(t_stacks *s)
{
	if (check_duplicates(s->a, s->size_a))
	{
		ft_putstr_fd("Error\n", 2);
		free(s->a);
		free(s->b);
		return (1);
	}
	return (0);
}

static int	run_push_swap(int argc, char **argv, int start, t_flags *flags)
{
	t_stacks	s;

	if (init_stacks(&s, argc - start))
		return (1);
	fill_stack(&s, argv, start);
	ft_bzero(&s.bench, sizeof(s.bench));
	s.bench.disorder = count_disorder(s.a, s.size_a);
	if (check_input(&s))
		return (1);
	push_swap(&s, flags);
	if (flags->bench)
		print_benchmark(&s);
	free(s.a);
	free(s.b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_flags	flags;
	int		start;

	flags.bench = 0;
	flags.strategy = ADAPTIVE;
	start = 1;
	if (argc == 1)
		return (0);
	if (parse_flags(&flags, argc, argv, &start) != 0)
		return (1);
	if (argc == start)
		return (0);
	if (validate_args(argc, argv, start))
		return (write(2, "Error\n", 6), 1);
	return (run_push_swap(argc, argv, start, &flags));
}
