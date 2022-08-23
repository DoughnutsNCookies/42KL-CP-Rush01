/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:51:57 by schuah            #+#    #+#             */
/*   Updated: 2022/08/23 20:05:02 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	print_table(int table[4][4], int input[16])
{
	ft_printf("\n   |  %2d  |  %2d  |  %2d  |  %2d  |\n",
		input[0], input[1], input[2], input[3]);
	ft_printf("-----------------------------------\n");
	ft_printf("%d  |  %2d  |  %2d  |  %2d  |  %2d  |  %d\n",
		input[8], table[0][0], table[0][1], table[0][2], table[0][3],
		input[12]);
	ft_printf("%d  |  %2d  |  %2d  |  %2d  |  %2d  |  %d\n",
		input[9], table[1][0], table[1][1], table[1][2], table[1][3],
		input[13]);
	ft_printf("%d  |  %2d  |  %2d  |  %2d  |  %2d  |  %d\n",
		input[10], table[2][0], table[2][1], table[2][2], table[2][3],
		input[14]);
	ft_printf("%d  |  %2d  |  %2d  |  %2d  |  %2d  |  %d\n",
		input[11], table[3][0], table[3][1], table[3][2], table[3][3],
		input[15]);
	ft_printf("-----------------------------------\n");
	ft_printf("   |  %2d  |  %2d  |  %2d  |  %2d  |\n\n",
		input[4], input[5], input[6], input[7]);
}
