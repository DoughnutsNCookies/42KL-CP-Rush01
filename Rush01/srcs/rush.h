/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:27:53 by schuah            #+#    #+#             */
/*   Updated: 2022/08/26 13:16:41 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include "../libft/srcs/libft.h"

# define B_MAX 4
# define I_MAX 16
# define N 1234
# define MAX_INPUT_RUSH 31
# define START 1000

int		solve(int table[B_MAX][B_MAX], int input[I_MAX]);

void	print_table(int table[B_MAX][B_MAX], int input[I_MAX]);

int		has_existing(int table[B_MAX][B_MAX], int x, int y);
int		mto_pos(int n);
int		check_removed(int n, int toremove);
int		check_single(int n, int table[B_MAX][B_MAX], int x, int y);
int		remove_option(int input, int clue, int dist);

void	remove_dup(int table[B_MAX][B_MAX]);
void	elimination(int table[B_MAX][B_MAX]);

int		bruteforce(int table[B_MAX][B_MAX], int input[I_MAX], int pos, int xy);
int		check_xy(int table[B_MAX][B_MAX], int input[I_MAX], int x, int y);
void	copy_table(int copy[B_MAX][B_MAX], int table[B_MAX][B_MAX]);
int		find_box(int table[B_MAX][B_MAX], int xy, int max_space, int best);

void	solve_for_minmax(int table[B_MAX][B_MAX], int input[I_MAX]);
void	edge_constraint(int table[B_MAX][B_MAX], int input[I_MAX]);
int		reduce_start(int start);
int		reduce_start_tens(int start);
int		reduce_input_recurs(char *temp, int i, int n);

#endif