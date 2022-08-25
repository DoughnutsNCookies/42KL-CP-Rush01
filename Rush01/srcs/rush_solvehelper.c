/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_solvehelper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:30:14 by schuah            #+#    #+#             */
/*   Updated: 2022/08/25 17:22:53 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	mto_pos(int n)
{
	return (n != 1000 && n != 200 && n != 30 && n != 4);
}

int	has_existing(int table[4][4], int x, int y)
{
	int	i;

	i = -1;
	while (++i < 4)
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

int	check_single(int n, int table[4][4], int x, int y)
{
	int		i;
	int		max;

	i = -1;
	max = 0;
	while (++i < 4)
		max += table[y][i] + table[i][x];
	max -= n;
	if (max % 10 == 4)
		return (4);
	if (max % 100 == 30)
		return (30);
	if (max % 1000 == 200)
		return (200);
	if (max % 10000 == 1000)
		return (1000);
	return (0);
}

/* 4 - Clue + 2 + Distance (start from 1) */
int	remove_option(int input, int clue, int dist)
{
	int		n;
	char	*temp;

	temp = ft_itoa(input);
	n = 4 - clue + 2 + dist;
	if (n == 1 && temp[0] == '1')
		input -= 1000;
	if (n == 2 && temp[1] == '2')
	{
		input -= 200;
		if (temp[2] == '3')
			input -= 30;
		if (temp[3] == '4')
		input -= 4;
	}
	if (n == 3 && temp[2] == '3')
	{
		input -= 30;
		if (temp[3] == '4')
			input -= 4;
	}
	if (n == 4 && temp[3] == '4')
		input -= 4;
	free(temp);
	return (input);
}
