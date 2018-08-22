//
// Created by Roman Kyslyy on 8/18/18.
//

#ifndef COREWAR_VISUALIZATION_H
#define COREWAR_VISUALIZATION_H


#include <ncurses.h>
#include "corewar.h"

# define DEFAULT_COLOR_PAIR 1
# define MARK_PROCESS1_PAIR 2
# define DEFAULT_PLAYER1_PAIR 3
# define DEFAULT_PLAYER2_PAIR 4
# define DEFAULT_PLAYER3_PAIR 5
# define DEFAULT_PLAYER4_PAIR 6
# define NEW_PLAYER1_CODE_PAIR 7
# define NEW_PLAYER2_CODE_PAIR 8
# define NEW_PLAYER3_CODE_PAIR 9
# define NEW_PLAYER4_CODE_PAIR 10
# define SEEK_BITCH 11
# define SEEK_YELLOW_BITCH 12
# define MARK_PROCESS2_PAIR 13
# define MARK_PROCESS3_PAIR 14
# define MARK_PROCESS4_PAIR 15
# define BORDER 16
# define WHITE_CUNT 17

# define LIGHT_GREEN 10
# define GREY 12
# define DARK_GREEN 13
# define GOOD_GREEN 14
# define RED_FALCON 15
# define LIGHT_RED 16
# define PISS 17
# define GOOD_RED 18
# define GOOD_CYAN 19
# define GOOD_BLUE 20
# define DARK_CYAN 21
# define DARK_BLUE 22
# define LIGHT_CYAN 23
# define LIGHT_BLUE 24
# define VERY_WHITE 25

typedef struct	s_player t_player;

typedef struct	s_vis_iter
{
	int 		n;
	int	 		m;
	int 		q;
	int 		i;
	int 		pair;
}				t_vis_iter;

void	init_colors(void);
void	init_pairs(void);
void	print_border(void);
void    init_vis(void);
int		mark_core(unsigned char x[], int i, unsigned char map[],
					unsigned char m_p[]);
void	mark_processes(t_vis_iter iters, unsigned char map[], unsigned char m_p[]);
void	pick_player_pair(int idx, unsigned char mark_timeout[],
					   int *pair, int val);
void	print_names(t_player *players);
void	erase_nums(int count);


#endif //COREWAR_VISUALIZATION_H
