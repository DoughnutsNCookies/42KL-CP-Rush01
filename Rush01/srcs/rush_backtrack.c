/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_backtrack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:40:39 by schuah            #+#    #+#             */
/*   Updated: 2022/08/25 20:13:20 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	get_max(int table[4][4])
{
	int	max;
	int	x;
	int	y;

	y = -1;
	max = 0;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			max += table[x][y];
	}
	return (max);
}

static int	find_best_box(int table[4][4])
{
	int		x;
	int		y;
	int		best;
	int		max_space;

	y = -1;
	max_space = 0;
	best = 0;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			best = find_box(table, (y * 4) + x, max_space, best);
	}
	return (best);
}

static void	put_and_check(int table[4][4], int opt, int xy)
{
	int	temp;

	if (opt == 1)
		table[xy / 4][xy % 4] = 1000;
	if (opt == 2)
		table[xy / 4][xy % 4] = 200;
	if (opt == 3)
		table[xy / 4][xy % 4] = 30;
	if (opt == 4)
		table[xy / 4][xy % 4] = 4;
	while (1)
	{
		temp = get_max(table);
		remove_dup(table);
		elimination(table);
		if (temp == get_max(table))
			break ;
	}
}

static int	find_next_best(int copy[4][4], int table[4][4],
	int best_pos, int input[16])
{
	int		i;
	char	*best_opt;

	i = -1;
	best_opt = ft_itoa(table[best_pos / 4][best_pos % 4]);
	while (++i < 4 && best_opt[i] != '\0')
	{
		while (best_opt[i] == '0' && best_opt[i] != '\0')
			i++;
		if (best_opt[i] == '\0')
			break ;
		copy_table(copy, table);
		if (bruteforce(table, input, best_opt[i] - 48, best_pos))
		{
			free(best_opt);
			return (1);
		}
		copy_table(table, copy);
	}
	free(best_opt);
	return (0);
}

int	bruteforce(int table[4][4], int input[16], int opt, int xy)
{
	int		best_pos;
	int		copy[4][4];

	if (opt == 0 && xy == 0)
	{
		solve_for_minmax(table, input);
		edge_constraint(table, input);
	}
	put_and_check(table, opt, xy);
	if (get_max(table) == 1234 * 4)
	{
		if (check_xy(table, input, -1, -1))
			return (1);
		else
			return (0);
	}
	best_pos = find_best_box(table);
	if (best_pos == 0)
		return (0);
	return (find_next_best(copy, table, best_pos, input));
}
