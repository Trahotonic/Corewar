/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkyslyy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 15:48:04 by rkyslyy           #+#    #+#             */
/*   Updated: 2018/08/29 15:48:06 by rkyslyy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/corewar.h"

int			main(int argc, char **argv)
{
	t_viz_data		viz_data;
	t_proc_pack		*pp;

	init_all(&pp, argc, argv, &viz_data);
	while (1)
	{
		shmatok666(pp, &viz_data);
		if (!pp->processes)
		{
			end_game(pp, &viz_data);
			break ;
		}
		if (pp->flags->di && pp->i == pp->flags->d)
			break ;
		if (pp->cycle_to_die <= 0)
		{
			kusok(pp, &viz_data);
			break ;
		}
		if (pp->flags->v && pp->i >= pp->flags->vi)
			if (break_vis(pp, &viz_data))
				break ;
		iterate(pp, &viz_data);
	}
	return (end_main(pp));
}
