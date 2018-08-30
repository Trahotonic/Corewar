/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:37:41 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 15:37:49 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	st_sup(t_process *pro, unsigned char *map, t_viz_data *viz_data)
{
	int		n;
	int		k;
	char	*tmp;

	k = ((((short)ab(pro->arg2, 16)) % (IDX_MOD))
		* 2 + pro->cur_pos) % ((MEM_SIZE) * 2);
	n = 0;
	tmp = ft_itoa_base(pro->reg[ab(pro->arg1, 16) - 1], 16);
	convert(&tmp);
	if (k < 0)
		k = ((MEM_SIZE) * 2 + k) % ((MEM_SIZE) * 2);
	while (n < 8)
	{
		k %= ((MEM_SIZE) * 2);
		viz_data->mark_timeout[k] = 100;
		viz_data->viz_data[k] = pro->pl_number;
		map[k++] = tmp[n++];
	}
}

void	st(t_process *pro, unsigned char *map, t_viz_data *viz_data)
{
	if (ft_strlen(pro->arg3) == 2)
		pro->iterator -= 2;
	if (ft_strlen(pro->arg3) == 4)
		pro->iterator -= 4;
	if (ft_strlen(pro->arg3) == 8)
		pro->iterator -= 8;
	if (ft_strlen(pro->arg1) != 2 || ft_strlen(pro->arg2) == 8
		|| ft_strlen(pro->arg2) == 0 || pro->iC == 1)
	{
		pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
		pro->iterator = 0;
		return ;
	}
	if (ft_strlen(pro->arg2) == 4)
		st_sup(pro, map, viz_data);
	else if (ft_strlen(pro->arg2) == 2)
		pro->reg[ab(pro->arg2, 16) - 1] = pro->reg[ab(pro->arg1, 16) - 1];
	pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
	pro->iterator = 0;
}
