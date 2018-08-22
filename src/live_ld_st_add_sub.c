//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

void  live(t_process *pro,int i, t_player *pl)
{
	char *tmp;
	t_player *tmppl;

	tmppl = pl;
	while (tmppl)
	{
		if (tmppl->playerNumber == pro->pl_num)
			tmppl->liveCount++;
		tmppl = tmppl->next;
	}
	tmp = ft_uitoa_base2(pl->playerNumber, 16);
	while(pl && !ft_strequ(tmp, pro->arg1))
	{
		ft_strdel(&tmp);
		pl = pl->next;
		if (pl)
			tmp = ft_uitoa_base2(pl->playerNumber, 16);
	}
	ft_strdel(&tmp);
	pro->alive = 1;
	if (pl)
		pl->lastAlive = i;
	pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
	pro->iterator = 0;
}

void ld_sup(t_process *pro, unsigned char* map)
{
	int  k;
	int  n;
	char *arg1;
	k = ((((short)ft_atoi_base(pro->arg1, 16)) % IDX_MOD)
		 * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	n = 0;
	arg1 = ft_strnew(8);
	while (n < 8)
	{
		k %= (MEM_SIZE * 2);
		arg1[n++] = map[k++];
	}
	pro->reg[ft_atoi_base(pro->arg2, 16) - 1] = ft_atoi_base(arg1, 16);
}

void  ld(t_process *pro, unsigned char *map)
{
	if (ft_strlen(pro->arg3) == 2)
		pro->iterator -= 2;
	if (ft_strlen(pro->arg3) == 4)
		pro->iterator -= 4;
	if (ft_strlen(pro->arg3) == 8)
		pro->iterator -= 8;
	if (ft_strlen(pro->arg1) == 2 || ft_strlen(pro->arg1) == 0
		|| ft_strlen(pro->arg2) != 2 || pro->iC == 1)
	{
		pro->cur_pos = (pro->iterator + pro->cur_pos) % (MEM_SIZE * 2);
		pro->iterator = 0;
		return ;
	}
	if (ft_strlen(pro->arg1) == 8)
		pro->reg[ft_atoi_base(pro->arg2, 16) - 1] =
				(unsigned int)ft_atoi_base(pro->arg1, 16);
	else if (ft_strlen(pro->arg1) == 4)
		ld_sup(pro, map);
	if (pro->reg[ft_atoi_base(pro->arg2, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
	pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
	pro->iterator = 0;
}

void st_sup(t_process *pro, unsigned char *map, t_viz_data *vizData)
{
	int    n;
	int    k;
	char   *tmp;

	k = ((((short)ft_atoi_base(pro->arg2, 16) ) % IDX_MOD)
		 * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	n = 0;
	tmp = ft_itoa_base(pro->reg[ft_atoi_base(pro->arg1, 16) - 1], 16);
	convert(&tmp);
	if (k < 0)
		k = (MEM_SIZE * 2 + k) % (MEM_SIZE * 2);
	while (n < 8)
	{
		k %= (MEM_SIZE * 2);
		vizData->mark_timeout[k] = 100;
		vizData->viz_data[k] = pro->pl_number;
		map[k++] = tmp[n++];
	}
}

void st(t_process *pro, unsigned char *map, t_viz_data *vizData)
{
	if (ft_strlen(pro->arg3) == 2)
		pro->iterator -= 2;
	if (ft_strlen(pro->arg3) == 4)
		pro->iterator -= 4;
	if (ft_strlen(pro->arg3) == 8)
		pro->iterator -= 8;
	if (ft_strlen(pro->arg1) != 2 || ft_strlen(pro->arg2) == 8
		|| ft_strlen(pro->arg2) == 0 || pro->iC == 1)
	{
		pro->cur_pos = (pro->iterator + pro->cur_pos) % (MEM_SIZE * 2);
		pro->iterator = 0;
		return ;
	}
	if (ft_strlen(pro->arg2) == 4)
		st_sup(pro, map, vizData);
	else if (ft_strlen(pro->arg2) == 2)
		pro->reg[ft_atoi_base(pro->arg2, 16) - 1] =
				pro->reg[ft_atoi_base(pro->arg1, 16) - 1];
	pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
	pro->iterator = 0;
}

void  add(t_process *pro)
{
	pro->cur_pos = (pro->iterator + pro->cur_pos) % (MEM_SIZE * 2);
	pro->iterator = 0;
	if (ft_strlen(pro->arg1) != 2 || ft_strlen(pro->arg2) != 2
		|| ft_strlen(pro->arg3) != 2 || pro->iC == 1)
		return ;
	pro->reg[ft_atoi_base(pro->arg3, 16) - 1] =
			pro->reg[ft_atoi_base(pro->arg1, 16) - 1] +
			pro->reg[ft_atoi_base(pro->arg2, 16) - 1];
	if (pro->reg[ft_atoi_base(pro->arg3, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
	pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
	pro->iterator = 0;
}

void  sub(t_process *pro)
{
	pro->cur_pos = (pro->iterator + pro->cur_pos)  % (MEM_SIZE * 2);
	pro->iterator = 0;
	if (ft_strlen(pro->arg1) != 2 || ft_strlen(pro->arg2) != 2
		|| ft_strlen(pro->arg3) != 2 || pro->iC == 1)
		return ;
	pro->reg[ft_atoi_base(pro->arg3, 16) - 1] =
			pro->reg[ft_atoi_base(pro->arg1, 16) - 1] -
			pro->reg[ft_atoi_base(pro->arg2, 16) - 1];
	if (pro->reg[ft_atoi_base(pro->arg3, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
	pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
	pro->iterator = 0;
}