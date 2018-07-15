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
    init_color(COLOR_WHITE, 1000, 1000, 1000);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
//    init_color(COLOR_GREEN, 0, 600, 0);
	init_color(13, 500, 1500, 500);
	init_pair(3, 13, COLOR_BLACK);
	init_pair(9, COLOR_WHITE, COLOR_BLACK);
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
			pair = 9;
			if (vizData->vizData[i] == 1)
			{
				if (vizData->markTimeout[i] > 0)
				{
					pair = 3;
					vizData->markTimeout[i]--;
				}
				else
					pair = 1;
			}
			ptr = proc;
			while (ptr)
			{
				if (i == ptr->cur_pos)
				{
					pair = 2;
					break ;
				}
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
