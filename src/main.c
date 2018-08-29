# include "./../inc/corewar.h"

void	init_all(t_proc_pack **pp, int argc, char **argv, t_viz_data *viz_data)
{
	*pp = (t_proc_pack*)malloc(sizeof(t_proc_pack));
	(*pp)->flags = ft_memalloc(sizeof(t_arg_flags));
	checkArguments(argc, argv, &(*pp)->flags, &(*pp)->players);
	(*pp)->n = 0;
	(*pp)->maxchecks = 1;
	(*pp)->processes = NULL;
	init_processes(&(*pp)->processes, (*pp)->players);
	init_map((*pp)->map, viz_data, (*pp)->players);
	if (!(*pp)->flags->v)
		introduce((*pp)->players);
	if (!(*pp)->flags->d && (*pp)->flags->v)
	{
//		system("afplay -v 0.3 ./Benny-hill-theme.mp3 &");
		init_vis();
		(viz_data)->players = (*pp)->players;
	}
	initfunc((*pp)->array);
	t_player    *p;
	(*pp)->cycleToDie = CYCLE_TO_DIE;
	(*pp)->i = 0;
	(*pp)->c = 0;
}

int 	endGame(t_proc_pack *pp, t_viz_data *vizData)
{
	kill_them_all(&pp->processes);
	if (pp->flags->v)
		visualize(pp->map, pp->processes, vizData);
	pick_winner(pp->players, pp->flags->v, get_players(pp->players));
	printEnd(vizData->print);
	return 0;
}

void	if21(t_proc_pack *pp)
{
	t_player		*p;

	p = pp->players;
	while (p)
	{
		p->liveCount = 0;
		p = p->next;
	}
	pp->cycleToDie -= CYCLE_DELTA;
	pp->maxchecks = 1;
	superkill(&pp->processes, pp->i, pp->players);
	kill(pp->processes);
	pp->n = 0;
}

void	not21(t_proc_pack *pp)
{
	t_player		*p;

	p = pp->players;
	while (p)
	{
		p->liveCount = 0;
		p = p->next;
	}
	if (pp->maxchecks == MAX_CHECKS)
	{
		pp->cycleToDie -= CYCLE_DELTA;
		pp->maxchecks = 1;
	}
	else
		pp->maxchecks++;
	superkill(&pp->processes, pp->i, pp->players);
	kill(pp->processes);
	pp->n = 0;
}

int 	partvis(t_proc_pack *pp, t_viz_data (*vizData))
{
	if (!vizData->space)
	{
		while (pp->c != 113 && pp->c != 115 && pp->c != 32)
			pp->c = getch();
		if (pp->c == 113)
			return (1);
		else if (pp->c == 115)
			nodelay(stdscr, false);
		else
			vizData->space = true;
	}
	else
	{
		nodelay(stdscr, true);
		pp->c = getch();
		if (pp->c == 113)
			return (1);
		else if (pp->c == 32)
		{
			vizData->space = false;
			nodelay(stdscr, false);
		}
	}
	return (0);
}

int 	breakVis(t_proc_pack *pp, t_viz_data *vizData)
{
	if (!pp->flags->d && pp->flags->v)
	{
		vizData->i = pp->i;
		visualize(pp->map, pp->processes, vizData);
		if (partvis(pp, vizData))
			return (1);
		pp->c = 0;
	}
	return (0);
}

int	end_main(t_proc_pack *pp)
{
	if (!pp->flags->d && pp->flags->v)
	{
//		system("killall afplay");
		endwin();
	}
	else
		dump(pp->map, pp->players);
	return (0);
}

void		iterate(t_proc_pack *pp, t_viz_data *vizData)
{
	pp->player = pp->players;
	pp->processes_deep = &pp->processes;
	pp->vizData = vizData;
	runProcesses(pp->map, pp->array, pp);
	pp->i++;
	pp->n++;
}

int     main(int argc, char **argv)
{
	t_viz_data		vizData;
	t_proc_pack		*pp;

	init_all(&pp, argc, argv, &vizData);
	while (1)
	{
		if (pp->n == pp->cycleToDie && check21(pp->players))
			if21(pp);
		else if (pp->n == pp->cycleToDie)
			not21(pp);
		vizData.cycleDelta = CYCLE_DELTA;
		vizData.cycleToDie = pp->cycleToDie;
		if (!pp->processes)
			return endGame(pp, &vizData);
		if (pp->flags->d && pp->i == pp->flags->d)
			break ;
		if (pp->cycleToDie <= 0)
			return endGame(pp, &vizData);
		if (breakVis(pp, &vizData))
			break ;
		iterate(pp, &vizData);
	}
	return (end_main(pp));
}
