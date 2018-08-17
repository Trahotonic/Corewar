//
// Created by Roman KYSLYY on 7/12/18.
//

int g_global = 1;

#include "../inc/corewar.h"

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

void sti_print(unsigned char *map, int i, t_vizData *vizData, char *arg1, t_process *pro)
{
	int n;

	n = 0;
	while (n < 8)
	{
		i %= MEM_SIZE * 2;
		vizData->markTimeout[i] = 100;
		vizData->vizData[i] = pro->pl_number;
		map[i++] = arg1[n++];
	}
}

void  sti(t_process *pro, unsigned char *map, int iz, t_player *pl, t_vizData *vizData) /* FIXED !!!!!!!!!!! */
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
	sti_print(map, i, vizData, arg1, pro);
	ft_strdel(&arg1);
	pro->cur_pos = (pro->iterator + pro->cur_pos) % 8192;
	pro->iterator = 0;
}

void	lld(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	int	n;
	int k;
	char *arg1;

	if (ft_strlen(processor->arg3) == 2)
		processor->iterator -= 2;
	if (ft_strlen(processor->arg3) == 4)
		processor->iterator -= 4;
	if (ft_strlen(processor->arg3) == 8)
		processor->iterator -= 8;
	if (ft_strlen(processor->arg1) == 2 || ft_strlen(processor->arg1) == 0 || ft_strlen(processor->arg2) != 2)
	{
		processor->cur_pos = (processor->cur_pos + processor->iterator) % (MEM_SIZE * 2);
		processor->iterator = 0;
		return ;
	}
	if (ft_strlen(processor->arg1) == 8)
	{
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] =
				(unsigned int)ft_atoi_base(processor->arg1, 16);
	}
	else if (ft_strlen(processor->arg1) == 4)
	{
		k = ((short)ft_atoi_base(processor->arg1, 16) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
		if (k < 0)
			k = (MEM_SIZE * 2) + k;
		n = 0;
		arg1 = ft_strnew(4);
		while (n < 4)
		{
			k %= (MEM_SIZE * 2);
			arg1[n++] = map[k++];
		}
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] =
				(short)ft_atoi_base(arg1, 16);
	}
	ft_strdel(&arg1);
	if (processor->reg[ft_atoi_base(processor->arg2, 16) - 1] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
	processor->cur_pos = (processor->iterator + processor->cur_pos) % 8192;
	processor->iterator = 0;
}

