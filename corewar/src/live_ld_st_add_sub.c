/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_ld_st_add_sub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:21:08 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 15:21:15 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	live(t_process *pro, int i, t_player *pl, t_arg_flags *q)
{
	char		*tmp;

	tmp = ft_uitoa_base2(pl->player_number, 16);
	while (pl)
	{
		if (ft_strequ(tmp, pro->arg1))
		{
			pl->last_alive = i + 1;
			if (!q->v && q->l)
				ft_printf(1, "A process shows that player %d (%s) is alive.\n",
					pl->player_number * -1, pl->h.prog_name);
			++pl->live_count_p;
			q->last = pl;
		}
		if (pl->player_number == pro->pl_num)
			pl->live_count++;
		ft_strdel(&tmp);
		pl = pl->next;
		if (pl)
			tmp = ft_uitoa_base2(pl->player_number, 16);
	}
	ft_strdel(&tmp);
	pro->alive = 1;
	pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
}

void	ld_sup(t_process *pro, unsigned char *map)
{
	int		k;
	int		n;
	char	*arg1;

	k = ((((short)ab(pro->arg1, 16)) % (IDX_MOD))
		* 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	n = 0;
	arg1 = ft_strnew(8);
	while (n < 8)
	{
		k %= ((MEM_SIZE) * 2);
		arg1[n++] = map[k++];
	}
	pro->reg[ab(pro->arg2, 16) - 1] = ab(arg1, 16);
	ft_strdel(&arg1);
}

void	ld(t_process *pro, unsigned char *map)
{
	if (ft_strlen(pro->arg3) == 2)
		pro->iterator -= 2;
	if (ft_strlen(pro->arg3) == 4)
		pro->iterator -= 4;
	if (ft_strlen(pro->arg3) == 8)
		pro->iterator -= 8;
	if (ft_strlen(pro->arg1) == 2 || ft_strlen(pro->arg1) == 0
		|| ft_strlen(pro->arg2) != 2 || pro->i_c == 1)
	{
		pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
		pro->iterator = 0;
		return ;
	}
	if (ft_strlen(pro->arg1) == 8)
		pro->reg[ab(pro->arg2, 16) - 1] = (unsigned int)ab(pro->arg1, 16);
	else if (ft_strlen(pro->arg1) == 4)
		ld_sup(pro, map);
	if (pro->reg[ab(pro->arg2, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
	pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
}

void	add(t_process *pro)
{
	pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
	if (ft_strlen(pro->arg1) != 2 || ft_strlen(pro->arg2) != 2
		|| ft_strlen(pro->arg3) != 2 || pro->i_c == 1)
		return ;
	pro->reg[ab(pro->arg3, 16) - 1] =
			pro->reg[ab(pro->arg1, 16) - 1] + pro->reg[ab(pro->arg2, 16) - 1];
	if (pro->reg[ab(pro->arg3, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
	pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
}

void	sub(t_process *pro)
{
	pro->cur_pos = (pro->iterator + pro->cur_pos) % (MEM_SIZE * 2);
	pro->iterator = 0;
	if (ft_strlen(pro->arg1) != 2 || ft_strlen(pro->arg2) != 2
		|| ft_strlen(pro->arg3) != 2 || pro->i_c == 1)
		return ;
	pro->reg[ab(pro->arg3, 16) - 1] =
			pro->reg[ab(pro->arg1, 16) - 1] - pro->reg[ab(pro->arg2, 16) - 1];
	if (pro->reg[ab(pro->arg3, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
	pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
}
