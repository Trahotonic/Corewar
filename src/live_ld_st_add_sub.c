//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

void  live(t_process *processor,int i, t_player *pl)
{
	char *tmp;
	t_player *tmppl;

	tmppl = pl;
	while (tmppl)
	{
		if (tmppl->playerNumber == processor->pl_num)
			tmppl->liveCount++;
		tmppl = tmppl->next;
	}
	tmp = ft_uitoa_base2(pl->playerNumber, 16);
	while(pl && !ft_strequ(tmp, processor->arg1))
	{
		ft_strdel(&tmp);
		pl = pl->next;
		if (pl)
			tmp = ft_uitoa_base2(pl->playerNumber, 16);
	}
	ft_strdel(&tmp);
	processor->alive = 1;
	if (pl)
		pl->lastAlive = i;
	processor->cur_pos = (processor->iterator + processor->cur_pos) % 8192;
	processor->iterator = 0;
}

void		ld(t_process *processor, unsigned char *map)
{
	int		n;
	char	*arg1;
	int		k;

	if (ft_strlen(processor->arg3) == 2)
		processor->iterator -= 2;
	if (ft_strlen(processor->arg3) == 4)
		processor->iterator -= 4;
	if (ft_strlen(processor->arg3) == 8)
		processor->iterator -= 8;
	if (ft_strlen(processor->arg1) == 2 || ft_strlen(processor->arg1) == 0 || ft_strlen(processor->arg2) != 2 || processor->iC == 1)
	{
		processor->cur_pos = (processor->iterator + processor->cur_pos) % (MEM_SIZE * 2);
		processor->iterator = 0;
		return ;
	}
	if (ft_strlen(processor->arg1) == 8)
	{
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] =
				(unsigned int)ft_atoi_base(processor->arg1, 16);
	}
	else if (ft_strlen(processor->arg1) == 4)
	{
		k = ((((short)ft_atoi_base(processor->arg1, 16)) % IDX_MOD) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
		n = 0;
		arg1 = ft_strnew(8);
		while (n < 8)
		{
			k %= (MEM_SIZE * 2);
			arg1[n++] = map[k++];
		}
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] = ft_atoi_base(arg1, 16);
	}
	if (processor->reg[ft_atoi_base(processor->arg2, 16) - 1] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
	processor->cur_pos = (processor->iterator + processor->cur_pos) % 8192;
	processor->iterator = 0;
}

void	st(t_process *processor, unsigned char *map, t_vizData *vizData)
{
	int		n;
	char	*tmp;
	int		k;

	if (ft_strlen(processor->arg3) == 2)
		processor->iterator -= 2;
	if (ft_strlen(processor->arg3) == 4)
		processor->iterator -= 4;
	if (ft_strlen(processor->arg3) == 8)
		processor->iterator -= 8;
	if (ft_strlen(processor->arg1) != 2 || ft_strlen(processor->arg2) == 8 || ft_strlen(processor->arg2) == 0 || processor->iC == 1)
	{
		processor->cur_pos = (processor->iterator + processor->cur_pos) % (MEM_SIZE * 2);
		processor->iterator = 0;
		return ;
	}
	if (ft_strlen(processor->arg2) == 4)
	{
		k = ((((short)ft_atoi_base(processor->arg2, 16) ) % IDX_MOD) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
		n = 0;
		tmp = ft_itoa_base(processor->reg[ft_atoi_base(processor->arg1, 16) - 1], 16);
		convert(&tmp);
		if (k < 0)
		{
			k = (MEM_SIZE * 2 + k) % (MEM_SIZE * 2);
		}
		while (n < 8)
		{
			k %= (MEM_SIZE * 2);
			vizData->markTimeout[k] = 100;
			vizData->vizData[k] = processor->pl_number;
			map[k++] = tmp[n++];
		}
	}
	else if (ft_strlen(processor->arg2) == 2)
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] =
				processor->reg[ft_atoi_base(processor->arg1, 16) - 1];
	processor->cur_pos = (processor->iterator + processor->cur_pos) % 8192;
	processor->iterator = 0;
}

void		add(t_process *processor)
{
	if (ft_strlen(processor->arg1) != 2 || ft_strlen(processor->arg2) != 2 || ft_strlen(processor->arg3) != 2 || processor->iC == 1)
	{
		processor->cur_pos = (processor->iterator + processor->cur_pos) % (MEM_SIZE * 2);
		processor->iterator = 0;
		return ;
	}
	processor->reg[ft_atoi_base(processor->arg3, 16) - 1] =
			processor->reg[ft_atoi_base(processor->arg1, 16) - 1] +
			processor->reg[ft_atoi_base(processor->arg2, 16) - 1];
	if (processor->reg[ft_atoi_base(processor->arg3, 16) - 1] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
	processor->cur_pos = (processor->iterator + processor->cur_pos) % 8192;
	processor->iterator = 0;
}

void		sub(t_process *processor)
{
	if (ft_strlen(processor->arg1) != 2 || ft_strlen(processor->arg2) != 2 || ft_strlen(processor->arg3) != 2 || processor->iC == 1)
	{
		processor->cur_pos = (processor->iterator + processor->cur_pos)  % (MEM_SIZE * 2);
		processor->iterator = 0;
		return ;
	}
	processor->reg[ft_atoi_base(processor->arg3, 16) - 1] =
			processor->reg[ft_atoi_base(processor->arg1, 16) - 1] -
			processor->reg[ft_atoi_base(processor->arg2, 16) - 1];
	if (processor->reg[ft_atoi_base(processor->arg3, 16) - 1] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
	processor->cur_pos = (processor->iterator + processor->cur_pos) % 8192;
	processor->iterator = 0;
}
