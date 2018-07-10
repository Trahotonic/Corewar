# include "./../inc/corewar.h"

void    initMap(unsigned char map[], char **total, header_t *header, char **argv)
{
    int     n;
    int     fd;
    char    *work;

    n = 0;
    while (n < 4096)
        map[n++] = '0';
    fd = open(argv[1], O_RDONLY);
    read(fd, header, sizeof(header_t));
    getTotal(fd, total);
    n = 0;
    work = *total;
    while (work[n] != '\0')
    {
        map[n] = work[n];
        n++;
    }
    close(fd);
}

void	initProcesses(t_process **processes)
{
	t_process	*tmp;
	int 		n;
	int 		m;

	*processes = (t_process*)malloc(sizeof(t_process));
	tmp = *processes;
	tmp->cur_pos = 0;
	tmp->carry = 0;
	tmp->pl_num = 0;
	tmp->alive = 0;
	tmp->command[0] = '.';
	tmp->command[1] = '.';
	tmp->command[2] = '\0';
	tmp->cycle_todo = 0;
	tmp->iterator = 0;
	n = 0;
	while (n++ < 16)
	{
		m = 0;
		while (m++ < 4)
			tmp->reg[n][m] = 0;
	}
	tmp->next = NULL;
}

void	runProcesses(t_process **processes, unsigned char map[])
{
	t_process *go;

	go = *processes;
	while (go)
	{
		if (ft_strequ("..", go->command))
		{
			go->command[0] = map[go->cur_pos];
			go->command[1] = map[go->cur_pos + 1];
			go->cycle_todo = 10;
		}
		else
		{
			go = go;
		}
		go = go->next;
	}
}


int     main(int argc, char **argv)
{
    header_t        header;
    char            *total;
    unsigned char   map[MEM_SIZE];
	t_process		*processes;
	int 			i;

    if (argc != 2)
        return 1;
	initProcesses(&processes);
    initMap(map, &total, &header, argv);
	initVis();
	i = 0x2a;
	while (i++ < 1536)
	{
		visualize(map, ft_strlen(total));
		mvwprintw(stdscr, 0, 200, "%d", i);
		usleep(2000);
	}
    free(total);
	endwin();
	return 0;
}