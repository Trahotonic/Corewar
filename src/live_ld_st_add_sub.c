//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

void  live(t_process *processor, unsigned char *map, int i, t_player *pl)
{
	int n;
	int m;
	char name[9];

	m = processor->cur_pos + 2;
	name[8] = 0;
	n = 0;
	processor->alive = 1;
	while(n < 8)
		name[n++] = map[m++];
	pl->lastAlive = i;
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
}

void  ld(t_process *processor, unsigned char *map, int iz, t_player *pl)
{
	int  n;

	if (ft_strlen(processor->arg1) == 8)
	{
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] = ft_atoi_base(processor->arg1, 16);
	}
	else if (ft_strlen(processor->arg1) == 4)
	{
		n = ft_atoi_base(processor->arg1, 16);
		n %= IDX_MOD;
		int k;
		k = processor->cur_pos + n * 2;
		n = 0;
		while (n < 8)
			processor->arg1[n++] = map[k++];
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] = ft_atoi_base(processor->arg1, 16);
	}
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
}

void	st(t_process *processor, unsigned char *map, int iz, t_player *pl)
{
	int  n;
	char *tmp;

	if (ft_strlen(processor->arg2) == 4)
	{
		n = ft_atoi_base(processor->arg2, 16);
		n %= IDX_MOD;
		int k;
		k = processor->cur_pos + n * 2;
		n = 0;
		tmp = ft_itoa_base(processor->reg[ft_atoi_base(processor->arg1, 16) - 1], 16);
		convert(&tmp);
		while (n < 8)
			map[k++] = tmp[n++];
	}
	else if (ft_strlen(processor->arg2) == 2)
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] = processor->reg[ft_atoi_base(processor->arg1, 16) - 1];
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
}

void		add(t_process *processor, unsigned char *map, int iz, t_player *pl)
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

void		sub(t_process *processor, unsigned char *map, int iz, t_player *pl)
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
