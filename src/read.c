//
// Created by Roman Kyslyy on 7/7/18.
//

# include "../inc/corewar.h"

char	*ft_arrg_join(char *s1, char *s2)
{
    char	*ret;
    char	*anchor;
    int		n;

    if (s1 && s2)
    {
        anchor = s2;
        if (!(ret = (char*)malloc(sizeof(char) * ((ft_strlen(s1)
                                                   + ft_strlen(s2)) + 1))))
            return (NULL);
        n = 0;
        while (s1[n] != '\0')
        {
            ret[n] = s1[n];
            n++;
        }
        while (*s2)
            ret[n++] = *s2++;
        ret[n] = '\0';
        free(s1);
        free(anchor);
        return (ret);
    }
    return (NULL);
}

char		*ft_uitoa_base2(unsigned int value, int base)
{
    char	*array;
    char	tmp[60];
    char	*ret;
    int		size;
    int		ptr;

    if (value == 0)
        return (ft_go_zero());
    array = "0123456789abcdef";
    size = 0;
    ptr = 59;
    while (value != 0)
    {
        tmp[ptr--] = array[value % base];
        value /= base;
        size++;
    }
    ptr++;
    ret = (char*)malloc(sizeof(char) * (size + 1));
    size = 0;
    while (ptr <= 59)
        ret[size++] = tmp[ptr++];
    ret[size] = '\0';
    return (ret);
}

void	convert(char **str)
{
    char	*new;
    char 	*work;
    int		n;
    int 	m;

    new = ft_strnew(8);
    work = *str;
    n = 0;
    m = 0;
    while (n < 8 - (int)ft_strlen(work))
        new[n++] = '0';
    while (n < 8)
        new[n++] = work[m++];
    free(*str);
    *str = new;
}

void    case123(unsigned int buff, char **str, ssize_t n)
{
    char    *dump;

    dump = ft_uitoa_base2(buff, 16);
	if (ft_strlen(dump) < 8)
		convert(&dump);
    if (n == 1)
        *str = ft_strsub(dump, 0, 2);
    else if (n == 2)
        *str = ft_strsub(dump, 0, 4);
    else if (n == 3)
        *str = ft_strsub(dump, 0, 6);
    free(dump);
}

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

void    getTotal(t_player *players, char **total, t_vizData *vizData, int c)
{
    ssize_t         n;
    unsigned int    buff;
    char            *str;
    int             count;
	int 			q;

	count = getCount(players);
	q = 1;
	while (q < c)
	{
		++q;
		players = players->next;
	}
	players->start = setStart(count, c);
    *total = ft_strnew(0);
    while ((n = read(players->fd, &buff, sizeof(int))))
    {
        buff = ((buff & 0x000000FF) << 24) | ((buff & 0x0000FF00) << 8) |
               ((buff & 0x00FF0000) >>  8) | ((buff & 0xFF000000) >> 24);
        if (n == 1 || n == 2 || n == 3)
            case123(buff, &str, n);
        else
        {
            str = ft_uitoa_base2(buff, 16);
            convert(&str);
        }
        *total = ft_arrg_join(*total, str);
        buff = 0;
    }
	q = 0;
    while (q < ft_strlen(*total))
    {
        vizData->vizData[players->start + q] = c;
        vizData->markTimeout[players->start + q] = 0;
        ++q;
    }
//    printf("here\n");
}
