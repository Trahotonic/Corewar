# include "./../inc/corewar.h"

void    initMap(unsigned char map[], char **total, header_t *header, char **argv)
{
    int     n;
    int     fd;
    char    *work;

    n = 0;
    while (n < 4096)
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

int  ft_iswhitespace(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

int base(int c, int base)
{
	char *str = "0123456789abcdef";
	char *str2 = "0123456789ABCDEF";
	int  i = 0;

	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int nb = 0;
	int negatif = 0;
	int i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negatif = 1;
		i++;
	}
	while (base(str[i], str_base) != -1)
	{
		nb = nb * str_base;
		nb = nb + base(str[i], str_base);
		i++;
	}
	if (negatif)
		return (-nb);
	return (nb);
}

void  live(t_process *processor, unsigned char *map, int i, t_player *pl)
{
	int n;
	int m;
	char name[9];

	m = processor->cur_pos + 2;
	name[8] = 0;
	n = 0;
	processor->alive = 1;
	while(n < 8)
		name[n++] = map[m++];
	pl->lastAlive = i;
	processor->cur_pos = m;
}

int ft_bto_i(char *bin)
{
	int plus;
	int ret;

	ret = 0;
	plus = 124;
	while (plus >= 1)
	{
		if (*bin == '1')
			ret += plus;
		plus /= 2;
		bin++;
	}
	return (ret);
}

char *ft_convert_2(int tmp, int base)
{
	char *str;

	str = ft_strnew(base);
	base -= 1;
	while (base + 1)
	{
		str[base] = tmp % 2 + 48;
		tmp /= 2;
		base--;
	}
	return (str);
}

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

void  ld(t_process *processor, unsigned char *map, int iz, t_player *pl)
{
	int  n;

	if (ft_strlen(processor->arg1) == 8)
	{
		processor->reg[ft_atoi_base(processor->arg2, 16)] = ft_atoi_base(processor->arg1, 16);
	}
	else if (ft_strlen(processor->arg1) == 4)
	{
		n = ft_atoi_base(processor->arg1, 16);
		n %= IDX_MOD;
		int k;
		k = processor->cur_pos + n * 2;
		n = 0;
		while (n < 8)
			processor->arg1[n++] = map[k++];
		processor->reg[ft_atoi_base(processor->arg2, 16)] = ft_atoi_base(processor->arg1, 16);
	}
}

void	conv(char **tmp)
{
	char	*work;
	char	*new;
	int 	n;

	work = *tmp;
	if (ft_strlen(work) < 8)
	{
		new = ft_strnew(8);
		n = 0;
		while (n++ < 8 - ft_strlen(work))
			new[n] = '0';
		while (n < 8)
			new[n] = work[n];
		free(*tmp);
		*tmp = new;
	}
}

void	st(t_process *processor, unsigned char *map, int iz, t_player *pl)
{
	int  n;
	char *tmp;

	if (ft_strlen(processor->arg2) == 4)
	{
		n = ft_atoi_base(processor->arg2, 16);
		n %= IDX_MOD;
		int k;
		k = processor->cur_pos + n * 2;
		n = 0;
		tmp = ft_itoa_base(processor->reg[ft_atoi_base(processor->arg1, 16) - 1], 16);
		convert(&tmp);
		while (n < 8)
		map[k++] = tmp[n++];
	}
	else if (ft_strlen(processor->arg2) == 2)
	{
		processor->reg[ft_atoi_base(processor->arg2, 16)] = processor->reg[ft_atoi_base(processor->arg1, 16)];
	}
	processor->cur_pos = processor->iterator;
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


void	runProcesses(t_process **processes, unsigned char map[], functions_t array[], int i, t_player *player)
{
	t_process	*go;
	int 		n;

	go = *processes;
	n = 0;
	while (go)
	{
		if (ft_strequ("..", go->command))
		{
			go->command[0] = map[go->cur_pos];
			go->command[1] = map[go->cur_pos + 1];
			while (!ft_strequ(go->command, array[n].name))
				n++;
			go->cycle_todo = array[n].cycles;
			go->codage = array[n].codage;
		}
		else if (ft_strequ("01", go->command) && !go->cycle_todo)
		{
			array[0].funcptr(go, map, i, player);
			go->command[0] = '.';
			go->command[1] = '.';
		}
		else if (ft_strequ("02", go->command) && !go->cycle_todo)
		{
			readShit(map, *processes);
			array[1].funcptr(go, map, i, player);
			go->command[0] = '.';
			go->command[1] = '.';
		}
		else if (ft_strequ("03", go->command) && !go->cycle_todo)
		{
			readShit(map, *processes);
			array[2].funcptr(go, map, i, player);
			go->command[0] = '.';
			go->command[1] = '.';
		}
		if (go->cycle_todo)
			go->cycle_todo--;
		go = go->next;
	}
}

int     main(int argc, char **argv)
{
    header_t        header;
    char            *total;
    unsigned char   map[MEM_SIZE];
	t_process		*processes;
	int 			i;
	int 			c;
	functions_t		array[3];
	t_player		player;

    if (argc != 2)
        return 1;
	initProcesses(&processes);
    initMap(map, &total, &header, argv);
	initVis();
	ft_printf("%u\n", header.prog_size);
	initfunc(array);
	player.header = header;
	player.lastAlive = 0;
	player.playerNumber = -1;
	i = 0;
	while (i++ < 100)
	{
		runProcesses(&processes, map, array, i, &player);
		printf("%d\n", player.lastAlive);
		visualize(map, ft_strlen(total));
		mvwprintw(stdscr, 0, 200, "%d", i);
		mvwprintw(stdscr, 0, 230, "%d", player.lastAlive);
//		usleep(500000);
		c = getch();
		if (c == 113)
			break ;
	}
    free(total);
	endwin();
	return 0;
}