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
	ft_printf(1, "Introducing contestants...\n");
	while (players)
	{
		ft_printf(1, "* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				players->player_number * -1,
				players->h.prog_size, players->h.prog_name,
				players->h.comment);
		players = players->next;
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
	if (*max != 0)
		return ;
	*winner = ptr;
}

int			pick_winner(t_player *players, int vis, int pl, t_proc_pack *pp)
{
	t_player	*winner;
	int			max;

	winner = (*pp).flags->last;
	max = players->last_alive;
	get_win_and_max(&winner, &max, players);
	if (!vis)
		return (ft_printf(1, "Player %d, (%s) won.\n",
						winner->player_number * -1,
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
