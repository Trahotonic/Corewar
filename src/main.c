# include "./../inc/corewar.h"

void	runProcesses(t_process **processes, unsigned char map[], functions_t array[], int i, t_player *player)
{
	t_process	*go;
	int 		n;

	go = *processes;
	n = 0;
	while (go)
	{
		if (ft_strequ("..", go->command))
		{
			go->command[0] = map[go->cur_pos];
			go->command[1] = map[go->cur_pos + 1];
			while (!ft_strequ(go->command, array[n].name))
				n++;
			go->cycle_todo = array[n].cycles;
			go->codage = array[n].codage;
		}
		else if ((ft_strequ("01", go->command) ||
				ft_strequ("02", go->command) ||
				ft_strequ("03", go->command))
				 && !go->cycle_todo)
		{
			readShit(map, *processes);
			if (ft_strequ("01", go->command))
				array[0].funcptr(go, map, i, player);
			else if (ft_strequ("02", go->command))
				array[1].funcptr(go, map, i, player);
			else if (ft_strequ("03", go->command))
				array[2].funcptr(go, map, i, player);
			go->command[0] = '.';
			go->command[1] = '.';
		}
		if (go->cycle_todo)
			go->cycle_todo--;
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
	int 			c;
	functions_t		array[3];
	t_player		player;

    if (argc != 2)
        return 1;
	initProcesses(&processes);
    initMap(map, &total, &header, argv);
	initVis();
	initfunc(array);
	player.header = header;
	player.lastAlive = 0;
	player.playerNumber = -1;
	i = 0;
//	attron(A_BOLD);
	while (i++ < 100)
	{
		runProcesses(&processes, map, array, i, &player);
//		printf("%d\n", player.lastAlive);
		visualize(map, ft_strlen(total));
		mvwprintw(stdscr, 0, 200, "%d", i);
		mvwprintw(stdscr, 0, 230, "%d", player.lastAlive);
//		usleep(500000);
		c = getch();
		if (c == 113)
			break ;
	}
//	attroff(A_BOLD);
    free(total);
	endwin();
	return 0;
}