/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_backtrackhelper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:43:09 by schuah            #+#    #+#             */
/*   Updated: 2022/08/25 17:55:06 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	find_box(int table[4][4], int xy, int max_space, int best)
{
	int		spaces;
	char	*temp;
	char	*temp2;

	if (table[xy / 4][xy % 4] != 1000 && table[xy / 4][xy % 4] != 200
		&& table[xy / 4][xy % 4] != 30 && table[xy / 4][xy % 4] != 4)
	{
		spaces = 0;
		temp = ft_itoa(table[xy / 4][xy % 4]);
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
	}
	return (best);
}
