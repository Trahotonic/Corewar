# include "./../inc/corewar.h"

# define VIZ 0

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

void	runProcesses(t_process **processes, unsigned char map[], functions_t array[], int i, t_player *player, t_vizData *vizData) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	t_process	*go;
	int 		n;

	if (i == 235)
	{

	}
	go = *processes;
	while (go)
	{

		go = go->next;
	}
	go = *processes;
	while (go->next)
		go = go->next;
	n = 0;
	while (go)
	{
		if (go->invalidAgr)
		{
			go->invalidAgr = 0;
			go->cur_pos = (go->cur_pos + 2) % (MEM_SIZE * 2);
			go = go->prev;
			continue ;
		}

//		if (go->invalidAgr)
//		{
//			go->invalidAgr = 0;
//			if ( ((map[go->prev_pos + 1] - 'f') < 0 && map[go->prev_pos] == '0') && map[go->prev_pos] != 0 && (map[go->prev_pos] != '1' && map[go->prev_pos + 1] != '0'))
//			{
//				go->command[0] = '.';
//				go->command[1] = '.';
//				go->cur_pos = go->prev_pos;
//			}
//		}
		if (ft_strequ("..", go->command))
		{
			go->command[0] = map[go->cur_pos];
			go->command[1] = map[go->cur_pos + 1];
			while (n < 16 && !ft_strequ(go->command, array[n].name))
				n++;
			if (n == 16)
			{
				go->invalidAgr = 1;
				go->command[0] = '.';
				go->command[1] = '.';
				n = 0;
				continue ;
			}
			go->cycle_todo = array[n].cycles;
			go->codage = array[n].codage;
			n = 0;
		}
		if (go->proc_num == 8)
		{

		}
//		if ((ft_strequ(go->command, "03") || ft_strequ(go->command, "02") || ft_strequ(go->command, "01") || ft_strequ(go->command, "04") ||
//				ft_strequ(go->command, "05") || ft_strequ(go->command, "06") || ft_strequ(go->command, "07") || ft_strequ(go->command, "08") ||
//				ft_strequ(go->command, "09") || ft_strequ(go->command, "10") || ft_strequ(go->command, "0a") || ft_strequ(go->command, "0b") ||
//				ft_strequ(go->command, "0c") || ft_strequ(go->command, "0d") || ft_strequ(go->command, "0e") || ft_strequ(go->command, "0f")) &&
//				((map[go->cur_pos] == '0' && (map[go->cur_pos + 1] - 'f') > 0) || (map[go->cur_pos] == '1' && map[go->cur_pos + 1] != '0')
//				 || (map[go->cur_pos] != '0' && map[go->cur_pos] != '1') || (map[go->cur_pos] == '0' && map[go->cur_pos + 1] == '0')) && go->fresh == 1)
//		{
//			go->command[0] = '.';
//			go->command[1] = '.';
//			go->cur_pos = (go->cur_pos + 2) % (MEM_SIZE * 2);
//		}
		if (go->cycle_todo > 0)
		{
			go->cycle_todo--;
		}
		if ((ft_strequ("01", go->command) || ft_strequ("02", go->command) || ft_strequ("03", go->command) ||
		     ft_strequ("04", go->command) || ft_strequ("05", go->command) || ft_strequ("06", go->command) ||
		     ft_strequ("07", go->command) || ft_strequ("08", go->command) || ft_strequ("09", go->command) ||
		     ft_strequ("0a", go->command) || ft_strequ("0b", go->command) || ft_strequ("0c", go->command) ||
		     ft_strequ("0d", go->command) || ft_strequ("0e", go->command) || ft_strequ("0f", go->command) ||
		     ft_strequ("10", go->command))
		    && !go->cycle_todo)
		{
			readShit(map, go);
			int z;
			z = 0;
			if (i == 12983)
			{
				if (go->proc_num == 14)
				{

				}
				while(z < 16)
				{
					if (go->reg[z] == -1)
					{

					}
					z++;
				}
			}
			if (ft_strequ("01", go->command))
				array[0].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("02", go->command))
				array[1].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("03", go->command))
				array[2].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("04", go->command))
				array[3].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("05", go->command))
				array[4].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("06", go->command))
				array[5].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("07", go->command))
				array[6].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("08", go->command))
				array[7].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("09", go->command))
				array[8].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("0a", go->command))
				array[9].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("0b", go->command))
				array[10].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("0c", go->command))
				array[11].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("0d", go->command))
				array[12].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("0e", go->command))
				array[13].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("0f", go->command))
				array[14].funcptr(go, map, i, player, vizData);
			else if (ft_strequ("10", go->command))
				array[15].funcptr(go, map, i, player, vizData);
			go->command[0] = '.';
			go->command[1] = '.';
			go->iC = 0;
		}
		go = go->prev;
	}
	n = 0;

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


int     counter(t_process * process)
{
	int i;

	i = 0;
	while (process)
	{
		i++;
		process = process->next;
	}
	return i;
}

void    kill(t_process * processes)
{
	while (processes)
	{
		processes->alive = 0;
		processes = processes->next;
	}
}

