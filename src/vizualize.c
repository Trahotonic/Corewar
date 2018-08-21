//
// Created by Roman Kyslyy on 7/7/18.
//

# include "../inc/corewar.h"

void	printBorder(void)
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

int		getPlayers(t_player *players)
{
	int n;

	n = 0;
	while (players)
	{
		players = players->next;
		++n;
	}
	return (n);
}

void    initVis(void)
{
    initscr();
    curs_set(0);
	nodelay(stdscr, false);
    start_color();
    initColors();
    initPairs();
    printBorder();
}

int 	getProcesses(t_process *proc)
{
	int n = 0;

	while (proc)
	{
		++n;
		proc = proc->next;
	}
	return (n);
}

int		markCore(unsigned char x[], int i, unsigned char map[],
		unsigned char mP[])
{
	x[0] = map[i];
	x[1] = map[i + 1];
	if (mP[i] == 1)
		return (MARK_PROCESS1_PAIR);
	else if (mP[i] == 2)
		return (MARK_PROCESS2_PAIR);
	else if (mP[i] == 3)
		return (MARK_PROCESS3_PAIR);
	else if (mP[i] == 4)
		return (MARK_PROCESS4_PAIR);
	else
		return (0);
}

void	markProcesses(t_visIter iters, unsigned char map[], unsigned char mP[])
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
			iters.pair = markCore(x, iters.i, map, mP);
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

void	pickPlayerPair(int idx, unsigned char markTimeout[], int *pair, int val)
{
	int defaultPairs[4];
	int newCodePairs[4];

	defaultPairs[0] = DEFAULT_PLAYER1_PAIR;
	defaultPairs[1] = DEFAULT_PLAYER2_PAIR;
	defaultPairs[2] = DEFAULT_PLAYER3_PAIR;
	defaultPairs[3] = DEFAULT_PLAYER4_PAIR;
	newCodePairs[0] = NEW_PLAYER1_CODE_PAIR;
	newCodePairs[1] = NEW_PLAYER2_CODE_PAIR;
	newCodePairs[2] = NEW_PLAYER3_CODE_PAIR;
	newCodePairs[3] = NEW_PLAYER4_CODE_PAIR;
	if (markTimeout[idx] > 0)
	{
		*pair = newCodePairs[val - 1];
		--markTimeout[idx];
	}
	else
		*pair = defaultPairs[val - 1];
}

void	printNames(t_player *players)
{
	int		n;
	int 	plCount;
	int 	pair;

	n = 0;
	plCount = getPlayers(players);
	while (n < plCount)
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

void	eraseNums(int count)
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

void	printSidePanel(t_vizData *vizData, t_process *proc)
{
	char		*running = "RUNNING";
	char		*pause = "PAUSED";
	int 		plCount;
	int 		n;
	t_player	*ptr;

	plCount = getPlayers(vizData->players);
	n = 0;
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
	attroff(COLOR_PAIR(WHITE_CUNT));
	printNames(vizData->players);
	attron(A_BOLD);
}

void    innerCycle(unsigned char map[], t_process *proc, t_vizData *vizData)
{
	unsigned char   x[3];

	printSidePanel(vizData, proc);
    t_visIter	iters;
	t_process	*ptr;
	unsigned char   markProc[MEM_SIZE * 2];

	x[2] = '\0';
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
    markProcesses(iters, map, markProc);
}

void    visualize(unsigned char map[], t_process *proc, t_vizData *vizData)
{
	innerCycle(map, proc, vizData);
	refresh();
}
