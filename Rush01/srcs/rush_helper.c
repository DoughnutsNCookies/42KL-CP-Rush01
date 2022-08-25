/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:51:57 by schuah            #+#    #+#             */
/*   Updated: 2022/08/25 20:12:10 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	print_table(int table[4][4], int input[16])
{
	ft_printf("\n   |  %4d  |  %4d  |  %4d  |  %4d  |\n",
		input[0], input[1], input[2], input[3]);
	ft_printf("------------------------------------------- X\n");
	ft_printf("%d  |  %4d  |  %4d  |  %4d  |  %4d  |  %d\n",
		input[8], table[0][0], table[0][1], table[0][2], table[0][3],
		input[12]);
	ft_printf("%d  |  %4d  |  %4d  |  %4d  |  %4d  |  %d\n",
		input[9], table[1][0], table[1][1], table[1][2], table[1][3],
		input[13]);
	ft_printf("%d  |  %4d  |  %4d  |  %4d  |  %4d  |  %d\n",
		input[10], table[2][0], table[2][1], table[2][2], table[2][3],
		input[14]);
	ft_printf("%d  |  %4d  |  %4d  |  %4d  |  %4d  |  %d\n",
		input[11], table[3][0], table[3][1], table[3][2], table[3][3],
		input[15]);
	ft_printf("-------------------------------------------\n");
	ft_printf("   Y  %4d  |  %4d  |  %4d  |  %4d  |\n\n",
		input[4], input[5], input[6], input[7]);
}

void	copy_table(int copy[4][4], int table[4][4])
{
	int	x;
	int	y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			copy[y][x] = table[y][x];
	}
}

void	remove_dup(int table[4][4])
{
	int	x;
	int	y;
	int	changed;

	y = -1;
	changed = 0;
	while (++y < 4 && changed == 0)
	{
		x = -1;
		while (++x < 4)
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

void	elimination(int table[4][4])
{
	int	x;
	int	y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (mto_pos(table[y][x]) && check_single(table[y][x], table, x, y))
			{
				table[y][x] = check_single(table[y][x], table, x, y);
			}
		}
	}
}

void	edge_constraint(int table[4][4], int input[16])
{
	int	x;
	int	y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (mto_pos(table[y][x]) == 0)
				continue ;
			table[y][x] = remove_option(table[y][x], input[x], y);
			table[y][x] = remove_option(table[y][x], input[x + 4], 3 - y);
			table[y][x] = remove_option(table[y][x], input[y + 8], x);
			table[y][x] = remove_option(table[y][x], input[y + 12], 3 - x);
		}
	}
}
