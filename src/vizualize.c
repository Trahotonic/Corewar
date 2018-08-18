//
// Created by Roman Kyslyy on 7/7/18.
//

# include "../inc/corewar.h"


void    initVis(void)
{
    initscr();
    curs_set(0);
//    nodelay(stdscr, true);
    start_color();
    initColors();
    initPairs();
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
	else
		return (MARK_PROCESS4_PAIR);
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
			if (mP[iters.i])
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

void    innerCycle(unsigned char map[], t_process *proc, t_vizData *vizData)
{
	unsigned char   x[3];

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
	mvwprintw(stdscr, 2, 196, "                  ");
	mvwprintw(stdscr, 2, 196, "processes: %d", getProcesses(proc));
	refresh();
}
