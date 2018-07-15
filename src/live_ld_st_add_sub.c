//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

void  live(t_process *processor, unsigned char *map, int i, t_player *pl, t_vizData *vizData)// Обновленно (но надо менять ) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{

	processor->alive = 1;
	pl->lastAlive = i;
	processor->cur_pos = (processor->iterator + processor->cur_pos) % 8192;
	processor->iterator = 0;
}

void		ld(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	int		n;
	char	*arg1;
	int		k;

	if (ft_strlen(processor->arg1) == 8)
	{
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] =
				(unsigned int)ft_atoi_base(processor->arg1, 16);
	}
	else if (ft_strlen(processor->arg1) == 4)
	{
		k = (ft_atoi_base(processor->arg1, 16) % IDX_MOD) * 2 + processor->cur_pos;
		n = 0;
		arg1 = ft_strnew(8);
		while (n < 8)
			arg1[n++] = map[k++];
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] =
				(unsigned int)ft_atoi_base(arg1, 16);
	}
	if (processor->reg[ft_atoi_base(processor->arg2, 16) - 1] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
}

void	st(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	int		n;
	char	*tmp;
	int		k;

	if (ft_strlen(processor->arg2) == 4)
	{
		k = ft_atoi_base(processor->arg2, 16) % IDX_MOD * 2 + processor->cur_pos;
		n = 0;
		tmp = ft_itoa_base(processor->reg[ft_atoi_base(processor->arg1, 16) - 1], 16);
		convert(&tmp);
		while (n < 8)
		{
			vizData->markTimeout[k] = 100;
			map[k++] = tmp[n++];
		}
	}
	else if (ft_strlen(processor->arg2) == 2)
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] =
				processor->reg[ft_atoi_base(processor->arg1, 16) - 1];
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
}

void		add(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData)
{
	processor->reg[ft_atoi_base(processor->arg3, 16) - 1] =
			processor->reg[ft_atoi_base(processor->arg1, 16) - 1] +
			processor->reg[ft_atoi_base(processor->arg2, 16) - 1];
	if (processor->reg[ft_atoi_base(processor->arg1, 16) - 1] +
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
}

void		sub(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData)
{
	processor->reg[ft_atoi_base(processor->arg3, 16) - 1] =
			processor->reg[ft_atoi_base(processor->arg1, 16) - 1] -
			processor->reg[ft_atoi_base(processor->arg2, 16) - 1];
	if (processor->reg[ft_atoi_base(processor->arg1, 16) - 1] -
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
}
