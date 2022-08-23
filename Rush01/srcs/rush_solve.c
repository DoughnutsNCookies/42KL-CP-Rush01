/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:54:27 by schuah            #+#    #+#             */
/*   Updated: 2022/08/23 22:05:21 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	solve_for_minmax(int table[4][4], int input[16])
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if (input[i] == 4)
		{
			if (i <= 3)
			{
				table[0][i % 4] = 2;
				table[1][i % 4] = 4;
				table[2][i % 4] = 8;
				table[3][i % 4] = 16;
			}
			if (i >= 4 && i <= 7)
			{
				table[3][i % 4] = 2;
				table[2][i % 4] = 4;
				table[1][i % 4] = 8;
				table[0][i % 4] = 16;
			}
			if (i >= 8 && i <= 11)
			{
				table[i % 4][0] = 2;
				table[i % 4][1] = 4;
				table[i % 4][2] = 8;
				table[i % 4][3] = 16;
			}
			if (i >= 12 && i <= 15)
			{
				table[i % 4][3] = 2;
				table[i % 4][2] = 4;
				table[i % 4][1] = 8;
				table[i % 4][0] = 16;
			}
		}
		if (input[i] == 1)
		{
			if (i <= 3)
				table[0][i] = 16;
			else if (i >= 4 && i <= 7)
				table[3][i - 4] = 16;
			else if (i >= 8 && i <= 11)
				table[i - 8][0] = 16;
			else if (i >= 12 && i <= 15)
				table[i - 12][3] = 16;
		}
	}
}

static void	constraint_propagation(int table[4][4], int input[16])
{
	int	x;
	int	y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			
		}
	}
}

int	solve(int table[4][4], int input[16])
{	
	solve_for_minmax(table, input);
	constraint_propagation(table, input);
	print_table(table, input);
	return (0);
}
