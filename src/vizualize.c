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
    init_color(LIGHT_GREEN, 500, 1000, 500);
    init_color(GREY, 300, 300, 300);
    init_color(DARK_GREEN, 0, 650, 0);
    init_color(DARK_YELLOW, 500, 500, 0);
    init_color(DARK_BLUE, 0, 0, 700);
	init_color(GOOD_GREEN, 0, 1000, 0);
	init_color(GOOD_RED, 1000, 0, 0);
	init_color(GOOD_YELLOW, 1000, 1000, 0);
	init_color(GOOD_BLUE, 200, 200, 1000);
	init_color(RED_FALCON, 700, 0, 0);
	init_color(LIGHT_RED, 1000, 300, 300);
	init_color(PISS, 0, 1000, 1000);
	init_color(LIGHT_YELLOW, 1000, 1000, 400);
	init_color(LIGHT_BLUE, 400, 400, 1000);
    init_pair(DEFAULT_COLOR_PAIR, GREY, COLOR_BLACK);
    init_pair(MARK_PROCESS1_PAIR, COLOR_BLACK, GOOD_GREEN);
    init_pair(MARK_PROCESS2_PAIR, COLOR_BLACK, GOOD_RED);
    init_pair(MARK_PROCESS3_PAIR, COLOR_BLACK, GOOD_YELLOW);
    init_pair(MARK_PROCESS4_PAIR, COLOR_BLACK, GOOD_BLUE);
    init_pair(DEFAULT_PLAYER1_PAIR, DARK_GREEN, COLOR_BLACK);
	init_pair(DEFAULT_PLAYER2_PAIR, RED_FALCON, COLOR_BLACK);
	init_pair(DEFAULT_PLAYER3_PAIR, DARK_YELLOW, COLOR_BLACK);
	init_pair(DEFAULT_PLAYER4_PAIR, DARK_BLUE, COLOR_BLACK);
    init_pair(NEW_PLAYER1_CODE_PAIR, LIGHT_GREEN, COLOR_BLACK);
    init_pair(NEW_PLAYER2_CODE_PAIR, LIGHT_RED, COLOR_BLACK);
    init_pair(NEW_PLAYER3_CODE_PAIR, LIGHT_YELLOW, COLOR_BLACK);
    init_pair(NEW_PLAYER4_CODE_PAIR, LIGHT_BLUE, COLOR_BLACK);
	init_pair(SEEK_BITCH, COLOR_BLACK, RED_FALCON);
	init_pair(SEEK_YELLOW_BITCH, COLOR_BLACK, PISS);
}

int 	getProcesses(t_process *proc)
{
	int n = 0;
	while (proc)
	{
		n++;
		proc = proc->next;
	}
	return n;
}

size_t    innerCycle(unsigned char map[], unsigned char x[], size_t len, t_process *proc, t_vizData *vizData)
{
    int 		n;
    int	 		m;
    int 		q;
	size_t 		i;
	int 		pair;
	t_process	*ptr;
	unsigned char   markProc[MEM_SIZE * 2];

    n = 0;
	i = 0;
	while (n < MEM_SIZE * 2)
		markProc[n++] = 0;
	n = 0;
	ptr = proc;
	while (ptr)
	{
		markProc[ptr->cur_pos] = ptr->pl_number;
		ptr = ptr->next;
	}
	n = 0;
    while (n < 64)
    {
        m = 0;
        q = 0;
        while (m < 64)
        {
			pair = DEFAULT_COLOR_PAIR;
			if (vizData->vizData[i] == 1)
			{
				if (vizData->markTimeout[i] > 0)
				{
					pair = NEW_PLAYER1_CODE_PAIR;
					vizData->markTimeout[i]--;
				}
				else
					pair = DEFAULT_PLAYER1_PAIR;
			}
			else if (vizData->vizData[i] == 2)
			{
				if (vizData->markTimeout[i] > 0)
				{
					pair = NEW_PLAYER2_CODE_PAIR;
					vizData->markTimeout[i]--;
				}
				else
					pair = DEFAULT_PLAYER2_PAIR;
			}
			else if (vizData->vizData[i] == 3)
			{
				if (vizData->markTimeout[i] > 0)
				{
					pair = NEW_PLAYER3_CODE_PAIR;
					vizData->markTimeout[i]--;
				}
				else
					pair = DEFAULT_PLAYER3_PAIR;
			}
			else if (vizData->vizData[i] == 4)
			{
				if (vizData->markTimeout[i] > 0)
				{
					pair = NEW_PLAYER4_CODE_PAIR;
					vizData->markTimeout[i]--;
				}
				else
					pair = DEFAULT_PLAYER4_PAIR;
			}

//	        else if (vizData->vizData[i] == 2)
//			{
//				if (vizData->markTimeout[i] > 0)
//				{
//					pair = NEW_PLAYER1_CODE_PAIR;
//					vizData->markTimeout[i]--;
//				}
//				else
//					pair = DEFAULT_PLAYER1_PAIR;
//			}
            x[0] = map[i];
            x[1] = map[i + 1];
			attron(COLOR_PAIR(pair));
            mvwprintw(stdscr, n + 2, q + 3, (char*)x);
			attroff(COLOR_PAIR(pair));
            q += 3;
			i += 2;
			m++;
        }
        n++;
    }
	n = 0;
	i = 0;
	while (n < 64)
	{
		m = 0;
		q = 0;
		while (m < 64)
		{
			x[0] = map[i];
			x[1] = map[i + 1];
			if (markProc[i] == 1)
			{
				attron(COLOR_PAIR(MARK_PROCESS1_PAIR));
				mvwprintw(stdscr, n + 2, q + 3, (char*)x);
				attroff(COLOR_PAIR(MARK_PROCESS1_PAIR));
			}
			else if (markProc[i] == 2)
			{
				attron(COLOR_PAIR(MARK_PROCESS2_PAIR));
				mvwprintw(stdscr, n + 2, q + 3, (char*)x);
				attroff(COLOR_PAIR(MARK_PROCESS2_PAIR));
			}
			else if (markProc[i] == 3)
			{
				attron(COLOR_PAIR(MARK_PROCESS3_PAIR));
				mvwprintw(stdscr, n + 2, q + 3, (char*)x);
				attroff(COLOR_PAIR(MARK_PROCESS3_PAIR));
			}
			else if (markProc[i] == 4)
			{
				attron(COLOR_PAIR(MARK_PROCESS4_PAIR));
				mvwprintw(stdscr, n + 2, q + 3, (char*)x);
				attroff(COLOR_PAIR(MARK_PROCESS4_PAIR));
			}
			q += 3;
			i += 2;
			m++;
		}
		n++;
	}

    return i;
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
