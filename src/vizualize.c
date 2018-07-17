//
// Created by Roman Kyslyy on 7/7/18.
//

# include "../inc/corewar.h"

void    initVis(void)
{
    initscr();
    curs_set(0);
    nodelay(stdscr, true);
    start_color();
    init_color(LIGHT_GREEN, 500, 1000, 500);
    init_color(GREY, 300, 300, 300);
    init_color(DARK_GREEN, 0, 650, 0);
	init_color(GOOD_GREEN, 0, 1000, 0);
    init_pair(DEFAULT_COLOR_PAIR, GREY, COLOR_BLACK);
    init_pair(MARK_PROCESS_PAIR, COLOR_BLACK, GOOD_GREEN);
    init_pair(DEFAULT_PLAYER1_PAIR, DARK_GREEN, COLOR_BLACK);
    init_pair(NEW_PLAYER1_CODE_PAIR, LIGHT_GREEN, COLOR_BLACK);
}

size_t    innerCycle(unsigned char map[], unsigned char x[], size_t len, t_process *proc, t_vizData *vizData)
{
    int 		n;
    int	 		m;
    int 		q;
	size_t 		i;
	int 		pair;
	t_process	*ptr;

    n = 0;
	i = 0;
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
			ptr = proc;
			while (ptr)
			{
				if (i == ptr->cur_pos)
					pair = MARK_PROCESS_PAIR;
				ptr = ptr->next;
			}
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
    return i;
}

void    visualize(unsigned char map[], size_t len, t_process *proc, t_vizData *vizData)
{
    unsigned char   x[3];

	x[2] = '\0';
	innerCycle(map, x, len, proc, vizData);
	refresh();
}
