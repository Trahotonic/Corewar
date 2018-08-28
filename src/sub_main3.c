//
// Created by Roman KYSLYY on 8/28/18.
//

#include "../inc/corewar.h"

t_player *ft_player_create(char *champ, int num)
{
	t_player *tmp;

	tmp = (t_player*)malloc(sizeof(t_player));
	tmp->num = num;
	tmp->fd = open(champ, O_RDONLY);
	if (tmp->fd == -1)
		exit(printf("ERROR\n"));
	tmp->next = NULL;
	tmp->lastAlive = 0;
	tmp->liveCount = 0;
	tmp->playerNumber = 0;

	return (tmp);
}

void ft_get_champ(t_player **players, char **argv, int *n)
{
	int i;

	i = 1;
	t_player *tmp;
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

void  ft_check_flag_d(t_player **players, char **argv, int *n, t_arg_flags *flags)
{
	int i;

	i = 0;
	(*n)++;
	if(argv[*n])
	{
		while(argv[*n][i])
		{
			if(!ft_isdigit(argv[*n][i]))
			{
				printf("ERROR\n");
				exit(1);
			}
			++i;
		}
		flags->d = ft_atoi(argv[*n]);
	}
	else
	{
		printf("ERROR\n");
		exit(1);
	}
}

void  ft_check_flag_vi(t_player **players, char **argv, int *n, t_arg_flags *flags)
{
	int i;

	i = 0;
	(*n)++;
	if(argv[*n])
	{
		while(argv[*n][i])
		{
			if(!ft_isdigit(argv[*n][i]))
			{
				printf("ERROR\n");
				exit(1);
			}
			++i;
		}
		flags->vi = ft_atoi(argv[*n]);
	}
	else
	{
		printf("ERROR\n");
		exit(1);
	}
}
void ft_flag_n_sup(t_player *tmp, t_player **players, char **argv, int n)
{
	int i;

	i = 1;
	if (!(tmp))
	{
		(*players) = ft_player_create(argv[n + 1], i);
		(*players)->playerNumber = ft_atoi(argv[n]);
	}
	else
	{
		i++;
		while ((tmp)->next)
		{
			if (tmp->playerNumber == ft_atoi(argv[n]))
				exit(printf("Error same number in players\n"));
			tmp = (tmp)->next;
			i++;
		}
		if (tmp->playerNumber == ft_atoi(argv[n]))
			exit(printf("Error same number in players\n"));
		(tmp)->next = ft_player_create(argv[n + 1], i);
		(tmp)->next->playerNumber = ft_atoi(argv[n]);
	}
}
