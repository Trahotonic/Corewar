/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:25:21 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 15:25:29 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	lld_sup(t_process *pro, unsigned char *map)
{
	int		k;
	int		n;
	char	*arg1;

	k = ((short)ab(pro->arg1, 16) * 2 + pro->cur_pos)
		% ((MEM_SIZE) * 2);
	if (k < 0)
		k = ((MEM_SIZE) * 2) + k;
	n = 0;
	arg1 = ft_strnew(4);
	while (n < 4)
	{
		k %= ((MEM_SIZE) * 2);
		arg1[n++] = map[k++];
	}
	pro->reg[ab(pro->arg2, 16) - 1] = ab(arg1, 16);
	ft_strdel(&arg1);
}

void	lld_compensator(t_process *pro)
{
	if (ft_strlen(pro->arg3) == 2)
		pro->iterator -= 2;
	if (ft_strlen(pro->arg3) == 4)
		pro->iterator -= 4;
	if (ft_strlen(pro->arg3) == 8)
		pro->iterator -= 8;
}

void	lld(t_process *pro, unsigned char *map)
{
	char	*arg1;

	lld_compensator(pro);
	if (ft_strlen(pro->arg1) == 2 || ft_strlen(pro->arg1) == 0
		|| ft_strlen(pro->arg2) != 2 || pro->i_c)
	{
		pro->cur_pos = (pro->cur_pos + pro->iterator) % ((MEM_SIZE) * 2);
		pro->iterator = 0;
		return ;
	}
	if (ft_strlen(pro->arg1) == 8)
		pro->reg[ab(pro->arg2, 16) - 1] = (unsigned int)ab(pro->arg1, 16);
	else if (ft_strlen(pro->arg1) == 4)
		lld_sup(pro, map);
	ft_strdel(&arg1);
	if (pro->reg[ab(pro->arg2, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
	pro->cur_pos = (pro->iterator + pro->cur_pos) % (MEM_SIZE);
	pro->iterator = 0;
}
