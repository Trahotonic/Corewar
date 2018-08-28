# include "./../inc/corewar.h"

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
		++i;
		while (tmp->next)
		{
			(tmp) = (tmp)->next;
			++i;
		}
		tmp->next = ft_player_create(argv[*n], i);
	}
}

void  ft_check_flag_d(t_player **players, char **argv, int *n, t_arg_flags *flags)
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

void  ft_check_flag_vi(t_player **players, char **argv, int *n, t_arg_flags *flags)
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
void ft_flag_n_sup(t_player *tmp, t_player **players, char **argv, int n)
{
	int i;

	i = 1;
	if (!(tmp))
	{
		(*players) = ft_player_create(argv[n + 1], i);
		(*players)->playerNumber = ft_atoi(argv[n]);
	}
	else
	{
		i++;
		while ((tmp)->next)
		{
			if (tmp->playerNumber == ft_atoi(argv[n]))
				exit(printf("Error same number in players\n"));
			tmp = (tmp)->next;
			i++;
		}
		if (tmp->playerNumber == ft_atoi(argv[n]))
			exit(printf("Error same number in players\n"));
		(tmp)->next = ft_player_create(argv[n + 1], i);
		(tmp)->next->playerNumber = ft_atoi(argv[n]);
	}
}

void  ft_check_flag_n(t_player **players, char **argv, int *n)
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
				exit(printf("Player number should be from -4 to -1 \n"));
			++i;
		}
		if (!argv[*n + 1] || (ft_atoi(argv[*n]) > -1 || ft_atoi(argv[*n]) < -4))
			exit(printf("Player number should be from -4 to -1 \n"));
		ft_flag_n_sup(tmp, players, argv, *n);
		(*n)++;
	}
	else
		exit(printf("Player number should be from -4 to -1 \n"));
}

void  ft_check_flags(t_player **players, char **argv, int *n, t_arg_flags *flags)
{
	if (ft_strequ(argv[*n], "-d"))
		ft_check_flag_d(players, argv, n, flags);
	else if (ft_strequ(argv[*n], "-vi"))
		ft_check_flag_vi(players, argv, n, flags);
	else if (ft_strequ(argv[*n], "-v"))
		flags->v = 1;
	else if (ft_strequ(argv[*n], "-n"))
		ft_check_flag_n(players, argv, n);
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

void checkArguments(int argc, char **argv, t_arg_flags **flags, t_player **players)
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

void	printEnd(t_char *print)
{
	while (print)
	{
		ft_printf("%c", print->c);
		print = print->next;
	}
}

int     main(int argc, char **argv)
{
	unsigned char	map[MEM_SIZE * 2];
	t_process		*processes;
	int				i;
	int				c;
	functions_t		array[16];
	t_player		*players;
	t_viz_data		vizData;
	int				cycleToDie;
	int				maxchecks;
	int				n;
	t_arg_flags		*flags;
	t_proc_pack		*proc_pack;

	proc_pack = (t_proc_pack*)malloc(sizeof(t_proc_pack));
	flags = ft_memalloc(sizeof(t_arg_flags));
	checkArguments(argc, argv, &flags, &players);
	n = 0;
	maxchecks = 1;
	processes = NULL;
	init_processes(&processes, players);
	init_map(map, &vizData, players);
	if (!flags->v)
		introduce(players);
	if (!flags->d && flags->v)
	{
//		system("afplay -v 0.3 ./Benny-hill-theme.mp3 &");
		init_vis();
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
			if (flags->v)
				visualize(map, processes, &vizData);
			pick_winner(players, flags->v, get_players(players));
			printEnd(vizData.print);
			return 0;
		}
		if (flags->d && i == flags->d)
			break ;
		if (cycleToDie <= 0)
		{
			kill_them_all(&processes);
			if (flags->v)
				visualize(map, processes, &vizData);
			pick_winner(players, flags->v, get_players(players));
			printEnd(vizData.print);
			return 0;
		}
		int br = 20137;
		if (!flags->d && flags->v)
		{
			vizData.cycleDelta = CYCLE_DELTA;
			vizData.cycleToDie = cycleToDie;
			vizData.i = i;
			visualize(map, processes, &vizData);
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
		proc_pack->i = i;
		proc_pack->player = players;
		proc_pack->processes = &processes;
		proc_pack->vizData = &vizData;
		runProcesses(map, array, proc_pack);
		i++;
		n++;
	}
	if (!flags->d && flags->v)
	{
//		system("killall afplay");
		endwin();
	}
	else
		dump(map, players);
	return 0;
}
