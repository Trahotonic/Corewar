/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:10:42 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 15:10:50 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		get_count(t_player *players)
{
	int	count;

	count = 0;
	while (players)
	{
		++count;
		players = players->next;
	}
	return (count);
}

int		get_start(int count, int idx)
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

void	fill_map(char *total, int count, int idx, unsigned char *map)
{
	int	n;
	int	m;

	m = 0;
	if (count == 1 || idx == 1)
		n = 0;
	else if (count == 2)
		n = MEM_SIZE;
	else if (count == 3)
		n = idx == 2 ? (MEM_SIZE * 2) / 3 : ((MEM_SIZE * 2) / 3) * 2;
	else
	{
		if (idx == 2)
			n = (MEM_SIZE * 2) / 4;
		else if (idx == 3)
			n = ((MEM_SIZE * 2) / 4) * 2;
		else
			n = ((MEM_SIZE * 2) / 4) * 3;
	}
	while (total[m] != '\0')
		map[n++] = total[m++];
}

void	init_map_sup(t_viz_data *viz_data, unsigned char *map)
{
	int	n;

	n = 0;
	while (n < MEM_SIZE * 2)
	{
		viz_data->mark_timeout[n] = 0;
		viz_data->viz_data[n] = 0;
		map[n++] = '0';
	}
}

void	init_map(unsigned char *map, t_viz_data *viz_data, t_player *players)
{
	int			n;
	int			count;
	char		*total;
	t_player	*ptr;

	init_map_sup(viz_data, map);
	count = get_count(players);
	n = 1;
	ptr = players;
	while (ptr)
	{
		if (read(ptr->fd, &ptr->h, sizeof(t_header)) < PROG_NAME_LENGTH +
				COMMENT_LENGTH + 8)
			exit(ft_printf(2, "Error: File is too small to be a champion\n"));
		ptr->h.prog_size = bit_swaper(ptr->h.prog_size);
		ptr->h.magic = bit_swaper(ptr->h.magic);
		get_total(players, &total, viz_data, n);
		error_printer(ptr, total);
		fill_map(total, count, n, map);
		ft_strdel(&total);
		ptr = ptr->next;
		++n;
	}
	viz_data->space = false;
}
