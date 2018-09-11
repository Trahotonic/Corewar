/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:08:48 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 15:08:49 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

t_process	*pro_creator(t_player *players)
{
	int			n;
	t_process	*tmp;

	n = 0;
	tmp = (t_process *)malloc(sizeof(t_process));
	tmp->carry = 0;
	tmp->pl_num = players->player_number;
	tmp->pl_number = players->num;
	tmp->alive = 0;
	tmp->i_c = 0;
	tmp->com2 = 0;
	tmp->cycle_todo = 0;
	tmp->iterator = 0;
	tmp->proc_num = 1;
	while (n < 16)
		tmp->reg[n++] = 0;
	tmp->reg[0] = players->player_number;
	tmp->t_dir = 0;
	tmp->invalid_agr = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void		init_processes(t_process **processes, t_player *players)
{
	t_process	*tmp;
	int			idx;
	int			count;

	idx = 1;
	count = get_count(players);
	check_pl_number(players);
	while (players)
	{
		tmp = pro_creator(players);
		tmp->cur_pos = get_start(count, idx);
		if (*processes == NULL)
			*processes = tmp;
		else
		{
			(*processes)->prev = tmp;
			tmp->next = *processes;
			*processes = tmp;
		}
		++idx;
		players = players->next;
	}
}
