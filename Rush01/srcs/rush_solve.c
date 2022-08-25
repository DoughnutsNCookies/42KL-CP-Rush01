/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:54:27 by schuah            #+#    #+#             */
/*   Updated: 2022/08/25 20:13:41 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	reduce_start(int start)
{
	char	*temp;

	temp = ft_itoa(start);
	temp[0]++;
	temp[ft_strlen(temp) - 1] = '\0';
	start = ft_atoi(temp);
	free(temp);
	return (start);
}

static void	fill_left(int i, int index, int table[4][4])
{
	int		start;
	int		spaces;

	start = 1000;
	spaces = 0;
	if (index == 0)
	{
		while (index < 4)
		{
			table[index++][i % 4] = start;
			start = reduce_start(start);
		}
	}
	else if (index == 3)
	{
		while (index > 0)
		{
			table[index--][i % 4] = start;
			start = reduce_start(start);
		}
	}
}

static void	fill_right(int i, int index, int table[4][4])
{
	int	start;

	start = 1000;
	if (index == 0)
	{
		while (index < 4)
		{
			table[i % 4][index++] = start;
			start = reduce_start(start);
		}
	}
	else if (index == 3)
	{
		while (index > 0)
		{
			table[i % 4][index--] = start;
			start = reduce_start(start);
		}
	}
}

static void	put_max(int table[4][4], int i)
{
	if (i <= 3)
		table[0][i] = 4;
	else if (i >= 4 && i <= 7)
		table[3][i - 4] = 4;
	else if (i >= 8 && i <= 11)
		table[i - 8][0] = 4;
	else if (i >= 12 && i <= 15)
		table[i - 12][3] = 4;
}

void	solve_for_minmax(int table[4][4], int input[16])
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if (input[i] == 4)
		{
			if (i <= 3)
				fill_left(i, 0, table);
			if (i >= 4 && i <= 7)
				fill_left(i, 3, table);
			if (i >= 8 && i <= 11)
				fill_right(i, 0, table);
			if (i >= 12 && i <= 15)
				fill_right(i, 3, table);
		}
		if (input[i] == 1)
			put_max(table, i);
	}
}
