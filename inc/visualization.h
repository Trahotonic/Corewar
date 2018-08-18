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

# define LIGHT_GREEN 1
# define GREY 2
# define DARK_GREEN 3
# define GOOD_GREEN 4
# define RED_FALCON 5
# define LIGHT_RED 6
# define PISS 7
# define GOOD_RED 8
# define GOOD_YELLOW 9
# define GOOD_BLUE 10
# define DARK_YELLOW 11
# define DARK_BLUE 12
# define LIGHT_YELLOW 13
# define LIGHT_BLUE 14

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
