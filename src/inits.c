//
// Created by Roman KYSLYY on 7/12/18.
//

#include "../inc/corewar.h"

void    initMap(unsigned char map[], char **total, header_t *header, char **argv)
{
	int     n;
	int     fd;
	char    *work;

	n = 0;
	while (n < MEM_SIZE * 2)
		map[n++] = '0';
	fd = open(argv[1], O_RDONLY);
	read(fd, header, sizeof(header_t));
	getTotal(fd, total);
	n = 0;
	work = *total;
	while (work[n] != '\0')
	{
		map[n] = work[n];
		n++;
	}
	close(fd);
}

void	initProcesses(t_process **processes)
{
	t_process	*tmp;
	int 		n;

	*processes = (t_process*)malloc(sizeof(t_process));
	tmp = *processes;
	tmp->cur_pos = 0;
	tmp->carry = 0;
	tmp->pl_num = 0;
	tmp->alive = 0;
	tmp->command[0] = '.';
	tmp->command[1] = '.';
	tmp->command[2] = '\0';
	tmp->cycle_todo = 0;
	tmp->iterator = 0;
	n = 0;
	while (n < 16)
		tmp->reg[n++] = 0;
	tmp->reg[0] = -1;
	tmp->next = NULL;
}

void initfunc(functions_t func[])
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
}
