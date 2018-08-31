/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:19:49 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 15:19:58 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		get_players(t_player *players)
{
	int	n;

	n = 0;
	while (players)
	{
		players = players->next;
		++n;
	}
	return (n);
}

int		get_processes(t_process *proc)
{
	int n;

	n = 0;
	while (proc)
	{
		++n;
		proc = proc->next;
	}
	return (n);
}

void	print_end(t_char *print)
{
	t_char	*ptr;

	ptr = print;
	while (ptr)
	{
		ft_printf("%c", ptr->c);
		ptr = ptr->next;
	}
}

void	usage(void)
{
	ft_printf("Usage: ./vm_champs/corewar [-d N -n N -vi N ] [-a] "
					"<champion1.cor> <...>\n"
					"    -a        : Prints output from \"aff\" "
					"(Default is to hide it)\n"
					"    -n  N     : Enter player number from -4 to -1\n"
					"    -d  N     : Dumps memory after N cycles then exits\n"
					"    -vi N     : Ncurses output mode starts from N "
					"iteration\n"
					"    -v        : Ncurses output mode\n");
	exit(1);
}
