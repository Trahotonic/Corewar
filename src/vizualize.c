//
// Created by Roman Kyslyy on 7/7/18.
//

# include "../inc/corewar.h"

void	printWords(int plCount, t_player *ptr, t_vizData *vizData)
{
	int n;

	n = 0;
	while (n < plCount)
	{
		mvwprintw(stdscr, 11 + (n * 4), 199, "Player %d :", ptr->playerNumber);
		mvwprintw(stdscr, 12 + (n * 4), 201, "Last live :%22d", ptr->lastAlive);
		mvwprintw(stdscr, 13 + (n * 4), 201, "Lives in current period :%8d", ptr->liveCount);
		ptr = ptr->next;
		++n;
	}
	mvwprintw(stdscr, 11 + (n * 4) + 6, 199, "CYCLE_TO_DIE : %d", vizData->cycleToDie);
	mvwprintw(stdscr, 11 + (n * 4) + 8, 199, "CYCLE_DELTA : %d", vizData->cycleDelta);
}

void	printSidePanel(t_vizData *vizData, t_process *proc)
{
	char		*running = "RUNNING";
	char		*pause = "PAUSED";
	int 		plCount;
	t_player	*ptr;

	plCount = getPlayers(vizData->players);
	ptr = vizData->players;
	eraseNums(plCount);
	attron(A_BOLD);
	attron(COLOR_PAIR(WHITE_CUNT));
	mvwprintw(stdscr, 2, 199, "                  ");
	if (vizData->space)
		mvwprintw(stdscr, 2, 199, "** %s **", running);
	else
		mvwprintw(stdscr, 2, 199, "** %s **", pause);
	mvwprintw(stdscr, 7, 199, "Cycle : %d", vizData->i);
	mvwprintw(stdscr, 9, 199, "Processes : %d", getProcesses(proc));
	printWords(plCount, ptr, vizData);
	attroff(COLOR_PAIR(WHITE_CUNT));
	printNames(vizData->players);
	attron(A_BOLD);
}

void	doPrint(t_visIter iters, t_vizData *vizData, unsigned char map[])
{
	unsigned char   x[3];

	x[2] = '\0';
	iters.n = 0;
	while (iters.n < 64)
	{
		iters.m = 0;
		iters.q = 0;
		while (iters.m < 64)
		{
			iters.pair = DEFAULT_COLOR_PAIR;
			if (vizData->vizData[iters.i])
				pickPlayerPair(iters.i, vizData->markTimeout,
							   &iters.pair, vizData->vizData[iters.i]);
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

void    innerCycle(unsigned char map[], t_process *proc, t_vizData *vizData)
{
	printSidePanel(vizData, proc);
    t_visIter	iters;
	t_process	*ptr;
	unsigned char   markProc[MEM_SIZE * 2];

    iters.n = 0;
	iters.i = 0;
	while (iters.n < MEM_SIZE * 2)
		markProc[iters.n++] = 0;
	iters.n = 0;
	ptr = proc;
	while (ptr)
	{
		if (ptr->proc_num == 28)
			markProc[ptr->cur_pos] = 33;
		else
			markProc[ptr->cur_pos] = ptr->pl_number;
		ptr = ptr->next;
	}
	doPrint(iters, vizData, map);
    markProcesses(iters, map, markProc);
}

void    visualize(unsigned char map[], t_process *proc, t_vizData *vizData)
{
	innerCycle(map, proc, vizData);
	refresh();
}
