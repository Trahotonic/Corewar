//
// Created by Roman KYSLYY on 8/28/18.
//

#include "../inc/corewar.h"


int		get_players(t_player *players)
{
	int n;

	n = 0;
	while (players)
	{
		players = players->next;
		++n;
	}
	return (n);
}


int 	get_processes(t_process *proc)
{
	int n = 0;

	while (proc)
	{
		++n;
		proc = proc->next;
	}
	return (n);
}


void	printEnd(t_char *print)
{
	while (print)
	{
		ft_printf("%c", print->c);
		print = print->next;
	}
}

