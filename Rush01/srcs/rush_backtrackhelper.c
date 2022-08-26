/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_backtrackhelper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:43:09 by schuah            #+#    #+#             */
/*   Updated: 2022/08/26 12:57:33 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	reduce_start_tens(int start)
{
	char	*temp;

	temp = ft_itoa(start);
	temp[0] += 1;
	temp[ft_strlen(temp) - 1] = '\0';
	start = ft_atoi(temp);
	free(temp);
	return (start);
}

static int	check_true(int table[B_MAX][B_MAX], int xy)
{
	int	start;

	start = START;
	while (1)
	{
		if (table[xy / B_MAX][xy % B_MAX] == start)
			return (1);
		if (start == B_MAX)
			break ;
		start = reduce_start_tens(start);
	}
	return (0);
}

int	find_box(int table[B_MAX][B_MAX], int xy, int max_space, int best)
{
	int		spaces;
	char	*temp;
	char	*temp2;

	if (check_true(table, xy))
		return (best);
	spaces = 0;
	temp = ft_itoa(table[xy / B_MAX][xy % B_MAX]);
	temp2 = temp;
	while (*temp != '\0')
	{
		if (*temp == '0')
			spaces++;
		if (spaces >= max_space)
		{
			max_space = spaces;
			best = xy;
		}
		temp++;
	}
	free(temp2);
	return (best);
}

// i = 2, n == 3, ten = 10
int	reduce_input_recurs(char *temp, int i, int n)
{
	int	ten;
	int	count;

	if (n == B_MAX)
	{
		if (temp[i] == n - 48)
			return (B_MAX);
		else
			return (0);
	}
	ten = 1;
	count = 0;
	while (count++ < B_MAX - n)
		ten *= 10;
	if (n < B_MAX)
	{
		if (temp[i] == n - 48)
			return ((n * ten) + reduce_input_recurs(temp, i + 1, n + 1));
		else
			return (reduce_input_recurs(temp, i + 1, n + 1));
	}
	return ((n * ten) + reduce_input_recurs(temp, i + 1, n + 1));
}

void	copy_table(int copy[B_MAX][B_MAX], int table[B_MAX][B_MAX])
{
	int	x;
	int	y;

	y = -1;
	while (++y < B_MAX)
	{
		x = -1;
		while (++x < B_MAX)
			copy[y][x] = table[y][x];
	}
}
