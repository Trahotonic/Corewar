/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msemenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:46:34 by msemenov          #+#    #+#             */
/*   Updated: 2018/08/30 16:46:42 by msemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

t_player	*ft_player_create(char *champ, int num)
{
	t_player	*tmp;

	if (ft_strstr2(champ, ".cor"))
	{
		tmp = (t_player *)malloc(sizeof(t_player));
		tmp->num = num;
		tmp->fd = open(champ, O_RDONLY);
		if (tmp->fd == -1)
			exit(printf("Invalid champion provided\n"));
		tmp->next = NULL;
		tmp->last_alive = 0;
		tmp->live_count = 0;
		tmp->live_count_p = 0;
		tmp->player_number = 0;
	}
	else
		exit(ft_printf("Invalid champion\n"));
	return (tmp);
}

void		ft_get_champ(t_player **players, char **argv, int *n)
{
	int			i;
	t_player	*tmp;

	i = 1;
	tmp = *players;
	if (!tmp)
		(*players) = ft_player_create(argv[*n], i);
	else
	{
		++i;
		while (tmp->next)
		{
			(tmp) = (tmp)->next;
			++i;
		}
		tmp->next = ft_player_create(argv[*n], i);
	}
}

void		ft_check_flag_d(char **argv, int *n, t_arg_flags *flags)
{
	int i;

	i = 0;
	(*n)++;
	if (argv[*n])
	{
		while (argv[*n][i])
		{
			if (!ft_isdigit(argv[*n][i]))
				exit(printf("invalid arguments\n"));
			++i;
		}
		flags->d = ft_atoi(argv[*n]);
		flags->di = true;
	}
	else
		exit(printf("invalid arguments\n"));
}

void		ft_check_flag_vi(char **argv, int *n, t_arg_flags *flags)
{
	int i;

	i = 0;
	(*n)++;
	if (argv[*n])
	{
		while (argv[*n][i])
		{
			if (!ft_isdigit(argv[*n][i]))
				exit(printf("invalid iteration\n"));
			++i;
		}
		flags->vi = ft_atoi(argv[*n]);
		flags->v = 1;
	}
	else
		exit(printf("invalid arguments\n"));
}

void		ft_flag_n_sup(t_player *tmp, t_player **players, char **argv, int n)
{
	int i;

	i = 1;
	if (!(tmp))
	{
		(*players) = ft_player_create(argv[n + 1], i);
		(*players)->player_number = ft_atoi(argv[n]);
	}
	else
	{
		i++;
		while ((tmp)->next)
		{
			if (tmp->player_number == ft_atoi(argv[n]))
				exit(printf("Error same number in players\n"));
			tmp = (tmp)->next;
			i++;
		}
		if (tmp->player_number == ft_atoi(argv[n]))
			exit(printf("Error same number in players\n"));
		(tmp)->next = ft_player_create(argv[n + 1], i);
		(tmp)->next->player_number = ft_atoi(argv[n]);
	}
}
