/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:51:57 by schuah            #+#    #+#             */
/*   Updated: 2022/08/26 13:05:29 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	print_last_input(int input[I_MAX], int y)
{
	int	i;

	if (y != B_MAX - 1)
		return ;
	i = 3;
	while (++i < B_MAX * 2)
		ft_printf("\t\t%d", input[i]);
	ft_printf("\n\n");
}

void	print_table(int table[B_MAX][B_MAX], int input[I_MAX])
{
	int	x;
	int	y;
	int	i;

	y = -1;
	i = -1;
	while (++y < B_MAX)
	{
		x = -1;
		if (y == 0)
		{
			while (++i < B_MAX)
				ft_printf("\t\t%d", input[i]);
			ft_printf("\n");
		}
		ft_printf("%d\t|\t", input[(B_MAX) + i]);
		while (++x < B_MAX)
			ft_printf("%d\t|\t", table[y][x]);
		ft_printf("%d\n", input[(B_MAX * 2) + i++]);
		print_last_input(input, y);
	}
}

void	remove_dup(int table[B_MAX][B_MAX])
{
	int	x;
	int	y;
	int	changed;

	y = -1;
	changed = 0;
	while (++y < B_MAX && changed == 0)
	{
		x = -1;
		while (++x < B_MAX)
		{
			if (mto_pos(table[y][x])
				&& check_removed(table[y][x], has_existing(table, x, y)) == 0)
			{
				table[y][x] -= has_existing(table, x, y);
				changed = 1;
			}
		}
		if (changed)
		{
			y = -1;
			changed = 0;
		}
	}
}

void	elimination(int table[B_MAX][B_MAX])
{
	int	x;
	int	y;

	y = -1;
	while (++y < B_MAX)
	{
		x = -1;
		while (++x < B_MAX)
			if (mto_pos(table[y][x]) && check_single(table[y][x], table, x, y))
				table[y][x] = check_single(table[y][x], table, x, y);
	}
}

void	edge_constraint(int table[B_MAX][B_MAX], int input[I_MAX])
{
	int	x;
	int	y;

	y = -1;
	while (++y < B_MAX)
	{
		x = -1;
		while (++x < B_MAX)
		{
			if (mto_pos(table[y][x]) == 0)
				continue ;
			table[y][x] = remove_option(table[y][x], input[x], y);
			table[y][x] = remove_option(table[y][x], input[x + B_MAX],
					B_MAX - 1 - y);
			table[y][x] = remove_option(table[y][x], input[y + (B_MAX * 2)], x);
			table[y][x] = remove_option(table[y][x], input[y + (B_MAX * 3)],
					B_MAX - 1 - x);
		}
	}
}
