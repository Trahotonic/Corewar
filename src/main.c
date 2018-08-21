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

void	runProcesses(t_process **processes, unsigned char map[], functions_t array[], int i, t_player *player, t_vizData *vizData)
{
	t_process	*go;
	int 		n;
	char 		tmp[3];

	tmp[2] = '\0';
	go = *processes;
	n = 0;
	if (i == 9690)
	{

	}
	while (go)
	{
		if (go->proc_num == 28)
		{

		}
		if (go->pl_number != 1 && go->pl_number != 2 && go->pl_number != 3 && go->pl_number != 4)
		{

		}
		if (go->invalidAgr)
		{
			go->invalidAgr = 0;
			go->cur_pos = (go->cur_pos + 2) % (MEM_SIZE * 2);
			go = go->next;
			continue ;
		}
		if (go->com2 == 0)
		{
			tmp[0] = map[go->cur_pos];
			tmp[1] = map[go->cur_pos + 1];
			go->com2 = ft_atoi_base(tmp, 16);
			while (n < 16 && go->com2 != array[n].name2)
				++n;
			if (n == 16)
			{
				go->invalidAgr = 1;
				go->com2 = 0;
				n = 0;
				continue ;
			}
			go->cycle_todo = array[n].cycles;
			go->codage = array[n].codage;
			n = 0;
		}
		if (go->cycle_todo > 0)
			--go->cycle_todo;
		if ((go->com2 > 0 && go->com2 <= 16)
		    && !go->cycle_todo)
		{
			readShit(map, go);
			if (ft_strequ(go->arg1, "ff09"))
			{

			}
			if (go->com2 == 1)
				live(go, i, player);
			else if (go->com2 == 2)
				ld(go, map);
			else if (go->com2 == 3)
				st(go, map, vizData);
			else if (go->com2 == 4)
				add(go);
			else if (go->com2 == 5)
				sub(go);
			else if (go->com2 == 6)
				and(go);
			else if (go->com2 == 7)
				or(go);
			else if (go->com2 == 8)
				xor(go);
			else if (go->com2 == 9)
				zjmp(go);
			else if (go->com2 == 10)
				ldi(go, map);
			else if (go->com2 == 11)
				sti(go, map, vizData);
			else if (go->com2 == 12)
				fork_c(processes, go);
			else if (go->com2 == 13)
				lld(go, map);
			else if (go->com2 == 14)
				lldi(go, map);
			else if (go->com2 == 15)
				lfork(processes, go);
			else if (go->com2 == 16)
				aff(go, map);
			go->com2 = 0;
			go->iC = 0;
		}
		go = go->next;
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
		ptr = ptr->next;
	}
}

int 	check21(t_player *players)
{
	t_player    *ptr;
	int k;

	k = 0;
	ptr = players;
	while (players)
	{
		k += players->liveCount;
		if (k >= NBR_LIVE)
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

	tmp = (t_player*)malloc(sizeof(t_player));
	tmp->num = num;
	tmp->fd = open(champ, O_RDONLY);
	if (tmp->fd == -1)
		exit(printf("ERROR\n"));
	tmp->next = NULL;
	tmp->lastAlive = 0;
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
		printf("ERROR\n");
}

int     main(int argc, char **argv)
{
	unsigned char	map[MEM_SIZE * 2];
	t_process		*processes;
	int				i;
	int				c;
	functions_t		array[16];
	t_player		*players;
	t_vizData		vizData;
	int				cycleToDie;
	int				maxchecks;
	int				n;
	t_argFlags		*flags;

	flags = ft_memalloc(sizeof(t_argFlags));
	checkArguments(argc, argv, &flags, &players);
	n = 0;
	maxchecks = 1;
	processes = NULL;
	initProcesses(&processes, players);
	initMap(map, &vizData, players);
	if (!flags->d && VIZ)
	{
		system("afplay -v 0.3 ./Benny-hill-theme.mp3 &");
		initVis();
		vizData.players = players;
	}
	initfunc(array);
	t_player    *p;
	cycleToDie = CYCLE_TO_DIE;
	i = 0;
	c = 0;
	while (1)
	{
		if (i == 10367)
		{

		}
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
			{
				system("killall afplay");
				endwin();
			}
			ft_printf("GAME OVER on cycle %d\ncycle to die = %d\nprocesses: %d\n", i, cycleToDie, counter(processes));
			return 0;
		}
		if (flags->d && i == flags->d)
			break ;
		if (cycleToDie <= 0)
		{
			if (VIZ)
			{
				system("killall afplay");
				endwin();
			}
			ft_printf("GAME OVER on cycle %d\ncycle to die = %d\nprocesses: %d\n", i, cycleToDie, counter(processes));
			return 0;
		}
		int br = 20137;
		if (!flags->d && VIZ)
		{
			vizData.cycleDelta = CYCLE_DELTA;
			vizData.cycleToDie = cycleToDie;
			vizData.i = i;
			visualize(map, processes, &vizData);
//			mvwprintw(stdscr, 0, 196, "%d", i);
//			mvwprintw(stdscr, 3, 196, "                       ");
//			mvwprintw(stdscr, 3, 196, "live count: %d", players->liveCount);
//			mvwprintw(stdscr, 4, 196, "                       ");
//			mvwprintw(stdscr, 4, 196, "last alive: %d", players->lastAlive);
//			mvwprintw(stdscr, 5, 196, "                       ");
//			mvwprintw(stdscr, 5, 196, "max checks: %d", maxchecks);
//			mvwprintw(stdscr, 6, 196, "                   ");
//			mvwprintw(stdscr, 6, 196, "cycle to die: %d", cycleToDie);
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
	{
		system("killall afplay");
		endwin();
	}
	else
		dump(map);
	return 0;
}
