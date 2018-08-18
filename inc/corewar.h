//
// Created by Roman Kyslyy on 7/7/18.
//

#ifndef COREWAR_COREWAR_H
#define COREWAR_COREWAR_H


#include <stdio.h>
#include "../libft/libft.h"
#include "visualization.h"

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		header_s
{
    unsigned int		magic;
    char				prog_name[PROG_NAME_LENGTH + 1];
    unsigned int		prog_size;
    char				comment[COMMENT_LENGTH + 1];
}					header_t;

typedef struct  	s_process
{
	int 				proc_num;
	int    				cur_pos;
	int 				codage;
	int    				carry;
	int    				pl_num;
	int 				pl_number;
	unsigned int		reg[REG_NUMBER];
	int    				alive;
	char   				command[3];
	int    				cycle_todo;
	int    				iterator;
	char 				arg1[9];
	char 				arg2[9];
	char 				arg3[9];
	int 				t_dir;
	int 				iC;
	int					invalidAgr;
	struct s_process	*next;
	struct s_process	*prev;

}     				t_process;

typedef struct  s_argFlags
{
	long long  d;
	int    v;
	long long  vi;
}     t_argFlags;

typedef struct  s_player
{
	int    playerNumber;
	int    lastAlive;
	int    liveCount;
	header_t  header;
	size_t    len;
	struct s_player *next;
	int    num;
	int    fd;
	int 	start;
}     t_player;


typedef struct  s_vizData
{
    unsigned char   vizData[MEM_SIZE * 2];
	unsigned char   markTimeout[MEM_SIZE * 2];
}               t_vizData;

typedef struct  functions_s
{
	char   *name;
	int    codage;
	int    cycles;
	void  (*funcptr)(t_process*, unsigned char*, int, t_player*, t_vizData*);
}     functions_t;

void	doNull(t_process *processor);
void    initMap(unsigned char map[], t_vizData *vizData, t_player *players);
void	initProcesses(t_process **processes, t_player *players);
int 	ft_iswhitespace(char const c);
int 	base(int c, int base);
int 	ft_atoi_base(const char *str, int str_base);
int 	ft_bto_i(char *bin);
void	readShit(unsigned char map[], t_process *processor);
char 	*ft_convert_2(int tmp, int base);
char	*ft_arrg_join(char *s1, char *s2);
char	*ft_uitoa_base2(unsigned int value, int base);
void	convert(char **str);
void    getTotal(t_player *players, char **total, t_vizData *vizData, int n);
void    initVis(void);
void    visualize(unsigned char map[], size_t len, t_process *proc, t_vizData *vizData);
void  	live(t_process *processor, unsigned char *map, int i, t_player *pl, t_vizData *vizData);
void  	ld(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	st(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	add(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	sub(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	and(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	or(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	xor(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	zjmp(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	ldi(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	lld(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	lldi(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	fork_c(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	lfork(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	sti(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void	aff(t_process *processor, unsigned char *map, int iz, t_player *pl, t_vizData *vizData);
void 	initfunc(functions_t func[]);

#endif //COREWAR_COREWAR_H
