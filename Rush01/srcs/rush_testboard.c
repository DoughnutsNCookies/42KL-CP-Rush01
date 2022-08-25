/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_testboard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:41:29 by schuah            #+#    #+#             */
/*   Updated: 2022/08/25 18:16:04 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	up_to_down(int table[4][4], int input[16], int x)
{
	int	i;
	int	roof;
	int	views;
	int	target;

	while (++x < 4)
	{
		i = -1;
		roof = 0;
		views = 0;
		target = *input;
		while (++i < 4)
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

static int	down_to_up(int table[4][4], int input[16], int x)
{
	int	i;
	int	roof;
	int	views;
	int	target;

	while (++x < 4)
	{
		i = 4;
		roof = 0;
		views = 0;
		target = *(input + 4);
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

static int	left_to_right(int table[4][4], int input[16], int y)
{
	int	i;
	int	roof;
	int	views;
	int	target;

	while (++y < 4)
	{
		i = -1;
		roof = 0;
		views = 0;
		target = *(input + 8);
		while (++i < 4)
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

static int	right_to_left(int table[4][4], int input[16], int y)
{
	int	i;
	int	roof;
	int	views;
	int	target;

	while (++y < 4)
	{
		i = 4;
		roof = 0;
		views = 0;
		target = *(input + 12);
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

int	check_xy(int table[4][4], int input[16], int x, int y)
{
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			if (table[y][x] == 1000)
				table[y][x] = 1;
			if (table[y][x] == 200)
				table[y][x] = 2;
			if (table[y][x] == 30)
				table[y][x] = 3;
			if (table[y][x] == 4)
				table[y][x] = 4;
		}
	}
	if (!left_to_right(table, input, -1))
		return (0);
	if (!right_to_left(table, input, -1))
		return (0);
	if (!down_to_up(table, input, -1))
		return (0);
	if (!up_to_down(table, input, -1))
		return (0);
	return (1);
}
