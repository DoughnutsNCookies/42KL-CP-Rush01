/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_solvehelper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:30:14 by schuah            #+#    #+#             */
/*   Updated: 2022/08/26 12:13:21 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	mto_pos(int n)
{
	int	start;

	start = START;
	while (1)
	{
		if (n == start)
			return (0);
		if (start == B_MAX)
			break ;
		start = reduce_start_tens(start);
	}
	return (1);
}

int	has_existing(int table[B_MAX][B_MAX], int x, int y)
{
	int	i;

	i = -1;
	while (++i < B_MAX)
	{
		if (mto_pos(table[y][i]) == 0
			&& check_removed(table[y][x], table[y][i]) == 0)
			return (table[y][i]);
		if (mto_pos(table[i][x]) == 0
			&& check_removed(table[y][x], table[i][x]) == 0)
			return (table[i][x]);
	}
	return (0);
}

int	check_removed(int n, int toremove)
{
	char	*n_temp;
	int		i;

	if (toremove == 0)
		return (1);
	n_temp = ft_itoa(n);
	i = -1;
	while (toremove / 10 != 0)
		toremove /= 10;
	while (n_temp[++i] != '\0')
	{
		if (n_temp[i] == toremove + 48)
		{
			free(n_temp);
			return (0);
		}
	}
	free(n_temp);
	return (1);
}

int	check_single(int n, int table[B_MAX][B_MAX], int x, int y)
{
	int		i;
	int		max;
	int		ten;
	int		start;

	i = -1;
	max = 0;
	while (++i < B_MAX)
		max += table[y][i] + table[i][x];
	max -= n;
	start = START;
	ten = 1000000000;
	while (1)
	{
		if (max % ten == start)
			return (start / 10);
		if (start == B_MAX)
			break ;
		ten /= 10;
		start = reduce_start_tens(start);
	}
	return (0);
}

int	remove_option(int input, int clue, int dist)
{
	int		n;
	int		i;
	char	*temp;

	temp = ft_itoa(input);
	n = 4 - clue + 2 + dist;
	i = 2;
	while (i <= B_MAX)
	{
		if (n == i && temp[i] == n - 48)
			input -= reduce_input_recurs(temp, i - 1, n);
		i++;
	}
	free(temp);
	return (input);
}
