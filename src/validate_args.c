/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelgasim <gelgasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:09:32 by gelgasim          #+#    #+#             */
/*   Updated: 2026/11/10 10:10:10 by gelgasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validate_args(int argc, char **argv, int start)
{
	int	i;
	int	j;

	i = start;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
			return (1);
		while (argv[i][j] >= '0' && argv[i][j] <= '9')
			j++;
		if (argv[i][j] != '\0')
			return (1);
		i++;
	}
	return (0);
}
