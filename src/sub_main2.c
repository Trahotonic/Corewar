//
// Created by Roman KYSLYY on 8/28/18.
//

#include "../inc/corewar.h"

static void	sub_dump(unsigned char map[], int *m)
{
	int		n;
	char	tmp[3];

	n = 0;
	tmp[2] = '\0';
	while (n < 64)
	{
		tmp[0] = map[*m];
		*m = *m + 1;
		tmp[1] = map[*m];
		*m = *m + 1;
		ft_printf("%s ", tmp);
		n++;
	}
}

void	dump(unsigned char map[], t_player *players)
{
	int		n;
	int 	m;
	int 	q;
	int 	row;
	char 	*r;

	q = 0;
	row = 0;
	m = 0;
	while (q < 64)
	{
		n = 2;
		r = ft_itoa_base(row, 16);
		ft_printf("0x");
		while (n++ < 6 - ft_strlen(r))
			ft_printf("0");
		ft_printf("%s : ", r);
		sub_dump(map, &m);
		ft_printf("\n");
		row += 64;
		q++;
	}
}

void	runProcesses(t_process **processes, unsigned char map[], functions_t array[], int i, t_player *player, t_viz_data *vizData)
{
	t_process	*go;
	int 		n;
	char 		tmp[3];

	tmp[2] = '\0';
	go = *processes;
	n = 0;
	if (i == 9690)
	{

	}
	while (go)
	{
		if (go->invalidAgr)
		{
			go->invalidAgr = 0;
			go->cur_pos = (go->cur_pos + 2) % (MEM_SIZE * 2);
			go = go->next;
			continue ;
		}
		if (go->com2 == 0)
		{
			tmp[0] = map[go->cur_pos];
			tmp[1] = map[go->cur_pos + 1];
			go->com2 = ab(tmp, 16);
			while (n < 16 && go->com2 != array[n].name2)
				++n;
			if (n == 16)
			{
				go->invalidAgr = 1;
				go->com2 = 0;
				n = 0;
				continue ;
			}
			go->cycle_todo = array[n].cycles;
			go->codage = array[n].codage;
			n = 0;
		}
		if (go->cycle_todo > 0)
			--go->cycle_todo;
		if ((go->com2 > 0 && go->com2 <= 16)
			&& !go->cycle_todo)
		{
			read_shit(map, go);
			if (ft_strequ(go->arg1, "ff09"))
			{

			}
			if (go->com2 == 1)
				live(go, i, player);
			else if (go->com2 == 2)
				ld(go, map);
			else if (go->com2 == 3)
				st(go, map, vizData);
			else if (go->com2 == 4)
				add(go);
			else if (go->com2 == 5)
				sub(go);
			else if (go->com2 == 6)
				and(go);
			else if (go->com2 == 7)
				or(go);
			else if (go->com2 == 8)
				xor(go);
			else if (go->com2 == 9)
				zjmp(go);
			else if (go->com2 == 10)
				ldi(go, map);
			else if (go->com2 == 11)
				sti(go, map, vizData);
			else if (go->com2 == 12)
				fork_c(processes, go);
			else if (go->com2 == 13)
				lld(go, map);
			else if (go->com2 == 14)
				lldi(go, map);
			else if (go->com2 == 15)
				lfork(processes, go);
			else if (go->com2 == 16)
				aff(go, map, vizData);
			go->com2 = 0;
			go->iC = 0;
		}
		go = go->next;
	}
}
