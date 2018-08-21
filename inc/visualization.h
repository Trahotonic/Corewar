//
// Created by Roman Kyslyy on 8/18/18.
//

#ifndef COREWAR_VISUALIZATION_H
#define COREWAR_VISUALIZATION_H


# include <ncurses.h>

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
# define GOOD_YELLOW 19
# define GOOD_BLUE 20
# define DARK_YELLOW 21
# define DARK_BLUE 22
# define LIGHT_YELLOW 23
# define LIGHT_BLUE 24

typedef struct	s_visIter
{
	int 		n;
	int	 		m;
	int 		q;
	int 		i;
	int 		pair;
}				t_visIter;

void	initColors(void);
void	initPairs(void);


#endif //COREWAR_VISUALIZATION_H
