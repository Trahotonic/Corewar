//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

void  and(t_process *pro)
{
	pro->cur_pos = (pro->iterator + pro->cur_pos) % (MEM_SIZE * 2);
	pro->iterator = 0;
	if (ft_strlen(pro->arg3) != 2 || ft_strlen(pro->arg1) == 0
		|| ft_strlen(pro->arg2) == 0 || pro->iC)
		return ;
	if (ft_strlen(pro->arg1) != 2 && ft_strlen(pro->arg2) == 2)
		pro->reg[ab(pro->arg3, 16) - 1] = ab(pro->arg1, 16)
													& pro->reg[ab(pro->arg2, 16) - 1];
	else if (ft_strlen(pro->arg1) == 2 && ft_strlen(pro->arg2) != 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				pro->reg[ab(pro->arg1, 16) - 1] & ab(pro->arg2, 16);

	else if (ft_strlen(pro->arg1) == 2 && ft_strlen(pro->arg2) == 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				pro->reg[ab(pro->arg1, 16) - 1]
				& pro->reg[ab(pro->arg2, 16) - 1];
	else
		pro->reg[ab(pro->arg3, 16) - 1] =
				ab(pro->arg1, 16) & ab(pro->arg2, 16);
	if (pro->reg[ab(pro->arg3, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
}

void  or(t_process *pro)
{
	pro->cur_pos = (pro->iterator + pro->cur_pos) % (MEM_SIZE * 2);
	pro->iterator = 0;
	if (ft_strlen(pro->arg3) != 2 || ft_strlen(pro->arg1) == 0
		|| ft_strlen(pro->arg2) == 0 || pro->iC)
		return ;
	if (ft_strlen(pro->arg1) != 2 && ft_strlen(pro->arg2) == 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				ab(pro->arg1, 16) | pro->reg[ab(pro->arg2, 16) - 1];
	else if (ft_strlen(pro->arg1) == 2 && ft_strlen(pro->arg2) != 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				pro->reg[ab(pro->arg1, 16) - 1] | ab(pro->arg2, 16);
	else if (ft_strlen(pro->arg1) == 2 && ft_strlen(pro->arg2) == 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				pro->reg[ab(pro->arg1, 16) - 1]
				| pro->reg[ab(pro->arg2, 16) - 1];
	else
		pro->reg[ab(pro->arg3, 16) - 1] =
				ab(pro->arg1, 16) | ab(pro->arg2, 16);
	if (pro->reg[ab(pro->arg3, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
}

void  xor(t_process *pro)
{
	pro->cur_pos = (pro->iterator + pro->cur_pos) % (MEM_SIZE * 2);
	pro->iterator = 0;
	if (ft_strlen(pro->arg3) != 2 || ft_strlen(pro->arg1) == 0
		|| ft_strlen(pro->arg2) == 0 || pro->iC)
		return ;
	if (ft_strlen(pro->arg1) != 2 && ft_strlen(pro->arg2) == 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				ab(pro->arg1, 16) ^ pro->reg[ab(pro->arg2, 16) - 1];
	else if (ft_strlen(pro->arg1) == 2 && ft_strlen(pro->arg2) != 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				pro->reg[ab(pro->arg1, 16) - 1] ^ ab(pro->arg2, 16);
	else if (ft_strlen(pro->arg1) == 2 && ft_strlen(pro->arg2) == 2)
		pro->reg[ab(pro->arg3, 16) - 1] =
				pro->reg[ab(pro->arg1, 16) - 1]
				^ pro->reg[ab(pro->arg2, 16) - 1];
	else
		pro->reg[ab(pro->arg3, 16) - 1] =
				ab(pro->arg1, 16) ^ ab(pro->arg2, 16);
	if (pro->reg[ab(pro->arg3, 16) - 1] == 0)
		pro->carry = 1;
	else
		pro->carry = 0;
}

void zjmp(t_process *processor)
{
	int i;

	if (ft_strlen(processor->arg1) != 4 || processor->carry == 0)
	{
		processor->cur_pos = (processor->cur_pos + processor->iterator)
							 % (MEM_SIZE * 2);
		processor->iterator = 0;
		return ;
	}
	i = ((((short)ab(processor->arg1, 16)) % IDX_MOD)
		 * 2 + processor->cur_pos) % (MEM_SIZE * 2);
	if (i < 0)
		i = MEM_SIZE * 2 + i;
	i %= (MEM_SIZE * 2);
	processor->cur_pos = i;
	processor->iterator = 0;
}

int ldi_sup3(t_process *pro)
{
	int i;

	if (ft_strlen(pro->arg2) == 4)
		i = ((((short)ab(pro->arg1, 16) +
			   (short)ab(pro->arg2, 16)) % IDX_MOD)
			 * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	else
		i = ((short)((short)ab(pro->arg1, 16)
					 + pro->reg[ab(pro->arg2, 16) - 1])
			 % IDX_MOD * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	return (i);
}

int ldi_sup2(t_process *pro, unsigned char *map)
{
	int i;
	int n;
	char *arg1;

	arg1 = ft_strnew(8);
	n = 0;
	i = (((short)ab(pro->arg1, 16) % IDX_MOD)
		 * 2 + pro->cur_pos) % (MEM_SIZE
								* 2);
	if (i < 0)
		i = (MEM_SIZE * 2) + i;
	while (n < 8)
	{
		i %= (MEM_SIZE * 2);
		arg1[n++] = map[i++];
	}
	if (ft_strlen(pro->arg2) == 4)
		i = (((ab(arg1, 16) + (short)ab(pro->arg2, 16))
			  % IDX_MOD) * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	else
		i = (((ab(arg1, 16) + pro->reg[ab(pro->arg2, 16)
												 - 1]) % IDX_MOD) * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	ft_strdel(&arg1);
	return (i);
}

int ldi_sup1(t_process *pro)
{
	int i;

	if (ft_strlen(pro->arg2) == 2)
		i = (((pro->reg[ab(pro->arg1, 16) - 1]
			   + pro->reg[ab(pro->arg2, 16) - 1])% IDX_MOD)
			 * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	else
		i = (((pro->reg[ab(pro->arg1, 16) - 1]
			   + (short)ab(pro->arg2, 16)) % IDX_MOD)
			 * 2 + pro->cur_pos) % (MEM_SIZE * 2);
	return (i);
}

void ldi_print(t_process *pro, unsigned char *map, int i)
{
	char *arg1;
	int n;

	n = 0;
	arg1 = ft_strnew(8);
	while (n < 8)
	{
		i %= (MEM_SIZE * 2);
		arg1[n++] = map[i++];
	}
	pro->reg[ab(pro->arg3, 16) - 1] =
			(unsigned int)ab(arg1, 16);
	ft_strdel(&arg1);
}

void ldi(t_process *pro, unsigned char *map)
{
	int  i;

	i = 0;
	if (ft_strlen(pro->arg3) != 2 || ft_strlen(pro->arg1) == 0
		|| ft_strlen(pro->arg2) == 0 || pro->iC)
	{
		pro->cur_pos = (pro->cur_pos +pro->iterator) % (MEM_SIZE * 2);
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
		i = (MEM_SIZE * 2) + i;
	ldi_print(pro, map, i);
	pro->cur_pos = (pro->iterator + pro->cur_pos) % (MEM_SIZE * 2);
	pro->iterator = 0;
}

