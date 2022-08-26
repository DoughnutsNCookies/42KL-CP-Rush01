/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_testboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:41:29 by schuah            #+#    #+#             */
/*   Updated: 2022/08/26 13:04:57 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	up_to_down(int table[B_MAX][B_MAX], int input[I_MAX], int x)
{
	int	i;
	int	roof;
	int	views;
	int	target;

	while (++x < B_MAX)
	{
		i = -1;
		roof = 0;
		views = 0;
		target = *input;
		while (++i < B_MAX)
		{
			if (table[i][x] > roof)
			{
				roof = table[i][x];
				views++;
			}
		}
		if (target != views)
			return (0);
		input++;
	}
	return (1);
}

static int	down_to_up(int table[B_MAX][B_MAX], int input[I_MAX], int x)
{
	int	i;
	int	roof;
	int	views;
	int	target;

	while (++x < B_MAX)
	{
		i = B_MAX;
		roof = 0;
		views = 0;
		target = *(input + B_MAX);
		while (--i >= 0)
		{
			if (table[i][x] > roof)
			{
				roof = table[i][x];
				views++;
			}
		}
		if (target != views)
			return (0);
		input++;
	}
	return (1);
}

static int	left_to_right(int table[B_MAX][B_MAX], int input[I_MAX], int y)
{
	int	i;
	int	roof;
	int	views;
	int	target;

	while (++y < B_MAX)
	{
		i = -1;
		roof = 0;
		views = 0;
		target = *(input + (B_MAX * 2));
		while (++i < B_MAX)
		{
			if (table[y][i] > roof)
			{
				roof = table[y][i];
				views++;
			}
		}
		if (target != views)
			return (0);
		input++;
	}
	return (1);
}

static int	right_to_left(int table[B_MAX][B_MAX], int input[I_MAX], int y)
{
	int	i;
	int	roof;
	int	views;
	int	target;

	while (++y < B_MAX)
	{
		i = B_MAX;
		roof = 0;
		views = 0;
		target = *(input + (B_MAX * 3));
		while (--i >= 0)
		{
			if (table[y][i] > roof)
			{
				roof = table[y][i];
				views++;
			}
		}
		if (target != views)
			return (0);
		input++;
	}
	return (1);
}

int	check_xy(int table[B_MAX][B_MAX], int input[I_MAX], int x, int y)
{
	int	start;
	int	i;

	while (++x < B_MAX)
	{
		y = -1;
		while (++y < B_MAX)
		{
			i = -1;
			start = START;
			while (++i < B_MAX)
			{
				if (table[y][x] == start)
					table[y][x] = i + 1;
				start = reduce_start(start);
			}
		}
	}
	return (left_to_right(table, input, -1) && right_to_left(table, input, -1)
		&& down_to_up(table, input, -1) && up_to_down(table, input, -1));
}
