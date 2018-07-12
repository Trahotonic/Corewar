//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

void		and(t_process *processor, unsigned char *map, int iz, t_player *pl)
{
	processor->reg[ft_atoi_base(processor->arg3, 16) - 1] =
			processor->reg[ft_atoi_base(processor->arg1, 16) - 1] &
			processor->reg[ft_atoi_base(processor->arg2, 16) - 1];
	if (processor->reg[ft_atoi_base(processor->arg1, 16)] -
		processor->reg[ft_atoi_base(processor->arg2, 16)] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
}

void		or(t_process *processor, unsigned char *map, int iz, t_player *pl)
{
	processor->reg[ft_atoi_base(processor->arg3, 16) - 1] =
			processor->reg[ft_atoi_base(processor->arg1, 16) - 1] |
			processor->reg[ft_atoi_base(processor->arg2, 16) - 1];
	if (processor->reg[ft_atoi_base(processor->arg1, 16)] -
		processor->reg[ft_atoi_base(processor->arg2, 16)] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
}

void		xor(t_process *processor, unsigned char *map, int iz, t_player *pl)
{
	processor->reg[ft_atoi_base(processor->arg3, 16) - 1] =
			processor->reg[ft_atoi_base(processor->arg1, 16) - 1] ^
			processor->reg[ft_atoi_base(processor->arg2, 16) - 1];
	if (processor->reg[ft_atoi_base(processor->arg1, 16)] -
		processor->reg[ft_atoi_base(processor->arg2, 16)] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
}


void	zjmp(t_process *processor, unsigned char *map, int iz, t_player *pl)
{
	if (processor->carry == 0)
		return;
	processor->cur_pos = ft_atoi_base(processor->arg1, 16) % IDX_MOD;
}

void	ldi(t_process *processor, unsigned char *map, int iz, t_player *pl)
{
	int		i;
	char	*arg1;
	int		n;

	n = 0;
	arg1 = ft_strnew(8);
	if (ft_strlen(processor->arg1) == 4)
	{
		i = ft_atoi_base(processor->arg1, 16) % IDX_MOD + processor->cur_pos;
		while (n < 8)
			arg1[n++] = map[i++];
		i = ft_atoi_base(arg1, 16) + ft_atoi_base(processor->arg2, 16) + processor->cur_pos;
		n = 0;
		while (n < 8)
			arg1[n++] = map[i++];
		processor->reg[ft_atoi_base(processor->arg3, 16)] = ft_atoi_base(arg1, 16);
	}
	i = ft_atoi_base(processor->arg1, 16) + ft_atoi_base(processor->arg2, 16) + processor->cur_pos;
	while (n < 8)
		arg1[n++] = map[i++];
	processor->reg[ft_atoi_base(processor->arg3, 16)] = ft_atoi_base(arg1, 16);
}

