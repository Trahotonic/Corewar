//
// Created by Roman KYSLYY on 7/12/18.
//

int g_global = 1;

#include "../inc/corewar.h"

void  sti(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData) /* FIXED !!!!!!!!!!! */
{
	int  i;
	char *arg2;
	int  n;
	char *arg1;

	if (ft_strlen(processor->arg1) != 2 || ft_strlen(processor->arg2) == 0 || ft_strlen(processor->arg3) == 0)
	{
		processor->cur_pos = (processor->cur_pos + processor->iterator) % (MEM_SIZE * 2);
		processor->iterator = 0;
		return ;
	}
	arg1 = ft_itoa_base(processor->reg[ft_atoi_base(processor->arg1, 16) - 1], 16);
	convert(&arg1);
	n = 0;
	arg2 = ft_strnew(8);
	if (ft_strlen(processor->arg2) == 2)
	{
		if (ft_strlen(processor->arg3) == 2)
		{
			i = ((processor->reg[ft_atoi_base(processor->arg2, 16) - 1] + processor->reg[ft_atoi_base(processor->arg3, 16) - 1])% IDX_MOD) * 2 + processor->cur_pos;
		}
		else
		{
			i = ((short)(processor->reg[ft_atoi_base(processor->arg2, 16) - 1] + (short)(ft_atoi_base(processor->arg3, 16)))% IDX_MOD) * 2 + processor->cur_pos;
		}
	}
	else if (ft_strlen(processor->arg2) == 4) /* исправить добавить t_ind */
	{
		if (ft_strlen(processor->arg3) == 4)
		{
			i = ((((short)ft_atoi_base(processor->arg2, 16) + (short)(ft_atoi_base(processor->arg3, 16))))% IDX_MOD) * 2 + processor->cur_pos;
		}
		else
		{
			i = ((short)(((short)ft_atoi_base(processor->arg2, 16) + processor->reg[ft_atoi_base(processor->arg3, 16) - 1] ))% IDX_MOD) * 2 + processor->cur_pos;
		}
	}
	if (i < 0)
		i = MEM_SIZE * 2 + i;
	while (n < 8)
	{
		i %= MEM_SIZE * 2;
		vizData->markTimeout[i] = 100;
		vizData->vizData[i] = 1;
		map[i++] = arg1[n++];
	}
	ft_strdel(&arg1);
	ft_strdel(&arg2);
	processor->cur_pos = (processor->iterator + processor->cur_pos) % 8192;
	processor->iterator = 0;
}

void	lld(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	int	n;
	int k;
	char *arg1;

	if (ft_strlen(processor->arg3) == 2)
		processor->iterator -= 1;
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
		k = (short)ft_atoi_base(processor->arg1, 16) * 2 + processor->cur_pos;
		n = 0;
		arg1 = ft_strnew(4);
		while (n < 4)
			arg1[n++] = map[k++];
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
	arg1 = ft_strnew(8);
	if (ft_strlen(arg1) == 0 || ft_strlen(processor->arg2) == 0 || ft_strlen(processor->arg3) != 2)
	{
		processor->cur_pos = (processor->cur_pos + processor->iterator) % (MEM_SIZE * 2);
		processor->iterator = 0;
		return ;
	}
	if (ft_strlen(processor->arg1) == 4 && !processor->t_dir)
	{
		i = (ft_atoi_base(processor->arg1, 16) + processor->cur_pos) % IDX_MOD * 2;
		while (n < 8)
			arg1[n++] = map[i++];
		i = (ft_atoi_base(arg1, 16) + ft_atoi_base(processor->arg2, 16)) * 2
			+ processor->cur_pos;
		n = 0;
	}
	i = (ft_atoi_base(processor->arg1, 16) + ft_atoi_base(processor->arg2, 16))
		* 2 + processor->cur_pos;
	while (n < 8)
		arg1[n++] = map[i++];
	processor->reg[ft_atoi_base(processor->arg3, 16) -1] =
			(unsigned int)ft_atoi_base(arg1, 16);
	if (processor->reg[ft_atoi_base(processor->arg3, 16) -1] == 0)
		processor->carry = 1;
	else
		processor->carry = 0;
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
		processor->cur_pos += processor->iterator % (MEM_SIZE * 2);
		processor->iterator = 0;
		return ;
	}
	tmp = (t_process*)malloc(sizeof(t_process));
	tmp->cur_pos = ((short)(ft_atoi_base(processor->arg1, 16)) % IDX_MOD) * 2 + processor->cur_pos;
	if (tmp->cur_pos < 0)
		tmp->cur_pos = MEM_SIZE * 2 + tmp->cur_pos;
//	mvwprintw(stdscr, 0, 210, "%d", tmp->cur_pos);
	tmp->carry = processor->carry;
	tmp->pl_num = processor->pl_num;
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
		processor->cur_pos += processor->iterator % (MEM_SIZE * 2);
		processor->iterator = 0;
		return ;
	}
	tmp = (t_process*)malloc(sizeof(t_process));
	tmp->cur_pos = ((short)ft_atoi_base(processor->arg1, 16) * 2 + processor->cur_pos) % 8192;
	if (tmp->cur_pos < 0)
		tmp->cur_pos = MEM_SIZE * 2 + tmp->cur_pos;
	tmp->carry = processor->carry;
	tmp->pl_num = processor->pl_num;
	tmp->alive = processor->alive;
	tmp->proc_num = ++g_global;
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
