//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

void    initMap(unsigned char map[], t_vizData *vizData, t_player *players)
{
	int         n;
	int         fd;
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
	n = 1;
	while (players)
	{
		read(players->fd, &players->header, sizeof(header_t));
		getTotal(players, &total, vizData, n);
		players = players->next;
		++n;
	}
//	fd = open(argv[1], O_RDONLY);
//	read(fd, header, sizeof(header_t));
//	getTotal(fd, total, vizData);
	n = 0;
//	work = total;
//	while (work[n] != '\0')
//	{
//		map[n] = work[n];
//		n++;
//	}
	close(fd);
}

void	initProcesses(t_process **processes)
{
	t_process	*tmp;
	int 		n;

	*processes = (t_process*)malloc(sizeof(t_process));
	tmp = *processes;
	tmp->cur_pos = 0;
	tmp->prev_pos = 0;
	tmp->carry = 0;
	tmp->proc_num = 1;
	tmp->pl_num = -1;
	tmp->alive = 0;
	tmp->iC = 0;
	tmp->command[0] = '.';
	tmp->command[1] = '.';
	tmp->command[2] = '\0';
	tmp->cycle_todo = 0;
	tmp->iterator = 0;
	tmp->fresh = 0;
	n = 0;
	while (n < 16)
		tmp->reg[n++] = 0;
	tmp->reg[0] = -1;
	tmp->t_dir = 0;
	tmp->invalidAgr = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
}

void initfunc(functions_t func[]) // Обновленно (но чето выебуется впадло разбираться пошел домой) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	func[0].codage = 0;
	func[0].funcptr = &live;
	func[0].cycles = 10;
	func[0].name = "01";

	func[1].codage = 1;
	func[1].funcptr = &ld;
	func[1].cycles = 5;
	func[1].name = "02";

	func[2].codage = 1;
	func[2].funcptr = &st;
	func[2].cycles = 5;
	func[2].name = "03";

	func[3].codage = 1;
	func[3].funcptr = &add;
	func[3].cycles = 10;
	func[3].name = "04";

	func[4].codage = 1;
	func[4].funcptr = &sub;
	func[4].cycles = 10;
	func[4].name = "05";

	func[5].codage = 1;
	func[5].funcptr = &and;
	func[5].cycles = 6;
	func[5].name = "06";

	func[6].codage = 1;
	func[6].funcptr = &or;
	func[6].cycles = 6;
	func[6].name = "07";

	func[7].codage = 1;
	func[7].funcptr = &xor;
	func[7].cycles = 6;
	func[7].name = "08";

	func[8].codage = 0;
	func[8].funcptr = &zjmp;
	func[8].cycles = 20;
	func[8].name = "09";

	func[9].codage = 1;
	func[9].funcptr = &ldi;
	func[9].cycles = 25;
	func[9].name = "0a";

	func[10].codage = 1;
	func[10].funcptr = &sti;
	func[10].cycles = 25;
	func[10].name = "0b";

	func[11].codage = 0;
	func[11].funcptr = &fork_c;
	func[11].cycles = 800;
	func[11].name = "0c";

	func[12].codage = 1;
	func[12].funcptr = &lld;
	func[12].cycles = 10;
	func[12].name = "0d";

	func[13].codage = 1;
	func[13].funcptr = &lldi;
	func[13].cycles = 50;
	func[13].name = "0e";

	func[14].codage = 0;
	func[14].funcptr = &lfork;
	func[14].cycles = 1000;
	func[14].name = "0f";

	func[15].codage = 1;
	func[15].funcptr = &aff;
	func[15].cycles = 2;
	func[15].name = "10";
}