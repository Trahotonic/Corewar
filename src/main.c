# include "./../inc/corewar.h"

void	dump(unsigned char map[])
{
	int		n;
	int 	m;
	int 	q;
	int 	row;
	char 	tmp[3];
	char 	*r;

	m = 0;
	q = 0;
	row = 0;
	tmp[2] = '\0';
	ft_printf("Introducing contestants...\n"
					  "* Player 1, weighing 325 bytes, \"Celebration Funebre v0.99pl42\" (\"Jour J\") !\n");
	while (q < 64)
	{
		n = 2;
		r = ft_itoa_base(row, 16);
		ft_printf("0x");
		while (n++ < 6 - ft_strlen(r))
			ft_printf("0");
		ft_printf("%s : ", r);
		n = 0;
		while (n < 64)
		{
			tmp[0] = map[m++];
			tmp[1] = map[m++];
			ft_printf("%s ", tmp);
			n++;
		}
		ft_printf("\n");
		row += 64;
		q++;
	}
}

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

void	checkArguments(int argc, char **argv, int *d, int *iter)
{
	int n;

	*d = 0;
	n = 1;
	while (n < argc)
	{
		if (ft_strequ(argv[n], "-d"))
		{
			*d = 1;
			*iter = ft_atoi(argv[n + 1]);
		}
		n++;
	}
}

int     main(int argc, char **argv)
{
    header_t        header;
    char            *total;
    unsigned char   map[MEM_SIZE * 2];
	t_process		*processes;
	int 			i;
	int 			c;
	functions_t		array[3];
	t_player		player;
	int 			d;
	int 			iter;

	checkArguments(argc, argv, &d, &iter);
	initProcesses(&processes);
    initMap(map, &total, &header, argv);
	if (!d)
		initVis();
	initfunc(array);
	player.header = header;
	player.lastAlive = 0;
	player.playerNumber = -1;
	i = 0;
	while (i++ < 100)
	{
		runProcesses(&processes, map, array, i, &player);
		if (!d)
		{
			visualize(map, ft_strlen(total));
			mvwprintw(stdscr, 0, 200, "%d", i);
			mvwprintw(stdscr, 0, 230, "%d", player.lastAlive);
			c = getch();
			if (c == 113)
				break ;
		}
	}
//	attroff(A_BOLD);
    free(total);
	if (!d)
		endwin();
	else
		dump(map);
	return 0;
}