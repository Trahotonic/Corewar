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
			x[0] = map[iters.i];
			x[1] = map[iters.i + 1];
			if (mP[iters.i] == 1)
				iters.pair = MARK_PROCESS1_PAIR;
			else if (mP[iters.i] == 2)
				iters.pair = MARK_PROCESS2_PAIR;
			else if (mP[iters.i] == 3)
				iters.pair = MARK_PROCESS3_PAIR;
			else if (mP[iters.i] == 4)
				iters.pair = MARK_PROCESS4_PAIR;
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

void    innerCycle(unsigned char map[], unsigned char x[], size_t len, t_process *proc, t_vizData *vizData)
{
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
			if (vizData->vizData[iters.i] == 1)
			{
				if (vizData->markTimeout[iters.i] > 0)
				{
					iters.pair = NEW_PLAYER1_CODE_PAIR;
					vizData->markTimeout[iters.i]--;
				}
				else
					iters.pair = DEFAULT_PLAYER1_PAIR;
			}
			else if (vizData->vizData[iters.i] == 2)
			{
				if (vizData->markTimeout[iters.i] > 0)
				{
					iters.pair = NEW_PLAYER2_CODE_PAIR;
					vizData->markTimeout[iters.i]--;
				}
				else
					iters.pair = DEFAULT_PLAYER2_PAIR;
			}
			else if (vizData->vizData[iters.i] == 3)
			{
				if (vizData->markTimeout[iters.i] > 0)
				{
					iters.pair = NEW_PLAYER3_CODE_PAIR;
					vizData->markTimeout[iters.i]--;
				}
				else
					iters.pair = DEFAULT_PLAYER3_PAIR;
			}
			else if (vizData->vizData[iters.i] == 4)
			{
				if (vizData->markTimeout[iters.i] > 0)
				{
					iters.pair = NEW_PLAYER4_CODE_PAIR;
					vizData->markTimeout[iters.i]--;
				}
				else
					iters.pair = DEFAULT_PLAYER4_PAIR;
			}
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

void    visualize(unsigned char map[], size_t len, t_process *proc, t_vizData *vizData)
{
    unsigned char   x[3];

	x[2] = '\0';
	innerCycle(map, x, len, proc, vizData);
	mvwprintw(stdscr, 2, 196, "                  ");
	mvwprintw(stdscr, 2, 196, "processes: %d", getProcesses(proc));
	refresh();
}