void    superkill(t_process ** processes, int i, t_player *player)
{
	t_process   *ptr;
	t_process   *tmp;
	t_player    *plptr;

	ptr = *processes;
	while (ptr)
	{
		if (!ptr->alive)
		{
//			ft_printf("%d killed on %d\n", ptr->proc_num, i);
			if (ptr == *processes)
			{
				tmp = ptr;
				if (ptr->next)
					ptr->next->prev = NULL;
				*processes = ptr->next;
				ptr = *processes;
				free(tmp);
			}
			else
			{
				tmp = ptr;
				ptr->prev->next = ptr->next;
				if (ptr->next)
					ptr->next->prev = ptr->prev;
				ptr = ptr->next;
				free(tmp);
			}
			plptr = player;
			while (plptr)
			{
				plptr->liveCount = 0;
				plptr = plptr->next;
			}
			continue ;
		}
		if (!ptr)
			break ;
		ptr = ptr->next;
	}
}

int 	check21(t_player *players)
{
	t_player    *ptr;

	ptr = players;
	while (players)
	{
		if (players->liveCount >= NBR_LIVE)
		{
			players->liveCount = 0;
			while (ptr)
			{
				ptr->liveCount = 0;
				ptr = ptr->next;
			}
			return (1);
		}
		players = players->next;
	}
	return (0);
}

int     main(int argc, char **argv)
{
	header_t        header;
	char            *total;
	unsigned char   map[MEM_SIZE * 2];
	t_process  *processes;
	int    i;
	int    c;
	functions_t  array[16];
	t_player  *players;
	int    d;
	int    iter;
	t_vizData       vizData;
	int    cycleToDie;
	int    maxchecks;
	int             n;

	n = 0;
	maxchecks = 1;
	checkArguments(argc, argv, &d, &iter);
	initProcesses(&processes);
	initMap(map, &total, &header, argv, &vizData);
	if (!d && VIZ)
		initVis();
	initfunc(array);
	players = (t_player*)malloc(sizeof(t_player));
	players->header = header;
	players->lastAlive = 0;
	players->liveCount = 0;
	players->playerNumber = -1;
	players->len = ft_strlen(total);
	players->next = NULL;
	t_player    *p;
	cycleToDie = CYCLE_TO_DIE;
	i = 0;
	while (1)
	{
		if (n == cycleToDie && check21(players))
		{
			p = players;
			while (p)
			{
				p->liveCount = 0;
				p = p->next;
			}
			cycleToDie -= CYCLE_DELTA;
			maxchecks = 1;
			superkill(&processes, i, players);
			kill(processes);
			n = 0;
		}
		else if (n == cycleToDie)
		{
			p = players;
			while (p)
			{
				p->liveCount = 0;
				p = p->next;
			}
			if (maxchecks == MAX_CHECKS)
			{
				cycleToDie -= CYCLE_DELTA;
				maxchecks = 1;
			}
			else
				maxchecks++;
			superkill(&processes, i, players);
			kill(processes);
			n = 0;
		}
		if (!processes)
		{
			if (VIZ)
				endwin();
			ft_printf("GAME OVER on cycle %d\ncycle to die = %d\nprocesses: %d\n", i, cycleToDie, counter(processes));
			return 0;
		}
		if (d && i == iter)
			break ;
		if (cycleToDie <= 0)
		{
			if (VIZ)
				endwin();
			ft_printf("GAME OVER on cycle %d\ncycle to die = %d\nprocesses: %d\n", i, cycleToDie, counter(processes));
			return 0;
		}
//  printf("%d\n", i);
		if (i == 11367)
		{

		}
		int br = 1100;
		if (!d && VIZ && i >= br - 100)
		{
			visualize(map, ft_strlen(total), processes, &vizData);
			mvwprintw(stdscr, 0, 196, "%d", i);
			mvwprintw(stdscr, 3, 196, "                       ");
			mvwprintw(stdscr, 3, 196, "live count: %d", players->liveCount);
			mvwprintw(stdscr, 4, 196, "                       ");
			mvwprintw(stdscr, 4, 196, "last alive: %d", players->lastAlive);
			mvwprintw(stdscr, 5, 196, "                       ");
			mvwprintw(stdscr, 5, 196, "max checks: %d", maxchecks);
			mvwprintw(stdscr, 6, 196, "                   ");
			mvwprintw(stdscr, 6, 196, "cycle to die: %d", cycleToDie);
			if (i >= br)
				c = getch();
			if (c == 113)
				break ;
		}
		runProcesses(&processes, map, array, i, players, &vizData);
//  if (!processes) {
//   if (VIZ)
//    endwin();
//   return ft_printf("GAME OVER on cycle %d\ncycle to die = %d\nprocesses: %d\n", i, cycleToDie, counter(processes));
//  }
//  if (counter(processes) == 14)
//  {
//   ;
//  }

//   ft_printf("count proc = %d\ncycle to die = %d\n", counter(processes), cycleToDie);
		i++;
		n++;
//  if (!d && VIZ)
//   usleep(10000);
	}
	free(total);
	if (!d && VIZ)
		endwin();
	else
		dump(map);
	return 0;
}
