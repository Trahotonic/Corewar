/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:11:05 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/08/22 15:11:07 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/visualization.h"

void	init_colors(void)
{
	init_color(LIGHT_GREEN, 500, 1000, 500);
	init_color(GREY, 300, 300, 300);
	init_color(DARK_GREEN, 0, 650, 0);
	init_color(DARK_CYAN, 0, 500, 500);
	init_color(DARK_BLUE, 0, 0, 700);
	init_color(GOOD_GREEN, 0, 1000, 0);
	init_color(GOOD_RED, 1000, 0, 0);
	init_color(GOOD_CYAN, 0, 1000, 1000);
	init_color(GOOD_BLUE, 200, 200, 1000);
	init_color(RED_FALCON, 700, 0, 0);
	init_color(LIGHT_RED, 1000, 300, 300);
	init_color(PISS, 0, 1000, 1000);
	init_color(LIGHT_CYAN, 400, 1000, 1000);
	init_color(LIGHT_BLUE, 400, 400, 1000);
	init_color(VERY_WHITE, 1000, 1000, 1000);
}

void	init_pairs(void)
{
	init_pair(DEFAULT_COLOR_PAIR, GREY, COLOR_BLACK);
	init_pair(MARK_PROCESS1_PAIR, COLOR_BLACK, GOOD_GREEN);
	init_pair(MARK_PROCESS2_PAIR, COLOR_BLACK, GOOD_BLUE);
	init_pair(MARK_PROCESS3_PAIR, COLOR_BLACK, GOOD_RED);
	init_pair(MARK_PROCESS4_PAIR, COLOR_BLACK, GOOD_CYAN);
	init_pair(DEFAULT_PLAYER1_PAIR, DARK_GREEN, COLOR_BLACK);
	init_pair(DEFAULT_PLAYER2_PAIR, DARK_BLUE, COLOR_BLACK);
	init_pair(DEFAULT_PLAYER3_PAIR, RED_FALCON, COLOR_BLACK);
	init_pair(DEFAULT_PLAYER4_PAIR, DARK_CYAN, COLOR_BLACK);
	init_pair(NEW_PLAYER1_CODE_PAIR, LIGHT_GREEN, COLOR_BLACK);
	init_pair(NEW_PLAYER2_CODE_PAIR, LIGHT_BLUE, COLOR_BLACK);
	init_pair(NEW_PLAYER3_CODE_PAIR, LIGHT_RED, COLOR_BLACK);
	init_pair(NEW_PLAYER4_CODE_PAIR, LIGHT_CYAN, COLOR_BLACK);
	init_pair(SEEK_BITCH, COLOR_BLACK, RED_FALCON);
	init_pair(SEEK_YELLOW_BITCH, COLOR_BLACK, PISS);
	init_pair(BORDER, COLOR_BLACK, GREY);
	init_pair(WHITE_CUNT, VERY_WHITE, COLOR_BLACK);
}

void	print_border(void)
{
	int n;

	n = 0;
	attron(COLOR_PAIR(BORDER));
	while (n < 254)
	{
		mvwprintw(stdscr, 0, n, " ");
		mvwprintw(stdscr, 67, n++, " ");
	}
	n = 0;
	while (n < 68)
	{
		mvwprintw(stdscr, n, 0, " ");
		mvwprintw(stdscr, n, 196, " ");
		mvwprintw(stdscr, n++, 253, " ");
	}
	attroff(COLOR_PAIR(BORDER));
}

void	init_vis(void)
{
	initscr();
	curs_set(0);
	nodelay(stdscr, false);
	start_color();
	init_colors();
	init_pairs();
	print_border();
}
