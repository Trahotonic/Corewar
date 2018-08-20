//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

static int     getCount(t_player *players)
{
	int count;

	count = 0;
	while (players)
	{
		++count;
		players = players->next;
	}
	return (count);
}

static int     setStart(int count, int idx)
{
	if (count == 1 || idx == 1)
		return (0);
	if (count == 2)
		return (MEM_SIZE);
	else if (count == 3)
	{
		if (idx == 2)
			return ((MEM_SIZE * 2) / 3);
		else
			return (((MEM_SIZE * 2) / 3) * 2);
	}
	else
	{
		if (idx == 2)
			return ((MEM_SIZE * 2) / 4);
		else if (idx == 3)
			return (((MEM_SIZE * 2) / 4) * 2);
		else
			return (((MEM_SIZE * 2) / 4) * 3);
	}
}

void 	fillMap(char *total, int count, int idx, unsigned char map[])
{
	int n;
	int m;

	m = 0;
	if (count == 1 || idx == 1)
	{
		n = 0;
		while (total[m] != '\0')
		{
			map[n] = total[m];
			n++;
			m++;
		}
	}
	else if (count == 2)
	{
		n = MEM_SIZE;
		while (total[m] != '\0')
		{
			map[n] = total[m];
			n++;
			m++;
		}
	}
	else if (count == 3)
	{
		if (idx == 2)
			n = (MEM_SIZE * 2) / 3;
		else
			n = ((MEM_SIZE * 2) / 3) * 2;
		while (total[m] != '\0')
		{
			map[n] = total[m];
			n++;
			m++;
		}
	}
	else
	{
		if (idx == 2)
			n =  (MEM_SIZE * 2) / 4;
		else if (idx == 3)
			n = ((MEM_SIZE * 2) / 4) * 2;
		else
			n = ((MEM_SIZE * 2) / 4) * 3;
		while (total[m] != '\0')
		{
			map[n] = total[m];
			n++;
			m++;
		}
	}
}

void    initMap(unsigned char map[], t_vizData *vizData, t_player *players)
{
	int         n;
	int			count;
	char        *total;
	t_player	*ptr;


	n = 0;
	while (n < MEM_SIZE * 2)
	{
		vizData->markTimeout[n] = 0;
		vizData->vizData[n] = 0;
		map[n++] = '0';
	}
	count = getCount(players);
	n = 1;
	ptr = players;
	while (ptr)
	{
		read(ptr->fd, &ptr->header, sizeof(header_t));
		getTotal(players, &total, vizData, n);
		fillMap(total, count, n, map);
		ft_strdel(&total);
		ptr = ptr->next;
		++n;
	}
	vizData->space = false;
}


void	initProcesses(t_process **processes, t_player *players)
{
	t_process	*tmp;
	t_process	*ptr;
	int 		n;
	int 		idx;
	int 		count;

	idx = 1;
	count = getCount(players);
	while (players)
	{
		tmp = (t_process *)malloc(sizeof(t_process));
		tmp->cur_pos = setStart(count, idx);
		tmp->carry = 0;
		tmp->pl_num = players->playerNumber;
		tmp->pl_number = players->num;
		tmp->alive = 0;
		tmp->iC = 0;
		tmp->com2 = 0;
		tmp->cycle_todo = 0;
		tmp->iterator = 0;
		n = 0;
		while (n < 16)
			tmp->reg[n++] = 0;
		tmp->reg[0] = players->playerNumber;
		tmp->t_dir = 0;
		tmp->invalidAgr = 0;
		tmp->next = NULL;
		tmp->prev = NULL;
		if (*processes == NULL)
			*processes = tmp;
		else
		{
			ptr = *processes;
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = tmp;
			tmp->prev = ptr;
		}
		++idx;
		players = players->next;
	}

}

void initfunc(functions_t func[]) // Обновленно (но чето выебуется впадло разбираться пошел домой) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	func[0].codage = 0;
	func[0].cycles = 10;
	func[0].name2 = 1;

	func[1].codage = 1;
	func[1].cycles = 5;
	func[1].name2 = 2;

	func[2].codage = 1;
	func[2].cycles = 5;
	func[2].name2 = 3;

	func[3].codage = 1;
	func[3].cycles = 10;
	func[3].name2 = 4;

	func[4].codage = 1;
	func[4].cycles = 10;
	func[4].name2 = 5;

	func[5].codage = 1;
	func[5].cycles = 6;
	func[5].name2 = 6;

	func[6].codage = 1;
	func[6].cycles = 6;
	func[6].name2 = 7;

	func[7].codage = 1;
	func[7].cycles = 6;
	func[7].name2 = 8;

	func[8].codage = 0;
	func[8].cycles = 20;
	func[8].name2 = 9;

	func[9].codage = 1;
	func[9].cycles = 25;
	func[9].name2 = 10;

	func[10].codage = 1;
	func[10].cycles = 25;
	func[10].name2 = 11;

	func[11].codage = 0;
	func[11].cycles = 800;
	func[11].name2 = 12;

	func[12].codage = 1;
	func[12].cycles = 10;
	func[12].name2 = 13;

	func[13].codage = 1;
	func[13].cycles = 50;
	func[13].name2 = 14;

	func[14].codage = 0;
	func[14].cycles = 1000;
	func[14].name2 = 15;

	func[15].codage = 1;
	func[15].cycles = 2;
	func[15].name2 = 16;
}