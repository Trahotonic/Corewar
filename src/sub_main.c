/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:39:08 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 16:39:20 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void		introduce(t_player *players)
{
	int	m;

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

void		kill_them_all(t_process **process)
{
	t_process	*tmp;

	tmp = *process;
	while (tmp)
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
		if (players->last_alive > *max)
		{
			*max = players->last_alive;
			*winner = players;
		}
		players = players->next;
	}
	while (ptr)
	{
		if (ptr->last_alive == *max)
		{
			*winner = ptr;
			if (*max != 0)
				return ;
		}
		ptr = ptr->next;
	}
}

int			pick_winner(t_player *players, int vis, int pl)
{
	t_player	*winner;
	int			max;

	winner = players;
	max = players->last_alive;
	get_win_and_max(&winner, &max, players);
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
		nodelay(stdscr, false);
		getch();
		system("killall afplay");
		return (endwin());
	}
}

int			check21(t_player *players)
{
	t_player	*ptr;
	int			k;

	k = 0;
	ptr = players;
	while (players)
	{
		k += players->live_count;
		if (k >= NBR_LIVE)
		{
			players->live_count = 0;
			while (ptr)
			{
				ptr->live_count = 0;
				ptr = ptr->next;
			}
			return (1);
		}
		players = players->next;
	}
	return (0);
}
