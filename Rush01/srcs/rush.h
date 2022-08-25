/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:27:53 by schuah            #+#    #+#             */
/*   Updated: 2022/08/25 20:13:46 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include "../libft/srcs/libft.h"

int		solve(int table[4][4], int input[16]);

void	print_table(int table[4][4], int input[16]);

int		has_existing(int table[4][4], int x, int y);
int		mto_pos(int n);
int		check_removed(int n, int toremove);
int		check_single(int n, int table[4][4], int x, int y);
int		remove_option(int input, int clue, int dist);

void	remove_dup(int table[4][4]);
void	elimination(int table[4][4]);

int		bruteforce(int table[4][4], int input[16], int pos, int xy);
int		check_xy(int table[4][4], int input[16], int x, int y);
void	copy_table(int copy[4][4], int table[4][4]);
int		find_box(int table[4][4], int xy, int max_space, int best);

void	solve_for_minmax(int table[4][4], int input[16]);
void	edge_constraint(int table[4][4], int input[16]);

#endif