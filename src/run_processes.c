/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:36:42 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 16:36:49 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

static int	check_invalid_1(t_process **go)
{
	if ((*go)->invalid_agr)
	{
		(*go)->invalid_agr = 0;
		(*go)->cur_pos = ((*go)->cur_pos + 2) % ((MEM_SIZE) * 2);
		(*go) = (*go)->next;
		return (1);
	}
	return (0);
}

static int	check_invalid_2(t_process *go, char tmp[], unsigned char map[],
					t_functions array[])
{
	int n;

	n = 0;
	if (go->com2 == 0)
	{
		tmp[0] = map[go->cur_pos];
		tmp[1] = map[go->cur_pos + 1];
		go->com2 = ab(tmp, 16);
		while (n < 16 && go->com2 != array[n].name2)
			++n;
		if (n == 16)
		{
			go->invalid_agr = 1;
			go->com2 = 0;
			return (1);
		}
		go->cycle_todo = array[n].cycles;
		go->codage = array[n].codage;
	}
	return (0);
}

static void	pick_function_2(t_process *go, t_proc_pack *proc_pack,
						unsigned char map[])
{
	if (go->com2 == 12)
		fork_c(proc_pack->processes_deep, go);
	else if (go->com2 == 13)
		lld(go, map);
	else if (go->com2 == 14)
		lldi(go, map);
	else if (go->com2 == 15)
		lfork(proc_pack->processes_deep, go);
	else if (go->com2 == 16)
		aff(go, proc_pack->viz_data);
}

static void	pick_function_1(t_process *go, t_proc_pack *proc_pack,
					unsigned char map[])
{
	if (go->com2 == 1)
		live(go, proc_pack->i, proc_pack->player, *proc_pack->flags);
	else if (go->com2 == 2)
		ld(go, map);
	else if (go->com2 == 3)
		st(go, map, proc_pack->viz_data);
	else if (go->com2 == 4)
		add(go);
	else if (go->com2 == 5)
		sub(go);
	else if (go->com2 == 6)
		and(go);
	else if (go->com2 == 7)
		or(go);
	else if (go->com2 == 8)
		xor(go);
	else if (go->com2 == 9)
		zjmp(go);
	else if (go->com2 == 10)
		ldi(go, map);
	else if (go->com2 == 11)
		sti(go, map, proc_pack->viz_data);
	else
		pick_function_2(go, proc_pack, map);
}

void		run_processes(unsigned char *map, t_functions *array,
						t_proc_pack *proc_pack)
{
	t_process	*go;
	char		tmp[3];

	tmp[2] = '\0';
	go = *proc_pack->processes_deep;
	while (go)
	{
		if (check_invalid_1(&go) || check_invalid_2(go, tmp, map, array))
			continue ;
		if (go->cycle_todo > 0)
			--go->cycle_todo;
		if ((go->com2 > 0 && go->com2 <= 16) && !go->cycle_todo)
		{
			read_shit(map, go);
			pick_function_1(go, proc_pack, map);
			go->com2 = 0;
			go->i_c = 0;
		}
		go = go->next;
	}
}
