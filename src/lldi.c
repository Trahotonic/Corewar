/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:29:48 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 15:29:54 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		lldi_sup1(t_process *pro)
{
	int	i;

	if (ft_strlen(pro->arg2) == 2)
		i = (((pro->reg[ab(pro->arg1, 16) - 1]
			+ pro->reg[ab(pro->arg2, 16) - 1]))
			* 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	else
		i = (((pro->reg[ab(pro->arg1, 16) - 1] + (short)ab(pro->arg2, 16)))
			* 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	if (i < 0)
		i = ((MEM_SIZE) * 2) + i;
	return (i);
}

int		lldi_sup2(t_process *pro, unsigned char *map)
{
	int		i;
	int		n;
	char	*a1;

	a1 = ft_strnew(8);
	n = 0;
	i = (((short)ab(pro->arg1, 16) % (IDX_MOD))
		* 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	if (i < 0)
		i = ((MEM_SIZE) * 2) + i;
	while (n < 8)
	{
		i %= ((MEM_SIZE) * 2);
		a1[n++] = map[i++];
	}
	if (ft_strlen(pro->arg2) == 4)
		i = (((ab(a1, 16) + (short)ab(pro->arg2, 16)))
			* 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	else
		i = ((ab(a1, 16) + pro->reg[ab(pro->arg2, 16) - 1])
			* 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	if (i < 0)
		i = ((MEM_SIZE) * 2) + i;
	ft_strdel(&a1);
	return (i);
}

int		lldi_sup3(t_process *pro)
{
	int i;

	if (ft_strlen(pro->arg2) == 4)
		i = ((((short)ab(pro->arg1, 16) + (short)ab(pro->arg2, 16)))
			* 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	else
		i = ((short)((short)ab(pro->arg1, 16) + pro->reg[ab(pro->arg2, 16) - 1])
			* 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	if (i < 0)
		i = ((MEM_SIZE) * 2) + i;
	return (i);
}

void	lldi_print(t_process *pro, int i, unsigned char *map, char **arg1)
{
	int	n;

	n = 0;
	(*arg1) = ft_strnew(8);
	while (n < 8)
	{
		i %= ((MEM_SIZE) * 2);
		(*arg1)[n++] = map[i++];
	}
}

void	lldi(t_process *pro, unsigned char *map)
{
	int		i;
	char	*arg1;

	i = 0;
	if (ft_strlen(pro->arg3) != 2 || ft_strlen(pro->arg1) == 0
		|| ft_strlen(pro->arg2) == 0 || pro->iC)
	{
		pro->cur_pos = (pro->cur_pos + pro->iterator) % ((MEM_SIZE) * 2);
		pro->iterator = 0;
		return ;
	}
	if (ft_strlen(pro->arg1) == 2)
		i = lldi_sup1(pro);
	else if (ft_strlen(pro->arg1) == 4 && pro->t_dir != 1)
		i = lldi_sup2(pro, map);
	else if (ft_strlen(pro->arg1) == 4 && (pro->t_dir == 1 || pro->t_dir == 3))
		i = lldi_sup3(pro);
	lldi_print(pro, i, map, &arg1);
	pro->reg[ab(pro->arg3, 16) - 1] = (unsigned int)ab(arg1, 16);
	pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
	pro->iterator = 0;
	ft_strdel(&arg1);
}
