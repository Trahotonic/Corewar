# include "./../inc/corewar.h"

void	init_all()
{

}

int     main(int argc, char **argv)
{
	t_viz_data		vizData;
	t_arg_flags		*flags;
	t_proc_pack		*pp;

	pp = (t_proc_pack*)malloc(sizeof(t_proc_pack));
	flags = ft_memalloc(sizeof(t_arg_flags));
	checkArguments(argc, argv, &flags, &pp->players);
	pp->n = 0;
	pp->maxchecks = 1;
	pp->processes = NULL;
	init_processes(&pp->processes, pp->players);
	init_map(pp->map, &vizData, pp->players);
	if (!flags->v)
		introduce(pp->players);
	if (!flags->d && flags->v)
	{
//		system("afplay -v 0.3 ./Benny-hill-theme.mp3 &");
		init_vis();
		vizData.players = pp->players;
	}
	initfunc(pp->array);
	t_player    *p;
	pp->cycleToDie = CYCLE_TO_DIE;
	pp->i = 0;
	pp->c = 0;
	while (1)
	{
		if (pp->n == pp->cycleToDie && check21(pp->players))
		{
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
		else if (pp->n == pp->cycleToDie)
		{
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
		if (!pp->processes)
		{
			if (flags->v)
				visualize(pp->map, pp->processes, &vizData);
			pick_winner(pp->players, flags->v, get_players(pp->players));
			printEnd(vizData.print);
			return 0;
		}
		if (flags->d && pp->i == flags->d)
			break ;
		if (pp->cycleToDie <= 0)
		{
			kill_them_all(&pp->processes);
			if (flags->v)
				visualize(pp->map, pp->processes, &vizData);
			pick_winner(pp->players, flags->v, get_players(pp->players));
			printEnd(vizData.print);
			return 0;
		}
		if (!flags->d && flags->v)
		{
			vizData.cycleDelta = CYCLE_DELTA;
			vizData.cycleToDie = pp->cycleToDie;
			vizData.i = pp->i;
			visualize(pp->map, pp->processes, &vizData);
			if (!vizData.space)
			{
				while (pp->c != 113 && pp->c != 115 && pp->c != 32)
					pp->c = getch();
				if (pp->c == 113)
					break ;
				else if (pp->c == 115)
					nodelay(stdscr, false);
				else
					vizData.space = true;
			}
			else
			{
				nodelay(stdscr, true);
				pp->c = getch();
				if (pp->c == 113)
					break ;
				else if (pp->c == 32)
				{
					vizData.space = false;
					nodelay(stdscr, false);
				}
			}
			pp->c = 0;
		}
		pp->player = pp->players;
		pp->processes_deep = &pp->processes;
		pp->vizData = &vizData;
		runProcesses(pp->map, pp->array, pp);
		pp->i++;
		pp->n++;
	}
	if (!flags->d && flags->v)
	{
//		system("killall afplay");
		endwin();
	}
	else
		dump(pp->map, pp->players);
	return 0;
}
