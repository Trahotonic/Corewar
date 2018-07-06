# include "./../inc/corewar.h"

void    getTotal(int fd, char **total)
{
    int n;
    unsigned int buff;
    char *str;

    n = 1;
    *total = ft_strnew(0);
    while ((n = read(fd, &buff, sizeof(int))))
    {
        buff = ((buff & 0x000000FF) << 24) | ((buff & 0x0000FF00) <<  8) |
               ((buff & 0x00FF0000) >>  8) | ((buff & 0xFF000000) >> 24);
        if (n == 1)
            str = ft_strsub(ft_uitoa_base2(buff, 16), 0, 2);
        else if (n == 2)
            str = ft_strsub(ft_uitoa_base2(buff, 16), 0, 4);
        else if (n == 3)
            str = ft_strsub(ft_uitoa_base2(buff, 16), 0, 6);
        else
        {
            str = ft_uitoa_base2(buff, 16);
            convert(&str);
        }
        *total = ft_arrg_join(*total, str);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
	header_t	header;
	char		*total;
	unsigned char	map[4096];
    char *x;
	int n;
    int m;
    int q;
    int c;
    int i;
    i = 0;
    n = 0;
    x = (char*)malloc(sizeof(char) * 3);
    x[2] = '\0';
	while (n < 4096)
		map[n++] = '0';
	int fd = open(argv[1], O_RDONLY);
	read(fd, &header, sizeof(header_t));
    getTotal(fd, &total);
	n = 0;
    while (total[n] != '\0')
    {
        map[n] = total[n];
        n++;
    }
//    printf("%s\n", map);
	close(fd);
    initscr();
    curs_set(0);
    nodelay(stdscr, true);
    start_color();
    use_default_colors();
    init_pair(5, COLOR_GREEN, -1);
    while (1)
    {
//        clear();
        c = getch();
        if (c == 113)
            break ;
        n = 0;
        while (n < 64)
        {
            m = 0;
            q = 0;
            while (m < 64 && i < 4096)
            {
                x[0] = map[i];
                i++;
                x[1] = map[i];
                if (i < (int)ft_strlen(total))
                    attron(COLOR_PAIR(5));
                mvwprintw(stdscr, n, q, x);
                if (i < (int)ft_strlen(total))
                    attroff(COLOR_PAIR(5));
                m++;
                q += 3;
                i++;
            }
            n++;
        }
        refresh();
    }
    endwin();
	return 0;
}