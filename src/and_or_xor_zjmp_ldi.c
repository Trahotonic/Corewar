/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_xor_zjmp_ldi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:42:12 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 14:42:20 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	and(t_process *pro)
{
	pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
	if (ft_strlen(pro->arg3) != 2 || ft_strlen(pro->arg1) == 0
		|| ft_strlen(pro->arg2) == 0 || pro->i_c)
		return ;
	if (ft_strlen(pro->arg1) != 2 && ft_strlen(pro->arg2) == 2)
		pro->reg[ab(pro->arg3, 16) - 1] = ab(pro->arg1, 16)
		& pro->reg[ab(pro->arg2, 16) - 1];
	else if (ft_strlen(pro->arg1) == 2 && ft_strlen(pro->arg2) != 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				pro->reg[ab(pro->arg1, 16) - 1] & ab(pro->arg2, 16);
	else if (ft_strlen(pro->arg1) == 2 && ft_strlen(pro->arg2) == 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				pro->reg[ab(pro->arg1, 16) - 1]
				& pro->reg[ab(pro->arg2, 16) - 1];
	else
		pro->reg[ab(pro->arg3, 16) - 1] =
				ab(pro->arg1, 16) & ab(pro->arg2, 16);
	if (pro->reg[ab(pro->arg3, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
}

void	or(t_process *pro)
{
	pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
	if (ft_strlen(pro->arg3) != 2 || ft_strlen(pro->arg1) == 0
		|| ft_strlen(pro->arg2) == 0 || pro->i_c)
		return ;
	if (ft_strlen(pro->arg1) != 2 && ft_strlen(pro->arg2) == 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				ab(pro->arg1, 16) | pro->reg[ab(pro->arg2, 16) - 1];
	else if (ft_strlen(pro->arg1) == 2 && ft_strlen(pro->arg2) != 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				pro->reg[ab(pro->arg1, 16) - 1] | ab(pro->arg2, 16);
	else if (ft_strlen(pro->arg1) == 2 && ft_strlen(pro->arg2) == 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				pro->reg[ab(pro->arg1, 16) - 1]
				| pro->reg[ab(pro->arg2, 16) - 1];
	else
		pro->reg[ab(pro->arg3, 16) - 1] =
				ab(pro->arg1, 16) | ab(pro->arg2, 16);
	if (pro->reg[ab(pro->arg3, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
}

void	xor(t_process *pro)
{
	pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
	if (ft_strlen(pro->arg3) != 2 || ft_strlen(pro->arg1) == 0
		|| ft_strlen(pro->arg2) == 0 || pro->i_c)
		return ;
	if (ft_strlen(pro->arg1) != 2 && ft_strlen(pro->arg2) == 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				ab(pro->arg1, 16) ^ pro->reg[ab(pro->arg2, 16) - 1];
	else if (ft_strlen(pro->arg1) == 2 && ft_strlen(pro->arg2) != 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				pro->reg[ab(pro->arg1, 16) - 1] ^ ab(pro->arg2, 16);
	else if (ft_strlen(pro->arg1) == 2 && ft_strlen(pro->arg2) == 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				pro->reg[ab(pro->arg1, 16) - 1]
				^ pro->reg[ab(pro->arg2, 16) - 1];
	else
		pro->reg[ab(pro->arg3, 16) - 1] =
				ab(pro->arg1, 16) ^ ab(pro->arg2, 16);
	if (pro->reg[ab(pro->arg3, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
}

void	zjmp(t_process *processor)
{
	int	i;

	if (ft_strlen(processor->arg1) != 4 || processor->carry == 0)
	{
		processor->cur_pos = (processor->cur_pos + processor->iterator)
							% ((MEM_SIZE) * 2);
		processor->iterator = 0;
		return ;
	}
	i = ((((short)ab(processor->arg1, 16)) % (IDX_MOD))
		* 2 + processor->cur_pos) % ((MEM_SIZE) * 2);
	if (i < 0)
		i = (MEM_SIZE) * 2 + i;
	i %= ((MEM_SIZE) * 2);
	processor->cur_pos = i;
	processor->iterator = 0;
}
