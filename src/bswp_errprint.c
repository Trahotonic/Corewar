/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bswp_errprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:45:01 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 14:45:08 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

unsigned int	bit_swaper(unsigned int i)
{
	i = ((i & 0x000000FF) << 24) | ((i & 0x0000FF00) << 8) |
		((i & 0x00FF0000) >> 8) | ((i & 0xFF000000) >> 24);
	return (i);
}

void			error_printer(int i, t_player *ptr)
{
	if (i == 1)
		exit(ft_printf("Error: \"%s\" has too large code"
			"(%d bytes > 682 bytes)\n", ptr->h.prog_name, ptr->h.prog_size));
	if (i == 2)
		exit(ft_printf("Error: \"%s\" has an invalid"
			"header\n", ptr->h.prog_name));
}

void			check_pl_number(t_player *player)
{
	t_player	*bu;
	t_player	*buf;
	int			n;
	int			k;

	k = -1;
	n = -1;
	bu = player;
	buf = player;
	while (buf)
	{
		if (buf->playerNumber == 0)
		{
			while (n >= -4)
			{
				while (bu && bu->playerNumber != n && buf->playerNumber == 0)
					bu = bu->next;
				!bu ? buf->playerNumber = n : 0;
				bu = player;
				n--;
			}
			n = --k;
		}
		buf = buf->next;
	}
}
