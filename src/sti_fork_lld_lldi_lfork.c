//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

void		sti(t_process *processor, unsigned char *map, int iz, t_player *pl)
{
	int		i;
	char	*arg2;
	int		n;
	char	*arg1;

	arg1 = ft_itoa_base(processor->reg[ft_atoi_base(processor->arg1, 16) - 1], 16);
	convert(&arg1);
	n = 0;
	arg2 = ft_strnew(8);

	mvwprintw(stdscr, 1, 200, "%d", ft_atoi_base(processor->arg2, 16));
	mvwprintw(stdscr, 1, 230, "%d", ft_atoi_base(processor->arg3, 16));
	if (ft_strlen(processor->arg2) == 4 && !processor->t_dir)
	{
		i = ft_atoi_base(processor->arg2, 16) % IDX_MOD + processor->cur_pos;
		while (n < 8)
			arg2[n++] = map[i++];
		i = ft_atoi_base(arg2, 16) + ft_atoi_base(processor->arg3, 16);
		n = 0;
	}
	else
		i = ((ft_atoi_base(processor->arg2, 16) + ft_atoi_base(processor->arg3, 16)) % IDX_MOD) * 2 + processor->cur_pos;
	while (n < 8)
		map[i++] = arg1[n++];
	ft_strdel(&arg1);
	ft_strdel(&arg2);
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
}

void	lld(t_process *processor, unsigned char *map, int iz, t_player *pl) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	int	n;
	int k;
	char *arg1;

	if (ft_strlen(processor->arg1) == 8)
	{
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] =
				(unsigned int)ft_atoi_base(processor->arg1, 16);
	}
	else if (ft_strlen(processor->arg1) == 4)
	{
		k = ft_atoi_base(processor->arg1, 16) * 2 + processor->cur_pos;
		n = 0;
		arg1 = ft_strnew(4);
		while (n < 4)
			arg1[n++] = map[k++];
		processor->reg[ft_atoi_base(processor->arg2, 16) - 1] =
				(unsigned int)ft_atoi_base(arg1, 16);
	}
	ft_strdel(&arg1);
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
}

void	lldi(t_process *processor, unsigned char *map, int iz, t_player *pl) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	int		i;
	char	*arg1;
	int		n;

	n = 0;
	arg1 = ft_strnew(8);
	if (ft_strlen(processor->arg1) == 4 && !processor->t_dir)
	{
		i = (ft_atoi_base(processor->arg1, 16) % IDX_MOD)
			* 2 + processor->cur_pos;
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
	processor->cur_pos += processor->iterator % 8192;
	processor->iterator = 0;
	ft_strdel(&arg1);
}

void	fork_c(t_process *processor, unsigned char *map, int iz, t_player *pl) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! (но это не точно =))))))))))))
{
	t_process	*tmp;
	t_process	*ptr;
	int 		n;

	tmp = (t_process*)malloc(sizeof(t_process));
	tmp->cur_pos = ft_atoi_base(processor->arg1, 16) % IDX_MOD * 2 + processor->cur_pos;
	tmp->carry = processor->carry;
	tmp->pl_num = processor->pl_num;
	tmp->alive = processor->alive;
	tmp->command[0] = '.';
	tmp->command[1] = '.';
	tmp->command[2] = '\0';
	tmp->cycle_todo = 0;
	tmp->iterator = 0;
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
}

void	lfork(t_process *processor, unsigned char *map, int iz, t_player *pl) /* Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! (но это не точно =)))))))))))) */
{
	t_process	*tmp;
	t_process	*ptr;
	int 		n;

	tmp = (t_process*)malloc(sizeof(t_process));
	tmp->cur_pos = ft_atoi_base(processor->arg1, 16) * 2 + processor->cur_pos;
	tmp->carry = processor->carry;
	tmp->pl_num = processor->pl_num;
	tmp->alive = processor->alive;
	tmp->command[0] = '.';
	tmp->command[1] = '.';
	tmp->command[2] = '\0';
	tmp->cycle_todo = 0;
	tmp->iterator = 0;
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
}
