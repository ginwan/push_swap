/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:13:22 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 10:43:05 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_strategy(t_flags *f, char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		f->strategy = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		f->strategy = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		f->strategy = COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		f->strategy = ADAPTIVE;
	else
		return (1);
	return (0);
}

int	parse_flags(t_flags *f, int argc, char **argv, int *start)
{
	int	i;

	i = 1;
	while (i < argc && ft_strncmp(argv[i], "--", 2) == 0)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			f->bench = 1;
		else if (set_strategy(f, argv[i]) != 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		(*start)++;
		i++;
	}
	return (0);
}
