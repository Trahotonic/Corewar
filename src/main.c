# include "./../inc/corewar.h"

# define VIZ 1

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
		if (ft_strequ("..", go->command))
		{
			go->command[0] = map[go->cur_pos];
			go->command[1] = map[go->cur_pos + 1];
			while (n < 16 && !ft_strequ(go->command, array[n].name))
				++n;
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
		if (go->cycle_todo > 0)
			--go->cycle_todo;
		if ((ft_strequ("01", go->command) || ft_strequ("02", go->command) || ft_strequ("03", go->command) ||
		     ft_strequ("04", go->command) || ft_strequ("05", go->command) || ft_strequ("06", go->command) ||
		     ft_strequ("07", go->command) || ft_strequ("08", go->command) || ft_strequ("09", go->command) ||
		     ft_strequ("0a", go->command) || ft_strequ("0b", go->command) || ft_strequ("0c", go->command) ||
		     ft_strequ("0d", go->command) || ft_strequ("0e", go->command) || ft_strequ("0f", go->command) ||
		     ft_strequ("10", go->command))
		    && !go->cycle_todo)
		{
			readShit(map, go);
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
}

int     counter(t_process * process)
{
	int i;

	i = 0;
	while (process)
	{
		++i;
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

t_player *ft_player_create(char *champ, int num)
{
	t_player *tmp;

	tmp = malloc(sizeof(t_player));
	tmp->num = num;
	tmp->fd = open(champ, O_RDONLY);
	if (tmp->fd == -1)
	{
		printf("ERROR\n");
		exit(666);
	}
	tmp->next = NULL;
	tmp->lastAlive = 0;
	tmp->len = 0;
	tmp->liveCount = 0;
	tmp->playerNumber = 0;

	return (tmp);
}

void ft_get_champ(t_player **players, char **argv, int *n)
{
	int i;

	i = 1;
	t_player *tmp;
	tmp = *players;
	if (!tmp)
		(*players) = ft_player_create(argv[*n], i);
	else
	{
		while (tmp->next)
		{
			(tmp) = (tmp)->next;
			++i;
		}
		tmp->next = ft_player_create(argv[*n], i);
	}
}

void  ft_check_flag_d(t_player **players, char **argv, int *n, t_argFlags *flags)
{
	int i;

	i = 0;
	(*n)++;
	if(argv[*n])
	{
		while(argv[*n][i])
		{
			if(!ft_isdigit(argv[*n][i]))
			{
				printf("ERROR\n");
				exit(1);
			}
			++i;
		}
		flags->d = ft_atoi(argv[*n]);
	}
	else
	{
		printf("ERROR\n");
		exit(1);
	}
}

void  ft_check_flag_vi(t_player **players, char **argv, int *n, t_argFlags *flags)
{
	int i;

	i = 0;
	(*n)++;
	if(argv[*n])
	{
		while(argv[*n][i])
		{
			if(!ft_isdigit(argv[*n][i]))
			{
				printf("ERROR\n");
				exit(1);
			}
			++i;
		}
		flags->vi = ft_atoi(argv[*n]);
	}
	else
	{
		printf("ERROR\n");
		exit(1);
	}
}

void  ft_check_flag_n(t_player **players, char **argv, int *n, t_argFlags *flags)
{
	int i;
	t_player *tmp;

	tmp = *players;
	i = 0;
	(*n)++;
	if(argv[*n])
	{
		if(*argv[*n] == '-')
			++i;
		while(argv[*n][i])
		{
			if(!ft_isdigit(argv[*n][i]))
			{
				printf("ERROR\n");
				exit(1);
			}
			++i;
		}
		if ((ft_atoi(argv[*n]) > INT32_MAX || ft_atoi(argv[*n]) < INT32_MIN) || !argv[*n + 1])
		{
			printf("ERROR\n");
			exit(666);
		}
		i = 1;
		if (!tmp)
		{
			*players = ft_player_create(argv[*n + 1], i);
			(*players)->playerNumber = ft_atoi(argv[*n]);
		}
		else
		{
			i++;
			while (tmp->next)
			{
				tmp = tmp->next;
				i++;
			}
			tmp->next = ft_player_create(argv[*n + 1], i);
			tmp->next->playerNumber = ft_atoi(argv[*n]);
		}
		(*n)++;
	}
	else
	{
		printf("ERROR\n");
		exit(1);
	}
}

void  ft_check_flags(t_player **players, char **argv, int *n, t_argFlags *flags)
{
	if (ft_strequ(argv[*n], "-d"))
		ft_check_flag_d(players, argv, n, flags);
	else if (ft_strequ(argv[*n], "-vi"))
		ft_check_flag_vi(players, argv, n, flags);
	else if (ft_strequ(argv[*n], "-v"))
		flags->v = 1;
	else if (ft_strequ(argv[*n], "-n"))
		ft_check_flag_n(players, argv, n, flags);
	else
		ft_printf("ERROR\n");

}

void ft_usage()
{

}

char *ft_strstr2(const char *big, const char *little)
{
	size_t lrunner;
	size_t brunner;

	brunner = 0;
	if (little[0] == '\0')
		return ((char*)&big[0]);
	while (big[brunner] != '\0')
	{
		if (big[brunner] == little[0])
		{
			lrunner = 0;
			while (little[lrunner] == big[brunner])
			{
				if (little[lrunner] == '\0')
					return ((char*)&big[brunner - lrunner]);
				lrunner++;
				brunner++;
			}
			brunner -= lrunner;
		}
		brunner++;
	}
	return (NULL);
}

void checkArguments(int argc, char **argv, t_argFlags **flags, t_player **players)
{
	int n;

	n = 1;
	if (argc == 1)
		ft_usage();
	while (n < argc)
	{
		if (ft_strstr2(argv[n], ".cor"))
		{
			ft_get_champ(players, argv, &n);
		}
		else if (*argv[n] == '-')
			ft_check_flags(players, argv, &n, *flags);
		else
			printf("ERROR\n");
		n++;
	}
	if (!*players)
	{
		printf("ERROR\n");
	}
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
	t_vizData       vizData;
	int    cycleToDie;
	int    maxchecks;
	int             n;
	t_argFlags  *flags;

	flags = ft_memalloc(sizeof(t_argFlags));
	checkArguments(argc, argv, &flags, &players);
	n = 0;
	maxchecks = 1;
	processes = NULL;
	initProcesses(&processes, players);
	initMap(map, &vizData, players);
	if (!flags->d && VIZ)
		initVis();
	initfunc(array);
	t_player    *p;
	cycleToDie = CYCLE_TO_DIE;
	i = 0;
	c = 0;
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
		if (flags->d && i == flags->d)
			break ;
		if (cycleToDie <= 0)
		{
			if (VIZ)
				endwin();
			ft_printf("GAME OVER on cycle %d\ncycle to die = %d\nprocesses: %d\n", i, cycleToDie, counter(processes));
			return 0;
		}
		int br = 1000;
		if (!flags->d && VIZ)
		{
			visualize(map, processes, &vizData);
			mvwprintw(stdscr, 0, 196, "%d", i);
			mvwprintw(stdscr, 3, 196, "                       ");
			mvwprintw(stdscr, 3, 196, "live count: %d", players->liveCount);
			mvwprintw(stdscr, 4, 196, "                       ");
			mvwprintw(stdscr, 4, 196, "last alive: %d", players->lastAlive);
			mvwprintw(stdscr, 5, 196, "                       ");
			mvwprintw(stdscr, 5, 196, "max checks: %d", maxchecks);
			mvwprintw(stdscr, 6, 196, "                   ");
			mvwprintw(stdscr, 6, 196, "cycle to die: %d", cycleToDie);
			if (!vizData.space)
			{
				while (c != 113 && c != 115 && c != 32)
					c = getch();
				if (c == 113)
					break ;
				else if (c == 115)
					nodelay(stdscr, false);
				else
					vizData.space = true;
			}
			else
			{
				nodelay(stdscr, true);
				c = getch();
				if (c == 113)
					break ;
				else if (c == 32)
				{
					vizData.space = false;
					nodelay(stdscr, false);
				}
			}
			c = 0;
		}
		runProcesses(&processes, map, array, i, players, &vizData);
		i++;
		n++;
	}
	if (!flags->d && VIZ)
		endwin();
	else
		dump(map);
	return 0;
}
