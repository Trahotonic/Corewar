//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

void		sti(t_process *processor, unsigned char *map, int iz, t_player *pl)
{
	int		i;
	char	*arg2;
	int		n;
	char	*arg1;

	arg1 = ft_strdup(processor->arg1);
	convert(&arg1);
	n = 0;
	arg2 = ft_strnew(8);
	if (ft_strlen(processor->arg2) == 4)
	{
		i = ft_atoi_base(processor->arg2, 16) % IDX_MOD + processor->cur_pos;
		while (n < 8)
			arg2[n++] = map[i++];
		i = ft_atoi_base(arg2, 16) + ft_atoi_base(processor->arg3, 16)
			+ processor->cur_pos;
		n = 0;
	}
	else
		i = ft_atoi_base(processor->arg2, 16) + ft_atoi_base(processor->arg3, 16)
			+ processor->cur_pos;
	while (n < 8)
		map[i++] = arg1[n++];
	ft_strdel(&arg1);
	ft_strdel(&arg2);
}
