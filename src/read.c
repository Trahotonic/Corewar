/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:35:42 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 15:35:45 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

char		*ft_arrg_join(char *s1, char *s2)
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

void		convert(char **str)
{
	char	*new;
	char	*work;
	int		n;
	int		m;

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

void		case123(unsigned int buff, char **str, ssize_t n)
{
	char	*dump;

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

void		shmatok(unsigned int *buff, char **str, int n, char **total)
{
	*buff = bit_swaper(*buff);
	if (n == 1 || n == 2 || n == 3)
		case123(*buff, str, n);
	else
	{
		*str = ft_uitoa_base2(*buff, 16);
		convert(str);
	}
	*total = ft_arrg_join(*total, *str);
	*buff = 0;
}

void		get_total(t_player *players, char **total,
					t_viz_data *viz_data, int c)
{
	int				n;
	unsigned int	buff;
	char			*str;
	int				count;
	int				q;

	count = get_count(players);
	q = 1;
	while (q < c)
	{
		++q;
		players = players->next;
	}
	players->start = get_start(count, c);
	*total = ft_strnew(0);
	while ((n = (int)read(players->fd, &buff, sizeof(int))))
		shmatok(&buff, &str, n, total);
	q = 0;
	while (q < ft_strlen(*total))
	{
		viz_data->viz_data[players->start + q] = c;
		viz_data->mark_timeout[players->start + q] = 0;
		++q;
	}
	viz_data->print = NULL;
}
