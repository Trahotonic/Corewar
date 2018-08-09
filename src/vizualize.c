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
	init_color(GOOD_GREEN, 0, 1000, 0);
	init_color(RED_FALCON, 1000, 0, 0);
	init_color(PISS, 0, 1000, 1000);
    init_pair(DEFAULT_COLOR_PAIR, GREY, COLOR_BLACK);
    init_pair(MARK_PROCESS_PAIR, COLOR_BLACK, GOOD_GREEN);
    init_pair(DEFAULT_PLAYER1_PAIR, DARK_GREEN, COLOR_BLACK);
    init_pair(NEW_PLAYER1_CODE_PAIR, LIGHT_GREEN, COLOR_BLACK);
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
	int         check = 0;
	unsigned char   markProc[MEM_SIZE * 2];

    n = 0;
	i = 0;
	while (n < MEM_SIZE * 2)
		markProc[n++] = 0;
	n = 0;
	ptr = proc;
	while (ptr)
	{
		markProc[ptr->cur_pos] = 1;
		ptr = ptr->next;
	}
	ptr = proc;
	while (ptr)
	{
		if (ptr->proc_num == 49)
		{
//			if (markProc[ptr->cur_pos] == 2)
//				markProc[ptr->cur_pos] = 3;
//			else
				markProc[ptr->cur_pos] = 2;
		}
		ptr = ptr->next;
	}
//	markProc[1224] = 2;
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
//	        ptr = proc;
//	        while (ptr)
//	        {
//		        if (i == ptr->cur_pos && ptr->proc_num == 20)
//		        {
//			        pair = SEEK_BITCH;
//			        break ;
//		        }
//		        ptr = ptr->next;
//	        }
//	        ptr = proc;
//	        while (ptr)
//	        {
//		        if (i == ptr->cur_pos && ptr->proc_num == 17)
//		        {
//			        pair = SEEK_YELLOW_BITCH;
//			        break ;
//		        }
//		        ptr = ptr->next;
//	        }
            x[0] = map[i];
            x[1] = map[i + 1];
			attron(COLOR_PAIR(pair));
            mvwprintw(stdscr, n, q, (char*)x);
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
				attron(COLOR_PAIR(MARK_PROCESS_PAIR));
				mvwprintw(stdscr, n, q, (char*)x);
				attroff(COLOR_PAIR(MARK_PROCESS_PAIR));
			}
			else if (markProc[i] == 2)
			{
				attron(COLOR_PAIR(SEEK_BITCH));
				mvwprintw(stdscr, n, q, (char*)x);
				attroff(COLOR_PAIR(SEEK_BITCH));
			}
			else if (markProc[i] == 3)
			{
				attron(COLOR_PAIR(SEEK_YELLOW_BITCH));
				mvwprintw(stdscr, n, q, (char*)x);
				attroff(COLOR_PAIR(SEEK_YELLOW_BITCH));
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
	mvwprintw(stdscr, 2, 193, "                  ");
	mvwprintw(stdscr, 2, 193, "processes: %d", getProcesses(proc));
	refresh();
}
