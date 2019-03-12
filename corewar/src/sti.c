/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:40:49 by msemenov          #+#    #+#             */
/*   Updated: 2018/09/12 14:42:12 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		sti_sup(t_process *pro, unsigned char *map)
{
	char	*arg2;
	int		i;
	int		n;

	n = 0;
	arg2 = ft_strnew(8);
	i = ((((short)ab(pro->arg2, 16)) % ((IDX_MOD))) * 2)
		+ pro->cur_pos % (((MEM_SIZE)) * 2);
	if (i < 0)
		i = ((MEM_SIZE) * 2) + i;
	while (n < 8)
	{
		i %= ((MEM_SIZE) * 2);
		arg2[n++] = map[i++];
	}
	if (ft_strlen(pro->arg3) == 4)
		i = (((ab(arg2, 16) + (short)(ab(pro->arg3, 16)))
			% (IDX_MOD)) * 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	else
		i = (((ab(arg2, 16) + (short)pro->reg[ab(pro->arg3,
				16) - 1]) % (IDX_MOD)) * 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	ft_strdel(&arg2);
	if (i < 0)
		i = (MEM_SIZE) * 2 + i;
	return (i);
}

int		sti_sup2(t_process *processor)
{
	int	i;
	int k;
	int j;

	if (ft_strlen(processor->arg3) == 4)
		i = (((((short)(ab(processor->arg2, 16) +
						(short)(ab(processor->arg3, 16)))))
			% (IDX_MOD)) * 2 + processor->cur_pos) % ((MEM_SIZE) * 2);
	else
	{
		k = (short)(ab(processor->arg2, 16));
		j = (int)processor->reg[ab(processor->arg3, 16) - 1];
		i = (((k + j)
			% (IDX_MOD)) * 2 + processor->cur_pos) % ((MEM_SIZE) * 2);
	}
	if (i < 0)
		i = (MEM_SIZE) * 2 + i;
	return (i);
}

int		sti_sup3(t_process *processor)
{
	int	i;

	if (ft_strlen(processor->arg3) == 2)
		i = (((int)(processor->reg[ab(processor->arg2, 16) - 1]
					+ (int)processor->reg[ab(processor->arg3, 16) - 1])
			% (IDX_MOD)) * 2 + processor->cur_pos) % ((MEM_SIZE) * 2);
	else
		i = (((short)(processor->reg[ab(processor->arg2, 16) - 1]
					+ (short)(ab(processor->arg3, 16)))
			% (IDX_MOD)) * 2 + processor->cur_pos) % ((MEM_SIZE) * 2);
	if (i < 0)
		i = (MEM_SIZE) * 2 + i;
	return (i);
}

int		sti_kostil(t_process *pro, char **arg1, bool check)
{
	pro->cur_pos = (pro->cur_pos + pro->iterator) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
	if (check)
		ft_strdel(arg1);
	return (1);
}

void	sti(t_process *pro, unsigned char *map, t_viz_data *viz_data)
{
	int		i;
	char	*arg1;
	int		n;

	n = 0;
	if (ft_strlen(pro->arg1) != 2 || ft_strlen(pro->arg2) == 0
		|| ft_strlen(pro->arg3) == 0 || pro->i_c)
		if (sti_kostil(pro, &arg1, false))
			return ;
	arg1 = ft_itoa_base(pro->reg[ab(pro->arg1, 16) - 1], 16);
	convert(&arg1);
	if (ft_strlen(pro->arg2) == 2)
		i = sti_sup3(pro);
	else if (ft_strlen(pro->arg2) == 4 && (pro->t_dir != 2 && pro->t_dir != 5))
		i = sti_sup(pro, map);
	else if (ft_strlen(pro->arg2) == 4)
		i = sti_sup2(pro);
	while (n < 8)
	{
		i %= (MEM_SIZE) * 2;
		viz_data->mark_timeout[i] = 100;
		viz_data->viz_data[i] = pro->pl_number;
		map[i++] = arg1[n++];
	}
	sti_kostil(pro, &arg1, true);
}