void	lldi(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	int		i;
	char	*arg1;
	int		n;

	n = 0;
	if (ft_strlen(processor->arg3) != 2 || ft_strlen(processor->arg1) == 0 || ft_strlen(processor->arg2) == 0)
	{
		processor->cur_pos = (processor->cur_pos +processor->iterator) % (MEM_SIZE * 2);
		processor->iterator = 0;
		return ;
	}
	arg1 = ft_strnew(8);
	if (ft_strlen(processor->arg1) == 2)
	{
		if (ft_strlen(processor->arg2) == 2)
		{
			i = (((processor->reg[ft_atoi_base(processor->arg1, 16) - 1] + processor->reg[ft_atoi_base(processor->arg2, 16) - 1])) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
		}
		else
		{
			i = (((processor->reg[ft_atoi_base(processor->arg1, 16) - 1] + (short)ft_atoi_base(processor->arg2, 16))) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
		}
	}
	else if (ft_strlen(processor->arg1) == 4 && processor->t_dir != 1)
	{
		i = (((short)ft_atoi_base(processor->arg1, 16) % IDX_MOD) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
		if (i < 0)
			i = (MEM_SIZE * 2) + i;
		while (n < 8)
		{
			i %= (MEM_SIZE * 2);
			arg1[n++] = map[i++];
		}
		if (ft_strlen(processor->arg2) == 4)
		{
			i = (((ft_atoi_base(arg1, 16) + (short)ft_atoi_base(processor->arg2, 16))) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
		}
		else
		{
			i = (((ft_atoi_base(arg1, 16) + processor->reg[ft_atoi_base(processor->arg2, 16) - 1])) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
		}
		n = 0;
	}
	else if (ft_strlen(processor->arg1) == 4 && (processor->t_dir == 1 || processor->t_dir == 3)) /* исправить добавить t_ind */
	{
		if (ft_strlen(processor->arg2) == 4)
		{
			i = ((((short)ft_atoi_base(processor->arg1, 16) + (short)ft_atoi_base(processor->arg2, 16))) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
		}
		else
		{
			i = ((short)((short)ft_atoi_base(processor->arg1, 16) + processor->reg[ft_atoi_base(processor->arg2, 16) - 1]) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
		}
	}
	if (i < 0)
		i = (MEM_SIZE * 2) + i;
	while (n < 8)
	{
		i %= (MEM_SIZE * 2);
		arg1[n++] = map[i++];
	}
	processor->reg[ft_atoi_base(processor->arg3, 16) - 1] =
			(unsigned int)ft_atoi_base(arg1, 16);
	processor->cur_pos = (processor->iterator + processor->cur_pos) % 8192;
	processor->iterator = 0;
	ft_strdel(&arg1);
}

void	fork_c(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! (но это не точно =))))))))))))
{
	t_process	*tmp;
	t_process	*ptr;
	int 		n;

	if (ft_strlen(processor->arg1) != 4)
	{
		processor->cur_pos = (processor->iterator + processor->cur_pos) % 8192;
		processor->iterator = 0;
		return ;
	}
	tmp = (t_process*)malloc(sizeof(t_process));
	tmp->cur_pos = (((short)(ft_atoi_base(processor->arg1, 16)) % IDX_MOD) * 2 + processor->cur_pos) % (MEM_SIZE * 2);
	if (tmp->cur_pos < 0)
		tmp->cur_pos = (MEM_SIZE * 2 + tmp->cur_pos) % 8192;
	tmp->carry = processor->carry;
	tmp->pl_num = processor->pl_num;
	tmp->pl_number = processor->pl_number;
	tmp->alive = processor->alive;
	tmp->proc_num = ++g_global;

	tmp->command[0] = '.';
	tmp->command[1] = '.';
	tmp->command[2] = '\0';
	tmp->cycle_todo = 0;
	tmp->iterator = 0;
	tmp->codage = 1;
	tmp->iC = 0;
	tmp->invalidAgr = 0;
	n = 0;
	while (n < 16)
	{
		tmp->reg[n] = processor->reg[n];
		n++;
	}
	tmp->t_dir = 0;
	ptr = processor;
	while (ptr->next)
		ptr = ptr->next;
	doNull(tmp);
	ptr->next = tmp;
	tmp->prev = ptr;
	tmp->next = NULL;
	processor->cur_pos = (processor->iterator + processor->cur_pos) % 8192;
	processor->iterator = 0;
}

void	lfork(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData) /* Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! (но это не точно =)))))))))))) */
{
	t_process	*tmp;
	t_process	*ptr;
	int 		n;

	if (ft_strlen(processor->arg1) != 4)
	{
		processor->cur_pos = (processor->iterator + processor->cur_pos) % 8192;
		processor->iterator = 0;
		return ;
	}
	tmp = (t_process*)malloc(sizeof(t_process));
	tmp->cur_pos = ((short)ft_atoi_base(processor->arg1, 16) * 2 + processor->cur_pos) % 8192;
	if (tmp->cur_pos < 0)
		tmp->cur_pos = (MEM_SIZE * 2 + tmp->cur_pos) % 8192;
	tmp->carry = processor->carry;
	tmp->pl_num = processor->pl_num;
	tmp->pl_number = processor->pl_number;
	tmp->alive = processor->alive;
	tmp->proc_num = ++g_global;
	if (g_global == 49 || g_global == 57)
	{

	}
	tmp->command[0] = '.';
	tmp->command[1] = '.';
	tmp->command[2] = '\0';
	tmp->cycle_todo = 0;
	tmp->iterator = 0;
	tmp->iC = 0;
	tmp->invalidAgr = 0;
	n = 0;
	while (n < 16)
	{
		tmp->reg[n] = processor->reg[n];
		n++;
	}
	tmp->t_dir = 0;
	ptr = processor;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = tmp;
	tmp->prev = ptr;
	tmp->next = NULL;
	processor->cur_pos = (processor->iterator + processor->cur_pos) % 8192;
	processor->iterator = 0;
}

void aff(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData)
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
