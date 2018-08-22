//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"


void	do_null(t_process *processor)
{
	int n = 0;

	processor->t_dir = 0;
	while (n < 9)
	{
		processor->arg1[n] = '\0';
		processor->arg2[n] = '\0';
		processor->arg3[n] = '\0';
		n++;
	}
}

void	readLittleShit(unsigned char map[], char arg1[], int tmp, t_process *processor, int arg)
{
	int n;

	n = 0;
	if (tmp == 1)
	{
		while (n < 2)
			arg1[n++] = map[(processor->cur_pos + processor->iterator++) % (MEM_SIZE * 2)];
		if ((unsigned char)ft_atoi_base(arg1, 16) > 16 || (unsigned char)ft_atoi_base(arg1, 16) <= 0)
			processor->iC = 1;
	}
	else if (tmp == 3)
	{
		while (n < 4)
			arg1[n++] = map[(processor->cur_pos + processor->iterator++) % (MEM_SIZE * 2)];
	}
	else if (tmp == 2 && (processor->com2 == 14 || processor->com2 == 10 ||
			(processor->com2 == 11 || processor->com2 == 9) ||
			(processor->com2 == 12) || (processor->com2 == 15)))
	{
		processor->t_dir += arg;
		while (n < 4)
			arg1[n++] = map[(processor->cur_pos + processor->iterator++) % (MEM_SIZE * 2)];
	}
	else if (tmp == 2 && processor->com2 != 14 && processor->com2 != 10)
	{
		while (n < 8)
			arg1[n++] = map[(processor->cur_pos + processor->iterator++) % (MEM_SIZE * 2)];
	}
}

void	read_shit(unsigned char *map, t_process *processor) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	int		n;
	char 	tmp[3];
	char 	*bin;

	tmp[2] = '\0';
	do_null(processor);
	if (processor->codage == 0)
	{
		processor->iterator += 2;
		readLittleShit(map, processor->arg1, 2, processor, 1);
	}
	else
	{
		tmp[0] = map[(processor->cur_pos + 2) % (MEM_SIZE * 2)];
		tmp[1] = map[(processor->cur_pos + 3) % (MEM_SIZE * 2)];
		processor->iterator += 4;
		n = ft_atoi_base(tmp, 16);
		readLittleShit(map, processor->arg1, saver(n, 8, 0), processor, 1);
		readLittleShit(map, processor->arg2, saver(n, 8, 2), processor, 2);
		readLittleShit(map, processor->arg3, saver(n, 8, 4), processor, 3);
	}
}
