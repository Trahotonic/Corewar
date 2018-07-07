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

int     main(int argc, char **argv)
{
    header_t        header;
    char            *total;
    unsigned char   map[4096];

    if (argc != 2)
        return 1;
    initMap(map, &total, &header, argv);
    visualize(map, ft_strlen(total));
    free(total);
	return 0;
}