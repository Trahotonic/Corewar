//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"


void	doNull(t_process *processor)
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

void	readLittleShit(unsigned char map[], char arg1[], char tmp[], t_process *processor)
{
	int n;

	n = 0;
	if (ft_strequ(tmp, "01"))
	{
		while (n < 2)
			arg1[n++] = map[(processor->cur_pos + processor->iterator++) % (MEM_SIZE * 2)];
		if ((unsigned char)ft_atoi_base(arg1, 16) > 15)
			processor->iC = 1;
	}
	else if (ft_strequ(tmp, "11"))
	{
		while (n < 4)
			arg1[n++] = map[processor->cur_pos + processor->iterator++];
	}
	else if (ft_strequ(tmp, "10") && (ft_strequ(processor->command, "0e") || ft_strequ(processor->command, "0a") ||
			(ft_strequ(processor->command, "0b")) || (ft_strequ(processor->command, "09")) ||
			(ft_strequ(processor->command, "0c")) || (ft_strequ(processor->command, "0f"))))
	{
		processor->t_dir = 1;
		while (n < 4)
			arg1[n++] = map[(processor->cur_pos + processor->iterator++) % (MEM_SIZE * 2)];
	}
	else if (ft_strequ(tmp, "10") && !ft_strequ(processor->command, "0e") && !ft_strequ(processor->command, "0a"))
	{
		while (n < 8)
			arg1[n++] = map[(processor->cur_pos + processor->iterator++) % (MEM_SIZE * 2)];
	}
}

