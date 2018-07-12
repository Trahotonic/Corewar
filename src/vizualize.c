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
    use_default_colors();
	init_pair(5, COLOR_GREEN, -1);
	init_pair(4, COLOR_GREEN, COLOR_WHITE);
}

size_t    innerCycle(unsigned char map[], unsigned char x[], size_t len, t_process *proc)
{
    int 	n;
    int	 	m;
    int 	q;
	size_t 	i;

    n = 0;
	i = 0;
    while (n < 64)
    {
        m = 0;
        q = 0;
        while (m++ < 64)
        {
			if (i < len)
			{
				if (i != proc->cur_pos)
					attron(COLOR_PAIR(5));
				else
					attron(COLOR_PAIR(4));
			}
            x[0] = map[i];
            x[1] = map[i + 1];
            mvwprintw(stdscr, n, q, (char*)x);
            if (i - 2 < len)
			{
				if (i != proc->cur_pos)
					attroff(COLOR_PAIR(5));
				else
					attroff(COLOR_PAIR(4));
			}
            q += 3;
			i += 2;
        }
		mvwprintw(stdscr, 0, 240, "%d", n);
        n++;
    }
    return i;
}

void    visualize(unsigned char map[], size_t len, t_process *proc)
{
    unsigned char   x[3];

	x[2] = '\0';
	innerCycle(map, x, len, proc);
	refresh();
}
