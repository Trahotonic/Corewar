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

char		*ft_uitoa_base2(unsigned long long value, int base)
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
