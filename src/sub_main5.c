/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:58:08 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 16:58:14 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	init_all(t_proc_pack **pp, int argc, char **argv, t_viz_data *viz_data)
{
	*pp = (t_proc_pack*)malloc(sizeof(t_proc_pack));
	(*pp)->flags = ft_memalloc(sizeof(t_arg_flags));
	check_arguments(argc, argv, &(*pp)->flags, &(*pp)->players);
	(*pp)->n = 0;
	(*pp)->maxchecks = 1;
	(*pp)->processes = NULL;
	init_processes(&(*pp)->processes, (*pp)->players);
	init_map((*pp)->map, viz_data, (*pp)->players);
	if (!(*pp)->flags->v)
		introduce((*pp)->players);
	if (!(*pp)->flags->d && (*pp)->flags->v)
	{
		init_vis();
		(viz_data)->players = (*pp)->players;
	}
	initfunc((*pp)->array);
	initfunc2((*pp)->array);
	(*pp)->cycle_to_die = CYCLE_TO_DIE;
	(*pp)->i = 0;
	(*pp)->c = 0;
}

int		end_game(t_proc_pack *pp, t_viz_data *viz_data)
{
	kill_them_all(&pp->processes);
	pp->viz_data->i = pp->i;
	if (pp->flags->v)
		visualize(pp->map, pp->processes, viz_data);
	if (pp->flags->a)
	{
		ft_printf("Aff: ");
		print_end(viz_data->print);
		ft_printf("\n");
	}
	pick_winner(pp->players, pp->flags->v, get_players(pp->players));
	return (0);
}

void	if21(t_proc_pack *pp)
{
	t_player		*p;

	p = pp->players;
	while (p)
	{
		p->live_count = 0;
		p = p->next;
	}
	pp->cycle_to_die -= CYCLE_DELTA;
	pp->maxchecks = 1;
	superkill(&pp->processes, pp->players);
	kill(pp->processes);
	pp->n = 0;
}

void	not21(t_proc_pack *pp)
{
	t_player		*p;

	p = pp->players;
	while (p)
	{
		p->live_count = 0;
		p = p->next;
	}
	if (pp->maxchecks == MAX_CHECKS)
	{
		pp->cycle_to_die -= CYCLE_DELTA;
		pp->maxchecks = 1;
	}
	else
		pp->maxchecks++;
	superkill(&pp->processes, pp->players);
	kill(pp->processes);
	pp->n = 0;
}

int		end_main(t_proc_pack *pp)
{
	if (!pp->flags->di && pp->flags->v)
		endwin();
	else if (pp->flags->di)
		dump(pp->map);
	return (0);
}
