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
}

size_t    innerCycle(unsigned char map[], unsigned char x[], size_t len)
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
            x[0] = map[i++];
            x[1] = map[i];
            if (i < len)
                attron(COLOR_PAIR(5));
            mvwprintw(stdscr, n, q, (char*)x);
            if (i++ < len)
                attroff(COLOR_PAIR(5));
            q += 3;
        }
		mvwprintw(stdscr, 0, 240, "%d", n);
        n++;
    }
    return i;
}

void    visualize(unsigned char map[], size_t len)
{
    unsigned char   x[3];

	x[2] = '\0';
	innerCycle(map, x, len);
	refresh();
}
