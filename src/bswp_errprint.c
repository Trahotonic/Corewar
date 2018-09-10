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

void			error_printer(t_player *ptr, char *total)
{
	if (ptr->h.prog_size != ft_strlen(total) / 2)
		exit(ft_printf("Error: \"%s's\" size doesn't match provided size"
							   " in header\n", ptr->h.prog_name));
	if (ptr->h.magic != 0xea83f3) {
		exit(ft_printf("Error: \"%s\" has an invalid"
								"header\n", ptr->h.prog_name));
	}
	if (ptr->h.prog_size > 682) {
		exit(ft_printf("Error: \"%s\" has too large code"
				"(%d bytes > 682 bytes)\n", ptr->h.prog_name,
					ptr->h.prog_size));
	}
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
		if (buf->player_number == 0)
		{
			while (n >= -4)
			{
				while (bu && bu->player_number != n && buf->player_number == 0)
					bu = bu->next;
				!bu ? buf->player_number = n : 0;
				bu = player;
				n--;
			}
			n = --k;
		}
		buf = buf->next;
	}
}
