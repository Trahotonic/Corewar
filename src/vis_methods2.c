/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_methods2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:12:23 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/08/22 15:12:24 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		mark_core(unsigned char x[], int i, unsigned char map[],
					unsigned char m_p[])
{
	x[0] = map[i];
	x[1] = map[i + 1];
	if (m_p[i] == 1)
		return (MARK_PROCESS1_PAIR);
	else if (m_p[i] == 2)
		return (MARK_PROCESS2_PAIR);
	else if (m_p[i] == 3)
		return (MARK_PROCESS3_PAIR);
	else if (m_p[i] == 4)
		return (MARK_PROCESS4_PAIR);
	else
		return (0);
}

void	mark_processes(t_vis_iter iters, unsigned char map[],
					unsigned char m_p[])
{
	unsigned char x[3];

	x[2] = '\0';
	iters.n = 0;
	iters.i = 0;
	while (iters.n < 64)
	{
		iters.m = 0;
		iters.q = 0;
		while (iters.m < 64)
		{
			iters.pair = mark_core(x, iters.i, map, m_p);
			if (iters.pair)
			{
				attron(COLOR_PAIR(iters.pair));
				mvwprintw(stdscr, iters.n + 2, iters.q + 3, (char*)x);
				attroff(COLOR_PAIR(iters.pair));
			}
			iters.q += 3;
			iters.i += 2;
			iters.m++;
		}
		iters.n++;
	}
}

void	pick_player_pair(int idx, unsigned char mark_timeout[], int *pair,
						int val)
{
	int default_pairs[4];
	int new_code_pairs[4];

	default_pairs[0] = DEFAULT_PLAYER1_PAIR;
	default_pairs[1] = DEFAULT_PLAYER2_PAIR;
	default_pairs[2] = DEFAULT_PLAYER3_PAIR;
	default_pairs[3] = DEFAULT_PLAYER4_PAIR;
	new_code_pairs[0] = NEW_PLAYER1_CODE_PAIR;
	new_code_pairs[1] = NEW_PLAYER2_CODE_PAIR;
	new_code_pairs[2] = NEW_PLAYER3_CODE_PAIR;
	new_code_pairs[3] = NEW_PLAYER4_CODE_PAIR;
	if (mark_timeout[idx] > 0)
	{
		*pair = new_code_pairs[val - 1];
		--mark_timeout[idx];
	}
	else
		*pair = default_pairs[val - 1];
}

void	print_names(t_player *players)
{
	int		n;
	int		pl_count;
	int		pair;

	n = 0;
	pl_count = get_players(players);
	while (n < pl_count)
	{
		if (n == 0)
			pair = NEW_PLAYER1_CODE_PAIR;
		else if (n == 1)
			pair = NEW_PLAYER2_CODE_PAIR;
		else if (n == 2)
			pair = NEW_PLAYER3_CODE_PAIR;
		else
			pair = NEW_PLAYER4_CODE_PAIR;
		attron(COLOR_PAIR(pair));
		mvwprintw(stdscr, 11 + (n * 4), 211, "%s", players->header.prog_name);
		attroff(COLOR_PAIR(pair));
		players = players->next;
		++n;
	}
}

void	erase_nums(int count)
{
	int n;

	n = 0;
	mvwprintw(stdscr, 7, 207, "            ");
	mvwprintw(stdscr, 9, 211, "            ");
	while (n < count)
	{
		mvwprintw(stdscr, 11 + (n * 4), 210, "            ");
		mvwprintw(stdscr, 12 + (n * 4), 213, "            ");
		mvwprintw(stdscr, 13 + (n * 4), 226, "            ");
		++n;
	}
	mvwprintw(stdscr, 11 + (n * 4) + 6, 214, "            ");
	mvwprintw(stdscr, 11 + (n * 4) + 8, 113, "            ");
}
