/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:13:48 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 15:13:53 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		ldi_sup3(t_process *pro)
{
	int	i;
	int z;
	int q;

	if (ft_strlen(pro->arg2) == 4)
		i = ((((short)ab(pro->arg1, 16) + (short)ab(pro->arg2, 16)) % (IDX_MOD))
			* 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	else
	{
		z = ((short)ab(pro->arg1, 16));
		q = ((int)pro->reg[ab(pro->arg2, 16) - 1]);
		i = ((z + q) % (IDX_MOD) * 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	}
	return (i);
}

int		ldi_sup2(t_process *pro, unsigned char *map)
{
	int		i;
	int		n;
	char	*arg1;

	arg1 = ft_strnew(8);
	n = 0;
	i = (((short)ab(pro->arg1, 16) % (IDX_MOD))
		* 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	if (i < 0)
		i = ((MEM_SIZE) * 2) + i;
	while (n < 8)
	{
		i %= ((MEM_SIZE) * 2);
		arg1[n++] = map[i++];
	}
	if (ft_strlen(pro->arg2) == 4)
		i = (((ab(arg1, 16) + (short)ab(pro->arg2, 16))
			% (IDX_MOD)) * 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	else
		i = (((ab(arg1, 16) + pro->reg[ab(pro->arg2, 16) - 1])
			% (IDX_MOD)) * 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	ft_strdel(&arg1);
	return (i);
}

int		ldi_sup1(t_process *pro)
{
	int i;

	if (ft_strlen(pro->arg2) == 2)
		i = (((pro->reg[ab(pro->arg1, 16) - 1]
			+ pro->reg[ab(pro->arg2, 16) - 1]) % (IDX_MOD))
			* 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	else
		i = (((pro->reg[ab(pro->arg1, 16) - 1]
			+ (short)ab(pro->arg2, 16)) % (IDX_MOD))
			* 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	return (i);
}

void	ldi_print(t_process *pro, unsigned char *map, int i)
{
	char	*arg1;
	int		n;

	n = 0;
	arg1 = ft_strnew(8);
	while (n < 8)
	{
		i %= ((MEM_SIZE) * 2);
		arg1[n++] = map[i++];
	}
	pro->reg[ab(pro->arg3, 16) - 1] =
			(unsigned int)ab(arg1, 16);
	ft_strdel(&arg1);
}

void	ldi(t_process *pro, unsigned char *map)
{
	int	i;

	i = 0;
	if (ft_strlen(pro->arg3) != 2 || ft_strlen(pro->arg1) == 0
		|| ft_strlen(pro->arg2) == 0 || pro->i_c)
	{
		pro->cur_pos = (pro->cur_pos + pro->iterator) % ((MEM_SIZE) * 2);
		pro->iterator = 0;
		return ;
	}
	if (ft_strlen(pro->arg1) == 2)
		i = ldi_sup1(pro);
	else if (ft_strlen(pro->arg1) == 4 && (pro->t_dir != 1 && pro->t_dir != 3))
		i = ldi_sup2(pro, map);
	else if (ft_strlen(pro->arg1) == 4 && (pro->t_dir == 1 || pro->t_dir == 3))
		i = ldi_sup3(pro);
	if (i < 0)
		i = ((MEM_SIZE) * 2) + i;
	ldi_print(pro, map, i);
	pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
}
