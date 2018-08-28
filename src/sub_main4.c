//
// Created by Roman KYSLYY on 8/28/18.
//

#include "../inc/corewar.h"

void  ft_check_flag_n(t_player **players, char **argv, int *n)
{
	int i;
	t_player *tmp;

	tmp = *players;
	i = 0;
	(*n)++;
	if(argv[*n])
	{
		if(*argv[*n] == '-')
			++i;
		while(argv[*n][i])
		{
			if(!ft_isdigit(argv[*n][i]))
				exit(printf("Player number should be from -4 to -1 \n"));
			++i;
		}
		if (!argv[*n + 1] || (ft_atoi(argv[*n]) > -1 || ft_atoi(argv[*n]) < -4))
			exit(printf("Player number should be from -4 to -1 \n"));
		ft_flag_n_sup(tmp, players, argv, *n);
		(*n)++;
	}
	else
		exit(printf("Player number should be from -4 to -1 \n"));
}

void  ft_check_flags(t_player **players, char **argv, int *n, t_arg_flags *flags)
{
	if (ft_strequ(argv[*n], "-d"))
		ft_check_flag_d(players, argv, n, flags);
	else if (ft_strequ(argv[*n], "-vi"))
		ft_check_flag_vi(players, argv, n, flags);
	else if (ft_strequ(argv[*n], "-v"))
		flags->v = 1;
	else if (ft_strequ(argv[*n], "-n"))
		ft_check_flag_n(players, argv, n);
	else
		ft_printf("ERROR\n");

}

void ft_usage()
{

}

char *ft_strstr2(const char *big, const char *little)
{
	size_t lrunner;
	size_t brunner;

	brunner = 0;
	if (little[0] == '\0')
		return ((char*)&big[0]);
	while (big[brunner] != '\0')
	{
		if (big[brunner] == little[0])
		{
			lrunner = 0;
			while (little[lrunner] == big[brunner])
			{
				if (little[lrunner] == '\0')
					return ((char*)&big[brunner - lrunner]);
				lrunner++;
				brunner++;
			}
			brunner -= lrunner;
		}
		brunner++;
	}
	return (NULL);
}

void checkArguments(int argc, char **argv, t_arg_flags **flags, t_player **players)
{
	int n;

	n = 1;
	if (argc == 1)
		ft_usage();
	while (n < argc)
	{
		if (ft_strstr2(argv[n], ".cor"))
		{
			ft_get_champ(players, argv, &n);
		}
		else if (*argv[n] == '-')
			ft_check_flags(players, argv, &n, *flags);
		else
			printf("ERROR\n");
		n++;
	}
	if (!*players)
		printf("ERROR\n");
}
