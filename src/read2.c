//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"


void	doNull(t_process *processor)
{
	int n = 0;

	while (n++ < 9)
	{
		processor->arg1[n] = '\0';
		processor->arg2[n] = '\0';
		processor->arg3[n] = '\0';
	}
}

void	readLittleShit(unsigned char map[], char arg1[], char tmp[], t_process *processor)
{
	int n;

	n = 0;
	if (ft_strequ(tmp, "01"))
	{
		while (n < 2)
			arg1[n++] = map[processor->iterator++];
	}
	else if (ft_strequ(tmp, "11"))
	{
		while (n < 4)
			arg1[n++] = map[processor->iterator++];
	}
	else if (ft_strequ(tmp, "10") && (ft_strequ(processor->command, "lldi") || ft_strequ(processor->command, "ldi")))
	{
		while (n < 4)
			arg1[n++] = map[processor->iterator++];
	}
	else if (ft_strequ(tmp, "10") && !ft_strequ(processor->command, "lldi") && !ft_strequ(processor->command, "ldi"))
	{
		while (n < 8)
			arg1[n++] = map[processor->iterator++];
	}
}

void	readShit(unsigned char map[], t_process *processor)
{
	int		n;
	char 	tmp[3];
	char 	*bin;

	tmp[2] = '\0';
	doNull(processor);
	if (processor->codage == 0)
	{
		processor->iterator += 2;
	}
	else
	{
		tmp[0] = map[processor->cur_pos + 2];
		tmp[1] = map[processor->cur_pos + 3];
		processor->iterator += 4;
		n = ft_atoi_base(tmp, 16);
		bin = ft_convert_2(n, 8);
		tmp[0] = bin[0];
		tmp[1] = bin[1];
		readLittleShit(map, processor->arg1, tmp, processor);
		tmp[0] = bin[2];
		tmp[1] = bin[3];
		readLittleShit(map, processor->arg2, tmp, processor);
		tmp[0] = bin[4];
		tmp[1] = bin[5];
		readLittleShit(map, processor->arg3, tmp, processor);
	}
}
