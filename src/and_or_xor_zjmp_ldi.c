//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

void		and(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData)
{
	processor->reg[ft_atoi_base(processor->arg3, 16) - 1] =
			processor->reg[ft_atoi_base(processor->arg1, 16) - 1] &
			processor->reg[ft_atoi_base(processor->arg2, 16) - 1];
	if (processor->reg[ft_atoi_base(processor->arg3, 16) - 1] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
}

void		or(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData)
{
	processor->reg[ft_atoi_base(processor->arg3, 16) - 1] =
			processor->reg[ft_atoi_base(processor->arg1, 16) - 1] |
			processor->reg[ft_atoi_base(processor->arg2, 16) - 1];
	if (processor->reg[ft_atoi_base(processor->arg3, 16) - 1] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
}

void		xor(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData)
{
	processor->reg[ft_atoi_base(processor->arg3, 16) - 1] =
			processor->reg[ft_atoi_base(processor->arg1, 16) - 1] ^
			processor->reg[ft_atoi_base(processor->arg2, 16) - 1];
	if (processor->reg[ft_atoi_base(processor->arg3, 16) - 1] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
}


void	zjmp(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData)
{
	int i;

	if (processor->carry == 0)
	{
		processor->cur_pos += processor->iterator;
		processor->iterator = 0;
		return;
	}

	i = (((short)ft_atoi_base(processor->arg1, 16)) % IDX_MOD) * 2 + processor->cur_pos;
	if (i < 0)
		i = MEM_SIZE * 2 + i;
	processor->cur_pos = i;
	processor->iterator = 0;
}

void	ldi(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	int		i;
	char	*arg1;
	int		n;

	n = 0;
	arg1 = ft_strnew(8);
	if (ft_strlen(processor->arg1) == 2)
	{
		if (ft_strlen(processor->arg2) == 2)
		{
			i = ((processor->reg[ft_atoi_base(processor->arg1, 16) - 1] + processor->reg[ft_atoi_base(processor->arg2, 16) - 1])% IDX_MOD) * 2 + processor->cur_pos;
		}
		else
		{
			i = ((processor->reg[ft_atoi_base(processor->arg1, 16) - 1] + (short)ft_atoi_base(processor->arg2, 16))% IDX_MOD) * 2 + processor->cur_pos;
		}
	}
	else if (ft_strlen(processor->arg1) == 4 && processor->t_dir != 1)
	{
		i = ((short)ft_atoi_base(processor->arg1, 16) % IDX_MOD)
			* 2 + processor->cur_pos;
		while (n < 8)
			arg1[n++] = map[i++];
		if (ft_strlen(processor->arg2 ) == 4)
		{
			i = ((ft_atoi_base(arg1, 16) + (short)ft_atoi_base(processor->arg2, 16)) % IDX_MOD) * 2
				+ processor->cur_pos;
		}
		else
		{
			i = ((ft_atoi_base(arg1, 16) + processor->reg[ft_atoi_base(processor->arg2, 16) - 1]) % IDX_MOD) * 2
				+ processor->cur_pos;
		}
		i = ft_atoi_base(arg1, 16) + ft_atoi_base(processor->arg2, 16) * 2
			+ processor->cur_pos;
		n = 0;
	}
	else if (ft_strlen(processor->arg1) == 4 && processor->t_dir == 1) /* исправить добавить t_ind */
	{
		if (ft_strlen(processor->arg2) == 4)
		{
			i = (((short)ft_atoi_base(processor->arg1, 16) + (short)ft_atoi_base(processor->arg2, 16))% IDX_MOD) * 2 + processor->cur_pos;
		}
		else
		{
			i = (short)((short)ft_atoi_base(processor->arg1, 16) + processor->reg[ft_atoi_base(processor->arg2, 16) - 1]) % IDX_MOD * 2 + processor->cur_pos;
		}
	}
//	if (ft_strlen(processor->arg1) == 4 && !processor->t_dir)
//	{
//		i = (ft_atoi_base(processor->arg1, 16) % IDX_MOD)
//			* 2 + processor->cur_pos;
//		while (n < 8)
//			arg1[n++] = map[i++];
//		i = ft_atoi_base(arg1, 16) + ft_atoi_base(processor->arg2, 16) * 2
//			+ processor->cur_pos;
//		n = 0;
//	}
//	i = (ft_atoi_base(processor->arg1, 16) + processor->reg[ft_atoi_base(processor->arg2, 16) - 1] + processor->cur_pos / 2)
//		% IDX_MOD * 2;
	while (n < 8)
		arg1[n++] = map[i++];
	processor->reg[ft_atoi_base(processor->arg3, 16) - 1] =
			(unsigned int)ft_atoi_base(arg1, 16);
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
	ft_strdel(&arg1);
}


