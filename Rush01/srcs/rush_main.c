/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:27:35 by schuah            #+#    #+#             */
/*   Updated: 2022/08/23 19:37:38 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_valid(int ac, char **av)
{
	int	wc;

	if (ac != 2)
		return (0);
	wc = 0;
	while (av[1][wc] != '\0')
		wc++;
	return (wc == 31);
}

int	*get_input(char *str)
{
	int	i;
	int	j;
	int	*input;

	input = malloc(sizeof(int) * 16);
	i = -1;
	j = -1;
	while (str[++i] != '\0')
		if (str[i] >= '0' && str[i] <= '9')
			input[++j] = ft_atoi(str + i);
	return (input);
}

int	main(int ac, char **av)
{
	int	table[4][4];
	int	*input;
	int	x;
	int	y;

	if (check_valid(ac, av) == 0)
		return (ft_printf("Input Error\n"));
	input = get_input(av[1]);
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			table[y][x] = 30;
	}
	solve(table, input);
	free(input);
	return (0);
}
