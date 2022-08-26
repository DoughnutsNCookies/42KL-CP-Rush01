/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:27:35 by schuah            #+#    #+#             */
/*   Updated: 2022/08/26 12:04:07 by schuah           ###   ########.fr       */
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
	return (wc == MAX_INPUT_RUSH);
}

int	*get_input(char *str)
{
	int	i;
	int	j;
	int	*input;

	input = malloc(sizeof(int) * (B_MAX * B_MAX));
	i = -1;
	j = -1;
	while (str[++i] != '\0')
		if (str[i] >= '0' && str[i] <= '9')
			input[++j] = ft_atoi(str + i);
	return (input);
}

int	main(int ac, char **av)
{
	int	table[B_MAX][B_MAX];
	int	*input;
	int	x;
	int	y;

	if (check_valid(ac, av) == 0)
		return (ft_printf("Input Error\n"));
	input = get_input(av[1]);
	y = -1;
	while (++y < B_MAX)
	{
		x = -1;
		while (++x < B_MAX)
			table[y][x] = N;
	}
	if (bruteforce(table, input, 0, 0))
		print_table(table, input);
	else
		ft_printf("Unsolvable\n");
	free(input);
	return (0);
}
