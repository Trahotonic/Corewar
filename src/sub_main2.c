/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:41:44 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 16:43:09 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

static void	sub_dump(unsigned char map[], int *m)
{
	int		n;
	char	tmp[3];

	n = 0;
	tmp[2] = '\0';
	while (n < 64)
	{
		tmp[0] = map[*m];
		*m = *m + 1;
		tmp[1] = map[*m];
		*m = *m + 1;
		ft_printf("%s ", tmp);
		n++;
	}
}

void		dump(unsigned char map[])
{
	int		n;
	int		m;
	int		q;
	int		row;
	char	*r;

	q = 0;
	row = 0;
	m = 0;
	while (q < 64)
	{
		n = 2;
		r = ft_itoa_base(row, 16);
		ft_printf("0x");
		while (n++ < 6 - ft_strlen(r))
			ft_printf("0");
		ft_printf("%s : ", r);
		sub_dump(map, &m);
		ft_printf("\n");
		row += 64;
		q++;
	}
}

void		kill(t_process *processes)
{
	while (processes)
	{
		processes->alive = 0;
		processes = processes->next;
	}
}

static void	del_pointer(t_process **processes, t_process **ptr)
{
	t_process *tmp;

	if (*ptr == *processes)
	{
		tmp = *ptr;
		if ((*ptr)->next)
			(*ptr)->next->prev = NULL;
		*processes = (*ptr)->next;
		*ptr = *processes;
		free(tmp);
	}
	else
	{
		tmp = *ptr;
		(*ptr)->prev->next = (*ptr)->next;
		if ((*ptr)->next)
			(*ptr)->next->prev = (*ptr)->prev;
		(*ptr) = (*ptr)->next;
		free(tmp);
	}
}

void		superkill(t_process **processes, t_player *player)
{
	t_process	*ptr;
	t_player	*plptr;

	ptr = *processes;
	while (ptr)
	{
		if (!ptr->alive)
		{
			del_pointer(processes, &ptr);
			plptr = player;
			while (plptr)
			{
				plptr->liveCount = 0;
				plptr = plptr->next;
			}
			continue ;
		}
		ptr = ptr->next;
	}
}
