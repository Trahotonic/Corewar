/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 14:46:56 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/08/22 14:48:28 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	print_words(int pl_count, t_player *ptr, t_viz_data *viz_data)
{
	int	n;

	n = 0;
	while (n < pl_count)
	{
		mvwprintw(stdscr, 11 + (n * 4), 199, "Player %d :", ptr->playerNumber);
		mvwprintw(stdscr, 12 + (n * 4), 201, "Last live :%22d", ptr->lastAlive);
		mvwprintw(stdscr, 13 + (n * 4), 201, "Lives in current period :%8d",
				ptr->liveCount);
		ptr = ptr->next;
		++n;
	}
	mvwprintw(stdscr, 11 + (n * 4) + 6, 199, "CYCLE_TO_DIE : %d",
			viz_data->cycleToDie);
	mvwprintw(stdscr, 11 + (n * 4) + 8, 199, "CYCLE_DELTA : %d",
			viz_data->cycleDelta);
}

void	print_side_panel(t_viz_data *viz_data, t_process *proc)
{
	char		*running;
	char		*pause;
	int			pl_count;
	t_player	*ptr;

	running = "RUNNING";
	pause = "PAUSED";
	pl_count = get_players(viz_data->players);
	ptr = viz_data->players;
	erase_nums(pl_count);
	attron(A_BOLD);
	attron(COLOR_PAIR(WHITE_CUNT));
	mvwprintw(stdscr, 2, 199, "                  ");
	if (viz_data->space)
		mvwprintw(stdscr, 2, 199, "** %s **", running);
	else
		mvwprintw(stdscr, 2, 199, "** %s **", pause);
	mvwprintw(stdscr, 7, 199, "Cycle : %d", viz_data->i);
	mvwprintw(stdscr, 9, 199, "Processes : %d", get_processes(proc));
	print_words(pl_count, ptr, viz_data);
	attroff(COLOR_PAIR(WHITE_CUNT));
	print_names(viz_data->players);
	attron(A_BOLD);
}

void	do_print(t_vis_iter iters, t_viz_data *viz_data, unsigned char map[])
{
	unsigned char	x[3];

	x[2] = '\0';
	iters.n = 0;
	while (iters.n < 64)
	{
		iters.m = 0;
		iters.q = 0;
		while (iters.m < 64)
		{
			iters.pair = DEFAULT_COLOR_PAIR;
			if (viz_data->viz_data[iters.i])
				pick_player_pair(iters.i, viz_data->mark_timeout,
					&iters.pair, viz_data->viz_data[iters.i]);
			x[0] = map[iters.i];
			x[1] = map[iters.i + 1];
			attron(COLOR_PAIR(iters.pair));
			mvwprintw(stdscr, iters.n + 2, iters.q + 3, (char*)x);
			attroff(COLOR_PAIR(iters.pair));
			iters.q += 3;
			iters.i += 2;
			iters.m++;
		}
		iters.n++;
	}
}

void	inner_cycle(unsigned char map[], t_process *proc, t_viz_data *viz_data)
{
	t_vis_iter			iters;
	t_process			*ptr;
	unsigned char		mark_proc[MEM_SIZE * 2];

	print_side_panel(viz_data, proc);
	iters.n = 0;
	iters.i = 0;
	while (iters.n < MEM_SIZE * 2)
		mark_proc[iters.n++] = 0;
	iters.n = 0;
	ptr = proc;
	while (ptr)
	{
		if (ptr->proc_num == 28)
			mark_proc[ptr->cur_pos] = 33;
		else
			mark_proc[ptr->cur_pos] = ptr->pl_number;
		ptr = ptr->next;
	}
	do_print(iters, viz_data, map);
	mark_processes(iters, map, mark_proc);
}

void	visualize(unsigned char map[], t_process *proc, t_viz_data *viz_data)
{
	inner_cycle(map, proc, viz_data);
	refresh();
}
