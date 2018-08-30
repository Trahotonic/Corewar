/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_fork_lld_lldi_lfork.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:31:34 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 16:31:41 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

t_process	*node_create(t_process *pro)
{
	t_process	*tmp;
	int			n;

	n = 0;
	tmp = (t_process*)malloc(sizeof(t_process));
	tmp->carry = pro->carry;
	tmp->pl_num = pro->pl_num;
	tmp->pl_number = pro->pl_number;
	tmp->alive = pro->alive;
	tmp->com2 = 0;
	tmp->cycle_todo = 0;
	tmp->iterator = 0;
	tmp->codage = 1;
	tmp->iC = 0;
	tmp->invalidAgr = 0;
	tmp->t_dir = 0;
	while (n < 16)
	{
		tmp->reg[n] = pro->reg[n];
		n++;
	}
	return (tmp);
}

void		fork_c(t_process **process, t_process *pro)
{
	t_process *tmp;

	if (ft_strlen(pro->arg1) != 4)
	{
		pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
		pro->iterator = 0;
		return ;
	}
	tmp = node_create(pro);
	tmp->cur_pos = (((short)(ab(pro->arg1, 16)) % (IDX_MOD))
					* 2 + pro->cur_pos) % (MEM_SIZE * 2);
	if (tmp->cur_pos < 0)
		tmp->cur_pos = (MEM_SIZE * 2 + tmp->cur_pos) % ((MEM_SIZE) * 2);
	do_null(tmp);
	tmp->next = *process;
	*process = tmp;
	(*process)->prev = NULL;
	(*process)->next->prev = *process;
	pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
}

void		lfork(t_process **process, t_process *pro)
{
	t_process *tmp;

	if (ft_strlen(pro->arg1) != 4)
	{
		pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
		pro->iterator = 0;
		return ;
	}
	tmp = node_create(pro);
	do_null(tmp);
	tmp->cur_pos = ((short)ab(pro->arg1, 16) * 2 + pro->cur_pos)
				% ((MEM_SIZE) * 2);
	if (tmp->cur_pos < 0)
		tmp->cur_pos = (MEM_SIZE * 2 + tmp->cur_pos) % ((MEM_SIZE) * 2);
	tmp->next = *process;
	*process = tmp;
	(*process)->prev = NULL;
	(*process)->next->prev = *process;
	pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
}

void		aff_compensator(t_process *pro)
{
	if (ft_strlen(pro->arg3) == 2)
		pro->iterator -= 2;
	if (ft_strlen(pro->arg3) == 4)
		pro->iterator -= 4;
	if (ft_strlen(pro->arg3) == 8)
		pro->iterator -= 8;
	if (ft_strlen(pro->arg2) == 2)
		pro->iterator -= 2;
	if (ft_strlen(pro->arg2) == 4)
		pro->iterator -= 4;
	if (ft_strlen(pro->arg2) == 8)
		pro->iterator -= 8;
}

void		aff(t_process *pro, t_viz_data *viz_data)
{
	t_char	*ptr;

	aff_compensator(pro);
	pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
	if (pro->iC)
		return ;
	if (!viz_data->print)
	{
		viz_data->print = (t_char*)malloc(sizeof(t_char));
		viz_data->print->c = pro->reg[ab(pro->arg1, 16) - 1] % 256;
		viz_data->print->next = NULL;
	}
	else
	{
		ptr = viz_data->print;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = (t_char*)malloc(sizeof(t_char));
		viz_data->print->c = pro->reg[ab(pro->arg1, 16) - 1] % 256;
		viz_data->print->next = NULL;
	}
	pro->cur_pos = (pro->iterator + pro->cur_pos) % ((MEM_SIZE) * 2);
	pro->iterator = 0;
}
