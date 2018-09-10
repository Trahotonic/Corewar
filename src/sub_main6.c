/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:08:25 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/09/10 16:08:25 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		partvis(t_proc_pack *pp, t_viz_data *viz_data)
{
	if (!viz_data->space)
	{
		while (pp->c != 113 && pp->c != 115 && pp->c != 32)
			pp->c = getch();
		if (pp->c == 113)
			return (1);
		else if (pp->c == 115)
			nodelay(stdscr, false);
		else
			viz_data->space = true;
	}
	else
	{
		nodelay(stdscr, true);
		pp->c = getch();
		if (pp->c == 113)
			return (1);
		else if (pp->c == 32)
		{
			viz_data->space = false;
			nodelay(stdscr, false);
		}
	}
	return (0);
}

int		break_vis(t_proc_pack *pp, t_viz_data *viz_data)
{
	if (!pp->flags->d && pp->flags->v)
	{
		viz_data->i = pp->i;
		visualize(pp->map, pp->processes, viz_data);
		if (partvis(pp, viz_data))
			return (1);
		pp->c = 0;
	}
	return (0);
}

void	iterate(t_proc_pack *pp, t_viz_data *viz_data)
{
	pp->player = pp->players;
	pp->processes_deep = &pp->processes;
	pp->viz_data = viz_data;
	run_processes(pp->map, pp->array, pp);
	pp->i++;
	pp->n++;
}

void	shmatok(t_proc_pack *pp, t_viz_data *viz_data)
{
	if (pp->n == pp->cycle_to_die && check21(pp->players))
		if21(pp);
	else if (pp->n == pp->cycle_to_die)
		not21(pp);
	viz_data->cycle_delta = CYCLE_DELTA;
	viz_data->cycle_to_die = pp->cycle_to_die;
}

int		kusok(t_proc_pack *pp, t_viz_data *viz_data)
{
	pp->cycle_to_die -= CYCLE_DELTA;
	iterate(pp, viz_data);
	shmatok(pp, viz_data);
	if (!pp->processes)
		return (end_game(pp, viz_data));
	if (pp->flags->d && pp->i == pp->flags->d)
		return (end_game(pp, viz_data));
	if (pp->cycle_to_die <= 0)
		return (end_game(pp, viz_data));
	if (pp->flags->v && pp->i >= pp->flags->vi)
		if (break_vis(pp, viz_data))
			return (end_game(pp, viz_data));
	return (end_game(pp, viz_data));
}
