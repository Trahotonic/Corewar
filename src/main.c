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
	while (n++ < 16)
	{
		tmp->reg[n] = 0;
	}
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

void  live(t_process processor, char *map, int i, t_player pl[])
{
	int n;
	int m;
	char name[9];

	m = processor.cur_pos + 1;
	name[8] = 0;
	n = 0;
	processor.alive = 1;
	while(n < 8)
		name[n++] = map[m++];
	while(pl)
	{
		if (ft_strequ(pl->header.prog_name, name))
		{
			pl->lastAlive = i;
			break;
		}
	}
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


void  ld(t_process processor, char *map, int iz, t_player pl[])
{
	char *tmp;
	int  i;
	int  n;
	char *ret;
	char  *tmp2;

	tmp2 = ft_strnew(2);
	n = 0;
	i = processor.cur_pos + 1;
	tmp = ft_strnew(2);
	while (n < 2)
		tmp[n++] = map[i++];
	n = ft_atoi_base(tmp, 16);
	ft_strdel(&tmp);
	ret = ft_itoa_base(n,10);
	n = ft_atoi(ret);
	ft_strdel(&ret);
	ret = ft_convert_2(n, 8);
	n = 0;
	if (ft_strequ(ret, "10"))
	{
		while (n < 8)
			tmp[n++] = map[i++];

		n = 0;
		while (n < 2)
			tmp2[n++] = map[i++];
		n = ft_atoi(tmp2);
		processor.reg[n] = ft_atoi_base(tmp, 16);;
	}
	else if (ft_strequ(ret, "11"))
	{
		char *tmp3;
		tmp3 = ft_strnew(4);
		while(n < 4)
			tmp3[n++] = map[i++];
		n = ft_atoi_base(tmp3, 10);
		int k;
		k = processor.cur_pos + n * 2;
		ft_strdel(&tmp3);
		tmp3 = ft_strnew(8);
		n = 0;
		while (n < 8)
			tmp3[n++] = map[k++];
		processor.reg[1] = ft_atoi_base(tmp3, 16);
	}

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
}


void	runProcesses(t_process **processes, unsigned char map[], functions_t array[], int i)
{
	t_process *go;

	go = *processes;
	while (go)
	{
		if (ft_strequ("..", go->command))
		{
			go->command[0] = map[go->cur_pos];
			go->command[1] = map[go->cur_pos + 1];
			go->cycle_todo = 10;
		}
		else if (ft_strequ("02", go->command))
		{
//			array[1].funcptr(*go, map, i, );
		}
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
	functions_t		array[2];

    if (argc != 2)
        return 1;
	initProcesses(&processes);
    initMap(map, &total, &header, argv);
	initVis();
	initfunc(array);
	i = 0x2a;
	while (i++ < 1536)
	{
		runProcesses(&processes, map, array, i);
		visualize(map, ft_strlen(total));
		mvwprintw(stdscr, 0, 200, "%d", i);
		usleep(2000);
	}
    free(total);
	endwin();
	return 0;
}