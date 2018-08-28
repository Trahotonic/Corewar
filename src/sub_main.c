//
// Created by Roman KYSLYY on 8/28/18.
//

#include "../inc/corewar.h"

void	introduce(t_player *players)
{
	int m;

	m = 0;
	ft_printf("Introducing contestants...\n");
	while (players)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", m + 1,
				  players->h.prog_size, players->h.prog_name,
				  players->h.comment);
		players = players->next;
		++m;
	}
}

void kill_them_all(t_process **process)
{
	t_process *tmp;

	tmp = *process;
	while(tmp)
	{
		*process = tmp->next;
		free(tmp);
		tmp = *process;
	}
}

static void	get_win_and_max(t_player **winner, int *max, t_player *players)
{
	t_player	*ptr;

	ptr = players;
	while (players)
	{
		if (players->lastAlive > *max)
		{
			*max = players->lastAlive;
			*winner = players;
		}
		players = players->next;
	}
	while (ptr)
	{
		if (ptr->lastAlive == *max)
			*winner = ptr;
		ptr = ptr->next;
	}
}

int	pick_winner(t_player *players, int vis, int pl)
{
	t_player	*winner;
	int 		max;

	if (vis)
		nodelay(stdscr, false);
	winner = players;
	max = players->lastAlive;
	get_win_and_max(&winner, &max, players->next);
	if (!vis)
		return (ft_printf("Contestant %d, \"%s\", has won !\n", winner->num,
						  winner->h.prog_name));
	else
	{
		attron(COLOR_PAIR(WHITE_CUNT));
		mvwprintw(stdscr, 11 + (pl * 4) + 14, 199, "The winner is : ");
		mvwprintw(stdscr, 11 + (pl * 4) + 16, 199, "Press any key to finish");
		attroff(COLOR_PAIR(WHITE_CUNT));
		attron(COLOR_PAIR(6 + winner->num));
		mvwprintw(stdscr, 11 + (pl * 4) + 14, 215, "%s", winner->h.prog_name);
		attroff(COLOR_PAIR(6 + winner->num));
		getch();
		return (endwin());
	}
}
