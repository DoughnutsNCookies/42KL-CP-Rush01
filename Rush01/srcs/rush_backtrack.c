/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_backtrack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:40:39 by schuah            #+#    #+#             */
/*   Updated: 2022/08/26 13:17:08 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	get_max(int table[B_MAX][B_MAX])
{
	int	max;
	int	x;
	int	y;

	y = -1;
	max = 0;
	while (++y < B_MAX)
	{
		x = -1;
		while (++x < B_MAX)
			max += table[x][y];
	}
	return (max);
}

static int	find_best_box(int table[B_MAX][B_MAX])
{
	int		x;
	int		y;
	int		best;
	int		max_space;

	y = -1;
	max_space = 0;
	best = 0;
	while (++y < B_MAX)
	{
		x = -1;
		while (++x < B_MAX)
			best = find_box(table, (y * B_MAX) + x, max_space, best);
	}
	return (best);
}

static void	put_and_check(int table[B_MAX][B_MAX], int opt, int xy)
{
	int	temp;
	int	start;
	int	i;

	i = -1;
	start = START;
	while (++i < B_MAX)
	{
		if (opt == i + 1 && opt != 0)
			table[xy / B_MAX][xy % B_MAX] = start;
		start = reduce_start(start);
	}
	while (1)
	{
		temp = get_max(table);
		remove_dup(table);
		elimination(table);
		if (temp == get_max(table))
			break ;
	}
}

static int	find_next_best(int copy[B_MAX][B_MAX], int table[B_MAX][B_MAX],
	int best_pos, int input[I_MAX])
{
	int		i;
	char	*best_opt;

	i = -1;
	best_opt = ft_itoa(table[best_pos / B_MAX][best_pos % B_MAX]);
	while (++i < B_MAX && best_opt[i] != '\0')
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

int	bruteforce(int table[B_MAX][B_MAX], int input[I_MAX], int opt, int xy)
{
	int		best_pos;
	int		copy[B_MAX][B_MAX];

	if (opt == 0 && xy == 0)
	{
		solve_for_minmax(table, input);
		edge_constraint(table, input);
	}
	put_and_check(table, opt, xy);
	if (get_max(table) == N * B_MAX)
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
