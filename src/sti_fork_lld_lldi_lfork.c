//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

int procN = 2;

int  sti_sup(t_process *pro, unsigned char *map)
{
	char *arg2;
	int i;
	int n;

	n = 0;
	arg2 = ft_strnew(8);
	i = ((((short)ft_atoi_base(pro->arg2, 16)) % IDX_MOD) * 2)
		+ pro->cur_pos % (MEM_SIZE * 2);
	if (i < 0)
		i = (MEM_SIZE * 2) + i;
	while (n < 8)
	{
		i %= (MEM_SIZE * 2);
		arg2[n++] = map[i++];
	}
	if (ft_strlen(pro->arg3) == 4)
		i = (((ft_atoi_base(arg2, 16) + (short)(ft_atoi_base(pro->arg3, 16)))
			  % IDX_MOD) * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	else
		i = (((ft_atoi_base(arg2, 16) + (short)pro->reg[ft_atoi_base(pro->arg3,
																	 16)- 1] ) % IDX_MOD) * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	ft_strdel(&arg2);
	if (i < 0)
		i = MEM_SIZE * 2 + i;
	return (i);
}

int  sti_sup2(t_process *processor)
{
	int i;

	if (ft_strlen(processor->arg3) == 4)
		i = (((((short)(ft_atoi_base(processor->arg2, 16) +
						(short)(ft_atoi_base(processor->arg3, 16)))))
			  % IDX_MOD) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
	else
	{
		i = (((short)(ft_atoi_base(processor->arg2, 16) +
					  (int)processor->reg[ft_atoi_base(processor->arg3, 16)- 1])
			  % IDX_MOD) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
	}
	if (i < 0)
		i = MEM_SIZE * 2 + i;
	return (i);
}

int  sti_sup3(t_process *processor)
{
	int i;

	if (ft_strlen(processor->arg3) == 2)
		i = (((int)(processor->reg[ft_atoi_base(processor->arg2, 16) - 1]
					+ (int)processor->reg[ft_atoi_base(processor->arg3, 16) - 1])
			  % IDX_MOD) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
	else
		i = (((short)(processor->reg[ft_atoi_base(processor->arg2, 16) - 1]
					  + (short)(ft_atoi_base(processor->arg3, 16)))
			  % IDX_MOD) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
	if (i < 0)
		i = MEM_SIZE * 2 + i;
	return (i);
}

void sti_print(unsigned char *map, int i, t_viz_data *vizData, char *arg1, t_process *pro)
{
	int n;

	n = 0;
	while (n < 8)
	{
		i %= MEM_SIZE * 2;
		vizData->mark_timeout[i] = 100;
		if (pro->pl_number != 1 && pro->pl_number != 2 && pro->pl_number != 3 && pro->pl_number != 4)
		{

		}
		vizData->viz_data[i] = pro->pl_number;
		map[i++] = arg1[n++];
	}
}

void  sti(t_process *pro, unsigned char *map, t_viz_data *viz_data)
{
	int  i;
	char *arg1;

	i = 0;
	if (ft_strlen(pro->arg1) != 2 || ft_strlen(pro->arg2) == 0
		|| ft_strlen(pro->arg3) == 0 || pro->iC)
	{
		pro->cur_pos = (pro->cur_pos + pro->iterator) % (MEM_SIZE * 2);
		pro->iterator = 0;
		return ;
	}
	arg1 = ft_itoa_base(pro->reg[ft_atoi_base(pro->arg1, 16) - 1], 16);
	convert(&arg1);
	if (ft_strlen(pro->arg2) == 2)
		i = sti_sup3(pro);
	else if (ft_strlen(pro->arg2) == 4 && (pro->t_dir != 2 && pro->t_dir != 5))
		i = sti_sup(pro, map);
	else if (ft_strlen(pro->arg2) == 4)
		i = sti_sup2(pro);
	sti_print(map, i, viz_data, arg1, pro);
	ft_strdel(&arg1);
	pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
	pro->iterator = 0;
}

void  lld_sup(t_process *pro, unsigned char *map)
{
	int k;
	int n;
	char *arg1;

	k = ((short)ft_atoi_base(pro->arg1, 16) * 2 + pro->cur_pos)
		% (MEM_SIZE * 2);
	if (k < 0)
		k = (MEM_SIZE * 2) + k;
	n = 0;
	arg1 = ft_strnew(4);
	while (n < 4)
	{
		k %= (MEM_SIZE * 2);
		arg1[n++] = map[k++];
	}
	pro->reg[ft_atoi_base(pro->arg2, 16) - 1] =
			(short)ft_atoi_base(arg1, 16);
}

void lld_compensator(t_process *pro)
{
	if (ft_strlen(pro->arg3) == 2)
		pro->iterator -= 2;
	if (ft_strlen(pro->arg3) == 4)
		pro->iterator -= 4;
	if (ft_strlen(pro->arg3) == 8)
		pro->iterator -= 8;
}
void lld(t_process *pro, unsigned char *map) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	char *arg1;

	lld_compensator(pro);
	if (ft_strlen(pro->arg1) == 2 || ft_strlen(pro->arg1) == 0
		|| ft_strlen(pro->arg2) != 2 || pro->iC)
	{
		pro->cur_pos = (pro->cur_pos + pro->iterator) % (MEM_SIZE * 2);
		pro->iterator = 0;
		return ;
	}
	if (ft_strlen(pro->arg1) == 8)
		pro->reg[ft_atoi_base(pro->arg2, 16) - 1] =
				(unsigned int)ft_atoi_base(pro->arg1, 16);
	else if (ft_strlen(pro->arg1) == 4)
		lld_sup(pro, map);
	ft_strdel(&arg1);
	if (pro->reg[ft_atoi_base(pro->arg2, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
	pro->cur_pos = (pro->iterator + pro->cur_pos) %
				   8192;
	pro->iterator = 0;
}


int  lldi_sup1(t_process *pro)
{
	int i;

	if (ft_strlen(pro->arg2) == 2)
		i = (((pro->reg[ft_atoi_base(pro->arg1, 16) - 1]
			   + pro->reg[ft_atoi_base(pro->arg2, 16) - 1]))
			 * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	else
		i = (((pro->reg[ft_atoi_base(pro->arg1, 16) - 1]
			   + (short)ft_atoi_base(pro->arg2, 16)))
			 * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	if (i < 0)
		i = (MEM_SIZE * 2) + i;
	return (i);
}

int  lldi_sup2(t_process *pro, unsigned char *map)
{
	int i;
	int n;
	char *a1;

	a1 = ft_strnew(8);
	n = 0;
	i = (((short)ft_atoi_base(pro->arg1, 16) % IDX_MOD)
		 * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	if (i < 0)
		i = (MEM_SIZE * 2) + i;
	while (n < 8)
	{
		i %= (MEM_SIZE * 2);
		a1[n++] = map[i++];
	}
	if (ft_strlen(pro->arg2) == 4)
		i = (((ft_atoi_base(a1, 16) + (short)ft_atoi_base(pro->arg2, 16)))
			 * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	else
		i = ((ft_atoi_base(a1, 16) + pro->reg[ft_atoi_base(pro->arg2, 16) - 1])
			 * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	if (i < 0)
		i = (MEM_SIZE * 2) + i;
	ft_strdel(&a1);
	return (i);
}

int  lldi_sup3(t_process *pro)
{
	int i;

	i = 0;
	if (ft_strlen(pro->arg2) == 4)
		i = ((((short)ft_atoi_base(pro->arg1, 16)
			   + (short)ft_atoi_base(pro->arg2, 16)))
			 * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	else
		i = ((short)((short)ft_atoi_base(pro->arg1, 16)
					 + pro->reg[ft_atoi_base(pro->arg2, 16) - 1])
			 * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	if (i < 0)
		i = (MEM_SIZE * 2) + i;
	return (i);
}

void lldi_print(t_process *pro, int i, unsigned char *map, char **arg1)
{
	int n;

	n = 0;
	(*arg1) = ft_strnew(8);
	while (n < 8)
	{
		i %= (MEM_SIZE * 2);
		(*arg1)[n++] = map[i++];
	}
}

void lldi(t_process *pro, unsigned char *map)
{
	int  i;
	char *arg1;
	int  n;

	n = 0;
	i = 0;
	if (ft_strlen(pro->arg3) != 2 || ft_strlen(pro->arg1) == 0 || ft_strlen(pro->arg2) == 0 || pro->iC)
	{
		pro->cur_pos = (pro->cur_pos +pro->iterator) % (MEM_SIZE * 2);
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
	pro->reg[ft_atoi_base(pro->arg3, 16) - 1] = (unsigned int)ft_atoi_base(arg1, 16);
	pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
	pro->iterator = 0;
	ft_strdel(&arg1);
}

t_process *node_create(t_process * pro)
{
	t_process *tmp;
	int   n;

	n = 0;
	tmp = (t_process*)malloc(sizeof(t_process));
	tmp->carry = pro->carry;
	tmp->pl_num = pro->pl_num;
	tmp->pl_number = pro->pl_number;
	if (tmp->pl_number != 1 && tmp->pl_number != 2 && tmp->pl_number != 3 && tmp->pl_number != 4)
	{

	}
	tmp->alive = pro->alive;
	tmp->com2 = 0;
	tmp->cycle_todo = 0;
	tmp->iterator = 0;
	tmp->codage = 1;
	tmp->iC = 0;
	tmp->invalidAgr = 0;
	tmp->t_dir = 0;
	tmp->proc_num = ++procN;
	while (n < 16)
	{
		tmp->reg[n] = pro->reg[n];
		n++;
	}
	return (tmp);
}

void fork_c(t_process **process, t_process *pro)
{
	t_process *tmp;

	if (ft_strlen(pro->arg1) != 4)
	{
		pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
		pro->iterator = 0;
		return ;
	}
	tmp = node_create(pro);
	tmp->cur_pos = (((short)(ft_atoi_base(pro->arg1, 16)) % IDX_MOD) * 2 +pro->cur_pos) % (MEM_SIZE * 2);
	if (tmp->cur_pos < 0)
		tmp->cur_pos = (MEM_SIZE * 2 + tmp->cur_pos) % 8192;
	do_null(tmp);
	tmp->next = *process;
	*process = tmp;
	(*process)->prev = NULL;
	(*process)->next->prev = *process;

	pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
	pro->iterator = 0;
}

void lfork(t_process **process, t_process *pro)
{
	t_process *tmp;

	if (ft_strlen(pro->arg1) != 4)
	{
		pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
		pro->iterator = 0;
		return ;
	}
	tmp = node_create(pro);
	do_null(tmp);
	tmp->cur_pos = ((short)ft_atoi_base(pro->arg1, 16) * 2 + pro->cur_pos) % 8192;
	if (tmp->cur_pos < 0)
		tmp->cur_pos = (MEM_SIZE * 2 + tmp->cur_pos) % 8192;
	tmp->next = *process;
	*process = tmp;
	(*process)->prev = NULL;
	(*process)->next->prev = *process;
	pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
	pro->iterator = 0;
}

void aff(t_process *processor, unsigned char *map)
{
	if (ft_strlen(processor->arg3) == 2)
		processor->iterator -= 2;
	if (ft_strlen(processor->arg3) == 4)
		processor->iterator -= 4;
	if (ft_strlen(processor->arg3) == 8)
		processor->iterator -= 8;
	if (ft_strlen(processor->arg2) == 2)
		processor->iterator -= 2;
	if (ft_strlen(processor->arg2) == 4)
		processor->iterator -= 4;
	if (ft_strlen(processor->arg2) == 8)
		processor->iterator -= 8;
	processor->cur_pos = (processor->iterator + processor->cur_pos) % (MEM_SIZE * 2);
	processor->iterator = 0;
}