int ft_validation_codage(unsigned char map[], t_process *processor)
{
	int  n;
	char tmp[3];
	char  *bin;
	char *frstbyte;
	char *secbyte;
	char *thrdbyte;

	tmp[0] = map[processor->cur_pos + 2];
	tmp[1] = map[processor->cur_pos + 3];
	processor->iterator += 4;
	n = ft_atoi_base(tmp, 16);
	bin = ft_convert_2(n, 8);
	frstbyte = ft_strsub(bin, 0, 2);
	secbyte = ft_strsub(bin, 2, 2);
	thrdbyte = ft_strsub(bin, 4, 2);
	if (ft_strequ(processor->command, "02"))
	{
		if ((ft_strequ(frstbyte, "10") || ft_strequ(frstbyte, "11")) && ft_strequ(secbyte, "01"))
			return (1);
		else
		{
			processor->iC = 1;
			if (ft_strequ(frstbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(frstbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(secbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(secbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "01"))
				processor->iterator += 1;
			return (0);
		}
	}
	if (ft_strequ(processor->command, "03"))
	{
		if (ft_strequ(frstbyte, "01")  && (ft_strequ(secbyte, "01") || ft_strequ(secbyte, "11")))
			return (1);
		else
		{
			processor->iC = 1;
			if (ft_strequ(frstbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(frstbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(secbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(secbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "01"))
				processor->iterator += 1;
			return (0);
		}
	}
	if (ft_strequ(processor->command, "04"))
	{
		if (ft_strequ(frstbyte, "01")  && ft_strequ(thrdbyte, "01") && ft_strequ(secbyte, "01"))
			return (1);
		else
		{
			processor->iC = 1;
			if (ft_strequ(frstbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(frstbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(secbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(secbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(thrdbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(thrdbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(thrdbyte, "01"))
				processor->iterator += 1;
			return (0);
		}
	}
	if (ft_strequ(processor->command, "05"))
	{
		if (ft_strequ(frstbyte, "01")  && ft_strequ(thrdbyte, "01") && ft_strequ(secbyte, "01"))
			return (1);
		else
		{
			processor->iC = 1;
			if (ft_strequ(frstbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(frstbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(secbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(secbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(thrdbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(thrdbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(thrdbyte, "01"))
				processor->iterator += 1;
			return (0);
		}
	}
	if (ft_strequ(processor->command, "06"))
	{
		if (!ft_strequ(frstbyte, "00") && !ft_strequ(secbyte, "00") && ft_strequ(thrdbyte, "01"))
			return (1);
		else
		{
			processor->iC = 1;
			if (ft_strequ(frstbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(frstbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(secbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(secbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(thrdbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(thrdbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(thrdbyte, "01"))
				processor->iterator += 1;
			return (0);
		}
	}
	if (ft_strequ(processor->command, "07"))
	{
		if (!ft_strequ(frstbyte, "00") && !ft_strequ(secbyte, "00") && ft_strequ(thrdbyte, "01"))
			return (1);
		else
		{
			processor->iC = 1;
			if (ft_strequ(frstbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(frstbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(secbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(secbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(thrdbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(thrdbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(thrdbyte, "01"))
				processor->iterator += 1;
			return (0);
		}
	}
	if (ft_strequ(processor->command, "08"))
	{
		if (!ft_strequ(frstbyte, "00") && !ft_strequ(secbyte, "00") && ft_strequ(thrdbyte, "01"))
			return (1);
		else
		{
			processor->iC = 1;
			if (ft_strequ(frstbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(frstbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(secbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(secbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(thrdbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(thrdbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(thrdbyte, "01"))
				processor->iterator += 1;
			return (0);
		}
	}
	if (ft_strequ(processor->command, "0a"))
	{
		if (!ft_strequ(frstbyte, "00") && (ft_strequ(secbyte, "01") || ft_strequ(secbyte, "10")) && ft_strequ(thrdbyte, "01"))
			return (1);
		else
		{
			processor->iC = 1;
			if (ft_strequ(frstbyte, "10"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(secbyte, "10"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(thrdbyte, "10"))
				processor->iterator += 2;
			if (ft_strequ(thrdbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(thrdbyte, "01"))
				processor->iterator += 1;
			return (0);
		}
	}
	if (ft_strequ(processor->command, "0b"))
	{
		if (ft_strequ(frstbyte, "01") && !ft_strequ(secbyte, "00") && (ft_strequ(thrdbyte, "01") || ft_strequ(thrdbyte, "10")))
			return (1);
		else
		{
			processor->iC = 1;
			if (ft_strequ(frstbyte, "10"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(secbyte, "10"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(thrdbyte, "10"))
				processor->iterator += 2;
			if (ft_strequ(thrdbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(thrdbyte, "01"))
				processor->iterator += 1;
			return (0);
		}
	}
	if (ft_strequ(processor->command, "0d"))
	{
		if ((ft_strequ(frstbyte, "10") || ft_strequ(frstbyte, "11")) && ft_strequ(secbyte, "01"))
			return (1);
		else
		{
			processor->iC = 1;
			if (ft_strequ(frstbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(frstbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(secbyte, "10"))
				processor->iterator += 4;
			if (ft_strequ(secbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "01"))
				processor->iterator += 1;
			return (0);
		}
	}
	if (ft_strequ(processor->command, "0e"))
	{
		if (!ft_strequ(frstbyte, "00") && (ft_strequ(secbyte, "10") || ft_strequ(secbyte, "01")) && ft_strequ(thrdbyte, "01"))
			return (1);
		else
		{
			processor->iC = 1;
			if (ft_strequ(frstbyte, "10"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(frstbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(secbyte, "10"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(secbyte, "01"))
				processor->iterator += 1;
			if (ft_strequ(thrdbyte, "10"))
				processor->iterator += 2;
			if (ft_strequ(thrdbyte, "11"))
				processor->iterator += 2;
			if (ft_strequ(thrdbyte, "01"))
				processor->iterator += 1;
			return (0);
		}
	}
	return (1);
}

void	readShit(unsigned char map[], t_process *processor) // Обновленно !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	int		n;
	char 	tmp[3];
	char 	*bin;

	tmp[2] = '\0';
	doNull(processor);
	if (processor->codage == 0)
	{
		processor->iterator += 2;
		readLittleShit(map, processor->arg1, "10", processor);
	}
	else
	{
//		if (!ft_validation_codage(map, processor))
//			return ;
		tmp[0] = map[processor->cur_pos + 2];
		tmp[1] = map[processor->cur_pos + 3];
		processor->iterator += 4;
		n = ft_atoi_base(tmp, 16);
		bin = ft_convert_2(n, 8);
		tmp[0] = bin[0];
		tmp[1] = bin[1];
//		if (bin[0] == '0' && bin[1] == '0')
//			return ;
		readLittleShit(map, processor->arg1, tmp, processor);
		tmp[0] = bin[2];
		tmp[1] = bin[3];
//		if (bin[0] == '0' && bin[1] == '0')
//		{
//			processor->iterator = 4;
//			return ;
//		}
		readLittleShit(map, processor->arg2, tmp, processor);
		tmp[0] = bin[4];
		tmp[1] = bin[5];
		readLittleShit(map, processor->arg3, tmp, processor);
	}
}
