#include <stdio.h>
#include "../libft/libft.h"
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

static char		*ft_uitoa_base2(unsigned long long value, int base)
{
	char	*array;
	char	tmp[60];
	char	*ret;
	int		size;
	int		ptr;

	if (value == 0)
		return (ft_go_zero());
	array = "0123456789abcdef";
	size = 0;
	ptr = 59;
	while (value != 0)
	{
		tmp[ptr--] = array[value % base];
		value /= base;
		size++;
	}
	ptr++;
	ret = (char*)malloc(sizeof(char) * (size + 1));
	size = 0;
	while (ptr <= 59)
		ret[size++] = tmp[ptr++];
	ret[size] = '\0';
	return (ret);
}

void	convert(char **str)
{
	char	*new;
	char 	*work;
	int		n;
	int 	m;

	new = ft_strnew(8);
	work = *str;
	n = 0;
	m = 0;
	while (n < 8 - (int)ft_strlen(work))
		new[n++] = '0';
	while (n < 8)
		new[n++] = work[m++];
	free(*str);
	*str = new;
}


int main(int argc, char **argv)
{
	header_t struc;
	if (argc != 2)
		return 1;
	unsigned int	buff;
	unsigned char	map[4096];
	int n = 0;
	while (n < 4096)
		map[n++] = 0;
	int fd = open(argv[1], O_RDONLY);
	read(fd, &struc, sizeof(header_t));
	n = 1;
	while (1)
	{
		n = read(fd, &buff, sizeof(int));
		printf("%d\n", n);
		if (!n)
			break ;
//		printf("%x\n", buff);
		buff = ((buff & 0x000000FF) << 24) |
			   ((buff & 0x0000FF00) <<  8) |
			   ((buff & 0x00FF0000) >>  8) |
			   ((buff & 0xFF000000) >> 24);
		char *str = ft_uitoa_base2(buff, 16);
		convert(&str);
		printf("%s\n",str);
	}
//	int wr = open("buffer.cor", O_WRONLY | O_CREAT, 0755);
//	write(fd, "x\n", 2);
//	ft_printf("%s\n", struc.comment);
//	ft_printf("%s\n", struc.prog_name);
//	ft_printf("%d\n", struc.magic);
//	ft_printf("%d\n", struc.prog_size);
//	while (read(fd, &line, 1024))
//		ft_printf("%s\n", line);
	close(fd);
//	close(wr);
	return 0;
}