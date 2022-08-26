/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:54:27 by schuah            #+#    #+#             */
/*   Updated: 2022/08/26 11:03:36 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	reduce_start(int start)
{
	char	*temp;

	temp = ft_itoa(start);
	temp[0]++;
	temp[ft_strlen(temp) - 1] = '\0';
	start = ft_atoi(temp);
	free(temp);
	return (start);
}

static void	fill_left(int i, int index, int table[B_MAX][B_MAX])
{
	int		start;
	int		spaces;

	start = START;
	spaces = 0;
	if (index == 0)
	{
		while (index < B_MAX)
		{
			table[index++][i % B_MAX] = start;
			start = reduce_start(start);
		}
	}
	else if (index == B_MAX - 1)
	{
		while (index > 0)
		{
			table[index--][i % B_MAX] = start;
			start = reduce_start(start);
		}
	}
}

static void	fill_right(int i, int index, int table[B_MAX][B_MAX])
{
	int	start;

	start = START;
	if (index == 0)
	{
		while (index < B_MAX)
		{
			table[i % B_MAX][index++] = start;
			start = reduce_start(start);
		}
	}
	else if (index == B_MAX - 1)
	{
		while (index > 0)
		{
			table[i % B_MAX][index--] = start;
			start = reduce_start(start);
		}
	}
}

static void	put_max(int table[B_MAX][B_MAX], int i)
{
	if (i <= B_MAX - 1)
		table[0][i] = B_MAX;
	else if (i >= B_MAX && i <= (B_MAX * 2) - 1)
		table[B_MAX - 1][i - B_MAX] = B_MAX;
	else if (i >= B_MAX * 2 && i <= (B_MAX * 3) - 1)
		table[i - (B_MAX * 2)][0] = B_MAX;
	else if (i >= B_MAX * 3 && i <= (B_MAX * 4) - 1)
		table[i - (B_MAX * 3)][B_MAX - 1] = B_MAX;
}

void	solve_for_minmax(int table[B_MAX][B_MAX], int input[I_MAX])
{
	int	i;

	i = -1;
	while (++i < (B_MAX * B_MAX))
	{
		if (input[i] == B_MAX)
		{
			if (i <= B_MAX - 1)
				fill_left(i, 0, table);
			if (i >= B_MAX && i <= (B_MAX * 2) - 1)
				fill_left(i, B_MAX - 1, table);
			if (i >= B_MAX * 2 && i <= (B_MAX * 3) - 1)
				fill_right(i, 0, table);
			if (i >= B_MAX * 3 && i <= (B_MAX * 4) - 1)
				fill_right(i, B_MAX - 1, table);
		}
		if (input[i] == 1)
			put_max(table, i);
	}
}
