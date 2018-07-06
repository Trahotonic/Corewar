# include "./../inc/corewar.h"

void    getTotal(int fd, char **total)
{
    int n;
    unsigned int buff;
    char *str;

    n = 1;
    *total = ft_strnew(0);
    while ((n = read(fd, &buff, sizeof(int))))
    {
        buff = ((buff & 0x000000FF) << 24) | ((buff & 0x0000FF00) <<  8) |
               ((buff & 0x00FF0000) >>  8) | ((buff & 0xFF000000) >> 24);
        if (n == 1)
            str = ft_strsub(ft_uitoa_base2(buff, 16), 0, 2);
        else if (n == 2)
            str = ft_strsub(ft_uitoa_base2(buff, 16), 0, 4);
        else if (n == 3)
            str = ft_strsub(ft_uitoa_base2(buff, 16), 0, 6);
        else
        {
            str = ft_uitoa_base2(buff, 16);
            convert(&str);
        }
        *total = ft_arrg_join(*total, str);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
	header_t	header;
	char		*total;
	unsigned char	map[4096];
	int n = 0;
	while (n < 4096)
		map[n++] = 0;
	int fd = open(argv[1], O_RDONLY);
	read(fd, &header, sizeof(header_t));
    getTotal(fd, &total);
	n = 0;
    while (total[n] != '\0')
    {
        map[n] = total[n];
        n++;
    }
    printf("%s\n", map);
	close(fd);
	return 0;
}